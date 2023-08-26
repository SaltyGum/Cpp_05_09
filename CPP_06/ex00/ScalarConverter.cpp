#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : literal("nameless")
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(std::string literal) : literal(literal)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &cp) : literal(cp.literal)
{
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &cp)
{
    if(this != &cp)
        literal = cp.literal;
    return *this;
}

// Converters
bool ScalarConverter::literalChar(std::string str)
{
    if(str.length() == 1 && isalpha(str[0]))
        return true;
    return false;
}

bool    ScalarConverter::literalInt(std::string str)
{
        std::istringstream iss(str);
        int convertedValue;
        char leftover;

        if (!(iss >> convertedValue) || (iss >> leftover))
        {
            return false;
        }
    return true;
}

bool ScalarConverter::literalFloat(std::string str)
{
        std::istringstream iss(str);
        float convertedValue;
        char leftover;

        if (!(iss >> convertedValue) || (iss >> leftover))
        {
            return false;
        }
    return true;
}

bool ScalarConverter::literalDouble(std::string str)
{
        std::istringstream iss(str);
        double convertedValue;
        char leftover;

        if (!(iss >> convertedValue) || (iss >> leftover))
        {
            return false;
        }
    return true;
}

bool ScalarConverter::special(std::string str)
{
    if(str == "nan" || str == "-inf" || str == "+inf" ||
        str == "nanf" || str == "-inff" || str == "+inff" || str == "inf" || str == "inff")
        return true;
    return false;
}

void ScalarConverter::putChar(std::string str)
{
    int value = std::atof(str.c_str());
    if(value < 0 || value > 128)
        std::cout << "char: impossible" << std::endl;
    else if(value < 32 || value > 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "Char: " << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::toChar(std::string str)
{
    int value = static_cast<int>(str[0]);
    if(value < 0 || value > 128)
        std::cout << "char: impossible" << std::endl;
    else if(value < 32 || value > 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "Char: " << "'" << static_cast<char>(value) << "'" << std::endl;
    std::cout << "Int: " << static_cast<int>(value) << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(2) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::toInt(std::string str)
{
    int value = std::atoi(str.c_str());
    putChar(str);
    std::cout << "Int: " << value << std::endl;
    std::cout << "Float: " << std::fixed << static_cast<float>(value) << "f" << std::endl;
    std::cout << "Double: " << std::fixed << static_cast<double>(value) << std::endl;
}

void ScalarConverter::toFloat(std::string str)
{
    float value = std::atof(str.c_str());
    putChar(str);
    if (INT_MIN > static_cast<double>(value) || INT_MAX < static_cast<double>(value))
    {
        std::cout << "Int: " << "Impossible" << std::endl;
    }
    else
        std::cout << "Int: " << static_cast<int>(value) << std::endl;
    std::cout << "Float: " << value << "f" << std::endl;
    std::cout << "Double: " << std::fixed << static_cast<double>(value) << std::endl;
}

void ScalarConverter::toDouble(std::string str)
{
    double value = std::atof(str.c_str());
    putChar(str);
    if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN))
        std::cout << "Int: " << "Impossible" << std::endl;
    else
        std::cout << "Int: " << static_cast<int>(value) << std::endl;
    std::cout << "Float: " << std::fixed << static_cast<float>(value) << "f" << std::endl;
    std::cout << "Double: " << std::fixed << value << std::endl;
}

void ScalarConverter::putSpecial(std::string literal){
    if (literal == "nan")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
    }
    else if (literal == "-inf" || literal == "+inf" || literal == "inf")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: " << literal << "f" << std::endl;
        std::cout << "Double: " << literal << std::endl;
    }
    else if (literal == "nanf" || literal == "-inff" || literal == "+inff" || literal == "inff" )
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: " << literal << std::endl;
        std::cout << "Double: " << literal << std::endl;
    }
}

void ScalarConverter::convert(std::string literal)
{
    if(special(literal))
    {
        putSpecial(literal);
    }
    else if(literalChar(literal))
    {
        toChar(literal);
    }
    else if(literalInt(literal))
    {
        toInt(literal);
    }
    else if(literalFloat(literal))
    {
        toFloat(literal);
    }
    else if(literalDouble(literal))
    {
        toDouble(literal);
    }
    else
        throw(std::range_error("wrong input"));
}