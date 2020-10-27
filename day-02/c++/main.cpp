#include <iostream>

int main(int argc, char *argv[])
{       
    bool found;    
    for (int i = 1; i < argc; i++) {        
        found = std::string(argv[i]).compare("Nemo") == 0;
        if (found) {
            std::cout << "I found Nemo at " << i << "!" << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << " I can't find Nemo :(" << std::endl;
    }

    return 0;
}