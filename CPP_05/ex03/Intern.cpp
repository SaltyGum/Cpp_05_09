#include "Intern.hpp"

Intern::Intern() {
}
Intern::~Intern()
{
}

Intern::Intern(Intern const &cp)
{
    (void)cp;
}

Intern& Intern::operator=(Intern const &cp){
    (void)cp;
    return (*this);   
}

AForm *Intern::pardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::robotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::shrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string type, std::string target)
{
    Form formList[] = {
    { "shrubbery creation",  "Shrubbery Creation Form", &Intern::shrubbery },
    { "robotomy request",    "Robotomy Request Form",    &Intern::robotomy  },
    { "presidential pardon", "Presidential Pardon Form", &Intern::pardon  }
};
    size_t i = 0;
    size_t maxLoop = sizeof(formList) / sizeof(Form);
    while(i < maxLoop)
    {
        if (type == formList[i].id)
            break;
        i++;
    }
    Func form = formList[i].func;
    if (i == maxLoop)
        throw std::invalid_argument("invalid form name " + formList->name);
    AForm *out = (this->*form)(target);
    std::cout << "Intern creates" << " " << formList[i].name << std::endl;
    return out;
}