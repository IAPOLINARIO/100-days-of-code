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
        if (repetitions > 0) {
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
    
    //Read the rest of the file until EOF. 
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
    for (int i = 0; i < totalSize; i++) {
        if (rMap.find(i) != rMap.end()) {            
            for (int j = 0; j <= rMap[i].second; j++) {                
                targetFile.write((char *) &rMap[i].first, sizeof(rMap[i].first)); //write the repeating bytes 'n' times
            }
            i += rMap[i].second;
        } else {                        
            targetFile.write((char *) &raw[0], sizeof(raw[0])); //write the normal raw sequence of bytes (not repeated)
        }
        raw.erase(raw.begin()); //remove first byte from raw vector
    }

    return 0;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    //----------------------------------------------------------------------------------------------------
    //5kB file tests
    //----------------------------------------------------------------------------------------------------
    //check successful compress
    CHECK(compress("../../../../assets/5kB_sample_text.txt", "bin/5kB_sample_text.txt.bkp") == 0);    
    //check successful uncompress
    CHECK(uncompress("bin/5kB_sample_text.txt.bkp", "bin/5kB_sample_text_RECOVERED.txt") == 0);
    //check if compressed file is smaller than original file
    CHECK(fileSize("../../../../assets/5kB_sample_text.txt") > fileSize("bin/5kB_sample_text.txt.bkp"));
    //check if the recovered file is equal to the original
    CHECK(fileSize("../../../../assets/5kB_sample_text.txt") == fileSize("bin/5kB_sample_text_RECOVERED.txt"));

    //show results
    std::cout << "\n\nFILE RESULTS (5kB):\n-------------------" << std::endl;
    std::cout << "../../../../assets/5kB_sample_text.txt (ORIGINAL) => " << fileSize("../../../../assets/5kB_sample_text.txt") << " bytes" << std::endl;
    std::cout << "bin/5kB_sample_text.txt.bkp (COMPRESSED) => " << fileSize("bin/5kB_sample_text.txt.bkp") << " bytes" << std::endl;
    std::cout << "bin/5kB_sample_text_RECOVERED.txt (RECOVERED) => " << fileSize("bin/5kB_sample_text_RECOVERED.txt") << " bytes" << std::endl;


    //----------------------------------------------------------------------------------------------------
    //10MB file tests
    //----------------------------------------------------------------------------------------------------
    //check successful compress
    CHECK(compress("../../../../assets/10MB_sample_text.txt", "bin/10MB_sample_text.txt.bkp") == 0);
    //check successful uncompress
    CHECK(uncompress("bin/10MB_sample_text.txt.bkp", "bin/10MB_sample_text_RECOVERED.txt") == 0);
    //check if compressed file is smaller than original file
    CHECK(fileSize("../../../../assets/10MB_sample_text.txt") > fileSize("bin/10MB_sample_text_RECOVERED.txt.bkp"));
    //check if the recovered file is equal to the original
    CHECK(fileSize("../../../../assets/10MB_sample_text.txt") == fileSize("bin/10MB_sample_text_RECOVERED.txt"));

    //show results
    std::cout << "\n\nFILE RESULTS (10MB):\n--------------------" << std::endl;
    std::cout << "../../../../assets/10MB_sample_text.txt (ORIGINAL) => " << fileSize("../../../../assets/10MB_sample_text.txt") << " bytes" << std::endl;
    std::cout << "bin/10MB_sample_text.txt.bkp (COMPRESSED) => " << fileSize("bin/10MB_sample_text.txt.bkp") << " bytes" << std::endl;
    std::cout << "bin/10MB_sample_text_RECOVERED.txt (RECOVERED) => " << fileSize("bin/10MB_sample_text_RECOVERED.txt") << " bytes\n\n" << std::endl;


    
}