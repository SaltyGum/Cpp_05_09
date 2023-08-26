#ifndef ROBOTOMYREQUESTFORM_CLASS
#define ROBOTOMYREQUESTFORM_CLASS

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
public:
    // Constructors / Destructors
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &cp);

    //Getters / Setters
    std::string getTarget() const;

    // Utils
    void toExecute() const;

    //Operators
    RobotomyRequestForm& operator=(RobotomyRequestForm const &cp);

private:
    std::string target;
};

#endif