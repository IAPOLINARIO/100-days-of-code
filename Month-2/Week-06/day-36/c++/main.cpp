/**
 * DAY-36 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Convert a integer to a LCD representation.
 * @param n The number
 * @param m Size as number of signs
 * @return LCD display representation as a string
 */ 
std::string toLCD(int n, int m) {
    const int SPACE_BETWEEN_DIGITS = 1;
    const int DIGIT_STRUCTURE_SIZE = 5;
    const int DIGIT_BASE_HEIGHT = 3 + 2 * m;
    const int DIGIT_DEFAULT_WIDTH = 3;
    const std::string ERROR = "INVALID INPUT";

    enum ENUM_DIGIT_CHAR_STRUCTURE {                
        SIMPLE_SPACE = 0,
        REPEATABLE_SPACE = 1,
        REPEATABLE_CHAR = 2,        
    };

    //lambda to destroy objects
    const auto destroy = [&](std::vector<std::tuple<int, int, int>*> &digits, char *canvas) { if (canvas != nullptr) delete canvas; for (auto &d : digits) delete d; };
    //lambda to identify if element of strucure of the digit is even or odd
    const auto isEven = [&](int e) { return (e % 2 == 0); };        
    //lambda to get the char based on digit data
    const auto charOfDigit = [&](int s, int y) { return isEven(y) ? (s == ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR) ? '-' : ' ' : (s == ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR) ? '|' : ' '; };    
    //lambda to get the multiplier based on digit data
    const auto multiplierOfDigit = [&](int s, int y, int m) { return isEven(y) ? (s != ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE) ? m : 1 : (s == ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE) ? m : 1; };    
    //lambda to writing into the canvas
    const auto writer = [&](int s, int x, int yBase, int y, int width, int m, char *canvas) { for (int r = 0; r < m; r++) canvas[y * width + x++] = charOfDigit(s, yBase); return x; };

    //check input for SUPPORTED digits, allocate memory only for digits really needed
    std::vector<std::tuple<int, int, int>*> digits;
    const std::string sn = std::to_string(n);
    for (int i = 0; i < sn.size(); i++) {        
        std::tuple<int, int, int>* d = nullptr;        
        switch (sn[i])
        {
        case '0':
            d = new std::tuple<int, int, int>[DIGIT_STRUCTURE_SIZE]{std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE)};
            break;
        case '1':            
            d = new std::tuple<int, int, int>[DIGIT_STRUCTURE_SIZE]{std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE)};
            break;                                         
        case '2':
            d = new std::tuple<int, int, int>[DIGIT_STRUCTURE_SIZE]{std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE)};
            break;     
        case '3':            
            d = new std::tuple<int, int, int>[DIGIT_STRUCTURE_SIZE]{std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE)};
            break;
        case '4':
            d = new std::tuple<int, int, int>[DIGIT_STRUCTURE_SIZE]{std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE)};
            break;
        case '5':
            d = new std::tuple<int, int, int>[DIGIT_STRUCTURE_SIZE]{std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE)};
            break;
        case '6':
            d = new std::tuple<int, int, int>[DIGIT_STRUCTURE_SIZE]{std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE)};
            break;
        case '7':
            d = new std::tuple<int, int, int>[DIGIT_STRUCTURE_SIZE]{std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE)};
            break;
        case '8':
            d = new std::tuple<int, int, int>[DIGIT_STRUCTURE_SIZE]{std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE)};
            break;
        case '9':
            d = new std::tuple<int, int, int>[DIGIT_STRUCTURE_SIZE]{std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR), std::make_tuple(ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE, ENUM_DIGIT_CHAR_STRUCTURE::REPEATABLE_CHAR, ENUM_DIGIT_CHAR_STRUCTURE::SIMPLE_SPACE)};
            break;                        
        default:        
            destroy(digits, nullptr); //destroy dynamically created digits and canvas, freeing memory
            return ERROR;
        }                
        digits.push_back(d);        
    }

    //allocate memory to build the canvas with the necessary size    
    int width = digits.size() * (DIGIT_DEFAULT_WIDTH + (m - 1)) + digits.size() * SPACE_BETWEEN_DIGITS - SPACE_BETWEEN_DIGITS;
    const int canvasSize = DIGIT_BASE_HEIGHT * width;
    char *canvas = new char[canvasSize]; 
    memset(canvas, ' ', canvasSize);
    
    //write digits to canvas
    int xSpaceOffset = 0;    
    //for (auto &p : digits) {   
    for (int i = 0; i < digits.size(); i++)  {
        int yAux = 0;        
        for (int y = 0; y < DIGIT_STRUCTURE_SIZE; y++) {              
            auto a = std::get<0>(digits[i][y]);
            auto b = std::get<1>(digits[i][y]);
            auto c = std::get<2>(digits[i][y]);
            for (int r = 0; r < (isEven(y) ? 1 : m); r++) {
                int xAux = xSpaceOffset;
                xAux = writer(a, xAux, y, yAux, width, multiplierOfDigit(a, y, m), canvas);
                xAux = writer(b, xAux, y, yAux, width, multiplierOfDigit(b, y, m), canvas);
                writer(c, xAux, y, yAux, width, multiplierOfDigit(c, y, m), canvas);
                yAux++;
            }            
        }        
        xSpaceOffset += DIGIT_DEFAULT_WIDTH + (m - 1) + SPACE_BETWEEN_DIGITS - (sn[i] == '1' ? (m - 1) : sn[i] == '3' ? 1 : 0);
    }    

    //generate output
    std::string output;
    for (int y = 0; y < DIGIT_BASE_HEIGHT; y++) {
        for (int x = 0; x < width; x++) {            
            output += canvas[y * width + x];
        }        
        output += "\n";
    }

    //destroy dynamically created digits and canvas, freeing memory
    destroy(digits, canvas);    

    //return output
    std::cout << output;
    return output;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{                  
    
    //test LCD size 1
    std::string expectedSize1 = 
R"(     -  -       -   -   -   -   -   -  
  |   |  | | | |   |     | | | | | | | 
     -  -   -   -   -       -   -      
  | |    |   |   | | |   | | |   | | | 
     -  -       -   -       -   -   -  )";

    std::string outputSize1 = toLCD(1234567890, 1);
    CHECK(expectedSize1.compare(outputSize1.substr(0, expectedSize1.size())) == 0);
            
    //test LCD size 2
    std::string expectedSize2 =
