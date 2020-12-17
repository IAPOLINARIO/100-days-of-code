/**
 * DAY-47 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 * 
 * ATTENTION:
 * It needs at least a C++17 compiler because of the usage of std::byte
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <cstddef> //for std::byte
#include <map>

/**
 * Get the file size given an opened file.
 * @param file The opened file
 * @return file size or -1 if error
 */ 
std::streampos fileSize(std::ifstream &file) {        
    //go to the end of file to get its size
    file.seekg(0, std::ios::end);
    std::streampos length = file.tellg(); 
    //get back to the beginning of file
    file.seekg(0, std::ios::beg);
    return length;
}

/**
 * Open file (binary mode).
 * @param filename The filename
 * @return The file
 */ 
std::ifstream openBinaryFile(std::string filename) {
    std::ifstream file(filename, std::ios::in | std::ios::binary);  
    return file;
}

/**
 * Get the file size given an filename.
 * @param fileName The file name
 * @return file size or -1 if error
 */ 
std::streampos fileSize(std::string fileName) {       
    //try to open the source (uncompressed file)
    std::ifstream file = openBinaryFile(fileName);
    if (!file) {
        return -1;
    }
    return fileSize(file);
}

/**
 * Compress a file.
 * @param sourceFileName Source filename
 * @param targetFileName Target (compressed) filename
 * return 0 if OK
 */ 
int compress(std::string sourceFileName, std::string targetFileName) {
    const int REPETITION_LEVEL = 5; //repetition level to be worth it, can be tweaked

    //try to open the source (uncompressed file)
    std::ifstream file = openBinaryFile(sourceFileName);
    if (!file) {
        return -1;
    }
        
    //get file size
    std::streampos length = fileSize(file);     

    //read the whole file to an vector of std::byte
    std::vector<std::byte> bytes(length);
    file.read((char *) bytes.data(), length);
    
    //store the bytes of the file into the bytes vector, except repetitions, which are stored in a std::map structure
    std::map<int, std::pair<std::byte, int>> repeatMap; //to hold repetitions: index of the raw vector, the byte and number of repetitions
    std::vector<std::byte> raw;
    for (int i = 0; i < bytes.size(); i++) {
        int count = 0;           
        for (count = i + 1; count < bytes.size(); count++) {
            if (bytes[i] != bytes[count]) {
                break;
            }
        }
        int repetitions = count - i - 1;
        if (repetitions > REPETITION_LEVEL) {
            repeatMap[i] = std::make_pair(bytes[i], repetitions); //store a repeated sequence into this map
            i += repetitions - 1;
        } else {
            raw.push_back(bytes[i]); //store not repeated sequences of bytes
        }
    }

    //write the compressed file, binary output
    std::ofstream targetFile(targetFileName, std::ios::out | std::ios::binary);
    int sizeOfRaw = raw.size() * sizeof(raw[0]); //first information, size of raw bytes (which are not repeated)
    targetFile.write((char *) &sizeOfRaw, sizeof(sizeOfRaw)); //size of raw
    targetFile.write((char *) &raw[0], sizeOfRaw); //raw bytes (not repeated)

    //write the repeated bytes
    for (auto &r : repeatMap) { //read std::map struct of bytes repeated
        targetFile.write((char *) &r.first, sizeof(r.first)); //index
        targetFile.write((char *) &r.second.first, sizeof(r.second.first)); //byte
        targetFile.write((char *) &r.second.second, sizeof(r.second.second)); //repetitions        
    }

    return 0;
}

/**
 * Uncompress a file.
 * @param sourceFileName Source (compressed) filename
 * @param targetFileName Target (uncompressed) filename
 * return 0 if OK
 */  
