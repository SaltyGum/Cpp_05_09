#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    
    if(argc != 2){
        std::cout << "Something is wrong with input " << std::endl;
        return 1;
    }

    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch (...)
    {
        std::cerr << "Something is wrong with input or no possible convertions " << std::endl;
    }
}