#ifndef SCALARCONVERTER_CLASS
#define SCALARCONVERTER_CLASS

#include <iostream>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <sstream>

class ScalarConverter {
public:
    // Constructors / Destructors
    ScalarConverter();
    ScalarConverter(std::string literal);
    ScalarConverter(ScalarConverter const &cp);
    ~ScalarConverter();

    // Operators
    ScalarConverter& operator=(ScalarConverter const &cp);

//Methods
    //Checkers
    static bool special(std::string literal);
    static bool literalChar(std::string str);
    static bool literalInt(std::string str);
    static bool literalFloat(std::string str);
    static bool literalDouble(std::string str);
    //Converters
    static void convert(std::string literal);
    static void toChar(std::string str);
    static void toInt(std::string str);
    static void toFloat(std::string str);
    static void toDouble(std::string str);
    //Printers
    static void putSpecial(std::string str);
    static void putChar(std::string str);
private:
    std::string literal;
};

#endif