int uncompress(std::string sourceFileName, std::string targetFileName) {
    //try to open the source (uncompressed file)
    std::ifstream file = openBinaryFile(sourceFileName);
    if (!file) {
        return -1;
    }

    //get the size of raw bytes (not repeated)
    int sizeOfRaw;
    file.read((char *) &sizeOfRaw, sizeof(sizeOfRaw));
    //transfer the raw bytes (not repeated) into the raw vector
    std::vector<std::byte> raw(sizeOfRaw);
    file.read((char *) &raw[0], sizeof(std::byte) * sizeOfRaw);

    std::map<int, std::pair<std::byte, int>> rMap; //struct to hold repeating bytes

    int index;
    std::byte byte;
    int repetitions;
    int sizeOfRepetitions = 0;
    
    //Read the rest of the file until EOF
    //Starting from now, the compressed file holds information of repeating bytes    
    while (file.read((char *) &index, sizeof(index))) { //index in the original file?
        file.read((char *) &byte, sizeof(byte)); //which byte?
        file.read((char *) &repetitions, sizeof(repetitions)); //number of repetitions of the byte
        
        rMap[index] = std::make_pair(byte, repetitions);//recreate map with repeating structure
        sizeOfRepetitions += sizeof(byte) * repetitions; //sum all the repeated bytes
    }

    int totalSize = sizeOfRaw + sizeOfRepetitions; //target uncompressed file size: raw bytes (not repeated) + repeated bytes

    //write de ucompressed target file, it will have totalSize bytes
    std::ofstream targetFile(targetFileName, std::ios::out | std::ios::binary);
    int bytesWritten = 0;
    for (auto &rm : rMap) {
        int sizeToWriteUntilRepeatedBytes = rm.first - bytesWritten;
        if (sizeToWriteUntilRepeatedBytes >= 0) {            
            targetFile.write((char *) &raw[0], sizeof(raw[0]) * sizeToWriteUntilRepeatedBytes); //write the normal raw sequence of bytes (not repeated)
            raw.erase(raw.begin(), raw.begin() + sizeToWriteUntilRepeatedBytes + 1);//+1 because the raw structure still has the beginning byte that repeats (possible improvement to remove it)
        }
        for (int j = 0; j <= rm.second.second; j++) {                
            targetFile.write((char *) &rm.second.first, sizeof(rm.second.first)); //write the repeating bytes 'n' times            
        }         
        bytesWritten += sizeToWriteUntilRepeatedBytes + rm.second.second * sizeof(rm.second.first) + 1;
    }
    if (raw.size() > 0) {
        targetFile.write((char *) &raw[0], sizeof(raw[0]) * raw.size()); //write the remaining normal raw sequence of bytes (not repeated)
    }

    return 0;
}

/**
 * Helper function to test files
 * @param sourceFilename The filename to compress, uncompress and compare sizes
 */ 
void runChecks(std::string sourceFilename) {
    std::string target = sourceFilename;
    const size_t last_slash_idx = target.find_last_of("\\/");
    if (std::string::npos != last_slash_idx) {
        target.erase(0, last_slash_idx + 1); //get only the name of the file
    }

    //check successful compress
    CHECK(compress(sourceFilename, "bin/" + target + ".bkp") == 0);    
    //check successful uncompress
    CHECK(uncompress("bin/" + target + ".bkp", "bin/RECOVERED_" + target) == 0);
    //check if compressed file is smaller than original file
    CHECK(fileSize(sourceFilename) > fileSize("bin/" + target + ".bkp"));
    //check if the recovered file is equal to the original
    CHECK(fileSize(sourceFilename) == fileSize("bin/RECOVERED_" + target));

    //show results
    std::cout << "\nFILE RESULTS:\n-------------" << std::endl;
    std::cout << sourceFilename << " (ORIGINAL) => " << fileSize(sourceFilename) << " bytes" << std::endl;
    std::cout << "bin/" + target + ".bkp" << " (COMPRESSED) => " << fileSize("bin/" + target + ".bkp") << " bytes" << std::endl;
    std::cout << "bin/RECOVERED_" + target << " (RECOVERED) => " << fileSize("bin/RECOVERED_" + target) << " bytes\n" << std::endl;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{  
    runChecks("../../../../assets/5kB_sample_text.txt");
    runChecks("../../../../assets/10MB_sample_text.txt");    
    runChecks("../../../../assets/MARBLES.BMP");
}