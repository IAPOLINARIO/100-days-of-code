/**
 * DAY-81 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include <regex>

/**
 * Draw the “G” Logo
 * 
 * @param n Size of output image as NxN pixels
 * @param outputFileName Ouput image file
 * @return true if OK
 */ 
bool buildGoogleLogo(const int n, const std::string outputFileName) {
    if (n <= 0 || outputFileName.empty()) {
        return false; //invalid parameter(s)
    }
    const double VIEWBOX_HEIGHT_RATIO = 1.020243674; //IMPORTANT: the Google Logo height is about 1% greater than its width (based on official image)
    const std::string HEADER = "<svg viewBox=\"0 0 " + std::to_string(n) + " " + std::to_string(n * VIEWBOX_HEIGHT_RATIO) + "\" xmlns=\"http://www.w3.org/2000/svg\">"; //header of output file (appropriately scaled)
    const std::string FOOTER = "</svg>"; //footer of output file
    const std::array<std::string, 4> FILL_COLORS = {"#4285f4", "#34a853", "#fbbc04", "#ea4335"}; //the official Google Logo colors!
    
    //reference paths to be used to build the logo in an appropriately scaled output file
    std::array<std::string, 4> REF_PATHS = {"M533.5 278.4c0-18.5-1.5-37.1-4.7-55.3H272.1v104.8h147c-6.1 33.8-25.7 63.7-54.4 82.7v68h87.7c51.5-47.4 81.1-117.4 81.1-200.2z",
                                            "M272.1 544.3c73.4 0 135.3-24.1 180.4-65.7l-87.7-68c-24.4 16.6-55.9 26-92.6 26-71 0-131.2-47.9-152.8-112.3H28.9v70.1c46.2 91.9 140.3 149.9 243.2 149.9z",
                                            "M119.3 324.3c-11.4-33.8-11.4-70.4 0-104.2V150H28.9c-38.6 76.9-38.6 167.5 0 244.4l90.4-70.1z",
                                            "M272.1 107.7c38.8-.6 76.3 14 104.4 40.8l77.7-77.7C405 24.6 339.7-.8 272.1 0 169.2 0 75.1 58 28.9 150l90.4 70.1c21.5-64.5 81.8-112.4 152.8-112.4z"};

    //lambda to scale a path
    const auto scaledPath = [&](std::string &p, double &ratio) {
        std::string newPath;
        std::string nStr;            
        for (int i = 0; i < p.size(); i++) {            
            if (!isdigit(p[i]) && p[i] != '.') { //is current char not part of a number?
                if (!nStr.empty()) { //is there a number?
                    const double num = atof(nStr.c_str()); //convert the discovered number do double
                    if (ratio == 0) { //is first time?
                        ratio = n / num; //the same calculated ratio will be applied to the whole output image
                    } 
                    const std::string newNumStr = std::to_string(ratio * atof(nStr.c_str()));
                    const std::string o = std::regex_replace(p, std::regex("(" + nStr + ")"), newNumStr, std::regex_constants::format_first_only);
                    const int s = o.find(newNumStr) + newNumStr.size();
                    p = o.substr(s); //consider only the part not updated yet
                    newPath += o.substr(0, s); //save the updated part of path
                    nStr = ""; //reset number for next discovery
                    i = -1; //start again              
                }          
            } else {
                nStr += p[i]; //build the number
            }        
        }
        return newPath; //return the fully updated path
    };
        
    //build the output file        
    std::ofstream out(outputFileName); 
    if (!out) {
        return false; //error creating output image file!
    }
    out << HEADER;
    double ratio = 0;
    for (int i = 0; i < REF_PATHS.size(); i++) {
        out << "<path d=\"" << scaledPath(REF_PATHS[i], ratio) << "\" fill=\"" << FILL_COLORS[i] << "\"/>";
    }
    out << FOOTER;

    return true;
}

