#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("RobotomyRequest", 145, 137), target("unnamed")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("RobotomyRequest", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cp) : AForm("RobotomyRequest", 145, 137), target(cp.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &cp)
{
    if(this != &cp)
        target = cp.getTarget();
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

void ShrubberyCreationForm::toExecute() const
{
    std::ofstream file;
    std::string filename = target + "_shrubbery";
    file.open(filename.c_str());
    file << "         * " << std::endl;
    file << "        *** " << std::endl;
    file << "       *oOo* " << std::endl;
    file << "      *oOoOo* " << std::endl;
    file << "     *oOoOoOo* " << std::endl;
    file << "    *oOoOoOoOo* " << std::endl;
    file << "   *oOoOoOoOoOo* " << std::endl;
    file << "       |||||      " << std::endl;
    file.close();
}