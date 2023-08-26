#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45), target("unnamed")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cp) : AForm("RobotomyRequest", 72, 45), target(cp.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &cp)
{
    if(this != &cp)
        target = cp.getTarget();
    return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

void RobotomyRequestForm::toExecute() const
{
    std::srand(std::time(0));
    std::cout << "\n******* Make some drilling noises ******" << std::endl;
    std::string success = target + " has been robotomized successfully!";
    std::string fail = "Robotomy failed, " + target + " is dead";
    std::cout << (std::rand() % 2 ? success : fail) << std::endl;
}