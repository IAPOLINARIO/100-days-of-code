#include <iostream>

const int NUMBER_OF_ARGS = 2;
const int DAYS_OF_YEAR = 365;

int main(int argc, char *argv[])
{
    //check number of args
    if (argc != NUMBER_OF_ARGS) {
        std::cerr << "Please enter age in years\n";
        return -1;
    }

    //check if the input is an integer
    char *end;
    int years = strtol(argv[1], &end, 10);
    if (*end) {
        std::cerr << "Invalid arguments\n";
        return -1;
    }

    //output age in days
    std::cout << "Age in days -> " << years * DAYS_OF_YEAR << std::endl;

    return 0;
}
