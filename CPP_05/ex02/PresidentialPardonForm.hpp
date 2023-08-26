#ifndef PRESIDENTIALPARDONFORM_CLASS
#define PRESIDENTIALPARDONFORM_CLASS

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
public:
    // Constructors / Destructors
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const &cp);

    //Getters / Setters
    std::string getTarget() const;

    // Utils
    void toExecute() const;

    //Operators
    PresidentialPardonForm& operator=(PresidentialPardonForm const &cp);

private:
    std::string target;
};

#endif