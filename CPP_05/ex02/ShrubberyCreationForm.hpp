#ifndef SHURUBBERRYCREATIONFORM_CLASS
#define SHURUBBERRYCREATIONFORM_CLASS

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
public:
    // Constructors / Destructors
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const &cp);

    //Getters / Setters
    std::string getTarget() const;

    // Utils
    void toExecute() const;

    //Operators
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const &cp);

private:
    std::string target;
};

#endif