/**
 * Helper test method.
 * @param n Size of output image as NxN pixels
 * @param outputFileName Ouput image file
 * @param expectedOutputContent Expected content of output image file
 */ 
void testGoogleLogo(const int n, const std::string outputFileName, const std::string expectedOutputContent) {
    CHECK(buildGoogleLogo(n, outputFileName) == true);
    
    std::ifstream file(outputFileName, std::ifstream::in); //file open for reading
    CHECK(file); //is file ok?
    std::string content;
    std::getline(file, content); //get the file line content 
    
    CHECK(content == expectedOutputContent); //check content of file
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    testGoogleLogo(25, "bin/google_logo_25.svg", "<svg viewBox=\"0 0 25 25.506092\" xmlns=\"http://www.w3.org/2000/svg\"><path d=\"M25.000000 13.045923c0.000000-0.866917-0.070291-1.738519-0.220244-2.591378H12.750703v4.910965h6.888472c-0.285848 1.583880-1.204311 2.985005-2.549203 3.875351v3.186504h4.109653c2.413308-2.221181 3.800375-5.501406 3.800375-9.381443\" fill=\"#4285f4\"/><path d=\"M12.750703 25.506092c3.439550 0.000000 6.340206-1.129335 8.453608-3.078725l-4.109653-3.186504c-1.143393 0.777882-2.619494 1.218369-4.339269 1.218369-3.327085 0.000000-6.148079-2.244611-7.160262-5.262418H1.354264v3.284911c2.164948 4.306467 6.574508 7.024367 11.396439 7.024367\" fill=\"#34a853\"/><path d=\"M5.590440 15.196813c-0.534208-1.583880-0.534208-3.298969 0.000000-4.882849V7.029053H1.354264c-1.808810 3.603561-1.808810 7.849110 0.000000 11.452671l4.236176-3.284911\" fill=\"#fbbc04\"/><path d=\"M12.750703 5.046860c1.818182-0.028116 3.575445 0.656045 4.892221 1.911903l3.641050-3.641050C18.978444 1.152765 15.918463-0.037488 12.750703 0.000000 7.928772 0.000000 3.519213 2.717901 1.354264 7.029053l4.236176 3.284911c1.007498-3.022493 3.833177-5.267104 7.160262-5.267104\" fill=\"#ea4335\"/></svg>");
    testGoogleLogo(700, "bin/google_logo_700.svg", "<svg viewBox=\"0 0 700 714.170572\" xmlns=\"http://www.w3.org/2000/svg\"><path d=\"M700.000000 365.285848c0.000000-24.273664-1.968135-48.678538-6.166823-72.558575H357.019681v137.507029h192.877226c-8.003749 44.348641-33.720712 83.580131-71.377694 108.509841v89.222118h115.070291c67.572634-62.193065 106.410497-154.039363 106.410497-262.680412\" fill=\"#4285f4\"/><path d=\"M357.019681 714.170572c96.307404 0.000000 177.525773-31.621368 236.701031-86.204311l-115.070291-89.222118c-32.014995 21.780694-73.345829 34.114339-121.499531 34.114339-93.158388 0.000000-172.146204-62.849110-200.487348-147.347704H37.919400v91.977507c60.618557 120.581068 184.086223 196.682287 319.100281 196.682287\" fill=\"#34a853\"/><path d=\"M156.532334 425.510778c-14.957826-44.348641-14.957826-92.371134 0.000000-136.719775V196.813496H37.919400c-50.646673 100.899719-50.646673 219.775070 0.000000 320.674789l118.612933-91.977507\" fill=\"#fbbc04\"/><path d=\"M357.019681 141.312090c50.909091-0.787254 100.112465 18.369260 136.982193 53.533271l101.949391-101.949391C531.396439 32.277413 445.716963-1.049672 357.019681 0.000000 222.005623 0.000000 98.537957 76.101218 37.919400 196.813496l118.612933 91.977507c28.209934-84.629803 107.328960-147.478913 200.487348-147.478913\" fill=\"#ea4335\"/></svg>");
}