R"(     --  --        --   --   --   --   --   --   
  |    |   | |  | |    |       | |  | |  | |  |  
  |    |   | |  | |    |       | |  | |  | |  |  
     --  --   --   --   --        --   --        
  | |      |    |    | |  |    | |  |    | |  |  
  | |      |    |    | |  |    | |  |    | |  |  
     --  --        --   --        --   --   --   )";    
    std::string outputSize2 = toLCD(1234567890, 2);
    CHECK(expectedSize2.compare(outputSize2.substr(0, expectedSize2.size())) == 0);

    //test LCD size 3
    std::string expectedSize3 =
R"(     ---  ---         ---   ---   ---   ---   ---   ---    
  |     |    | |   | |     |         | |   | |   | |   |   
  |     |    | |   | |     |         | |   | |   | |   |   
  |     |    | |   | |     |         | |   | |   | |   |   
     ---  ---   ---   ---   ---         ---   ---          
  | |        |     |     | |   |     | |   |     | |   |   
  | |        |     |     | |   |     | |   |     | |   |   
  | |        |     |     | |   |     | |   |     | |   |   
     ---  ---         ---   ---         ---   ---   ---    )";

    std::string outputSize3 = toLCD(1234567890, 3);
    CHECK(expectedSize3.compare(outputSize3.substr(0, expectedSize3.size())) == 0);
    
    //test LCD size 4
    std::string expectedSize4 =
R"(     ----  ----          ----   ----   ----   ----   ----   ----     
  |      |     | |    | |      |           | |    | |    | |    |    
  |      |     | |    | |      |           | |    | |    | |    |    
  |      |     | |    | |      |           | |    | |    | |    |    
  |      |     | |    | |      |           | |    | |    | |    |    
     ----  ----   ----   ----   ----          ----   ----            
  | |          |      |      | |    |      | |    |      | |    |    
  | |          |      |      | |    |      | |    |      | |    |    
  | |          |      |      | |    |      | |    |      | |    |    
  | |          |      |      | |    |      | |    |      | |    |    
     ----  ----          ----   ----          ----   ----   ----     )";
    std::string outputSize4 = toLCD(1234567890, 4);
    CHECK(expectedSize4.compare(outputSize4.substr(0, expectedSize4.size())) == 0);   

    //test invalid input
    CHECK(toLCD(-1, 1) == "INVALID INPUT");
}