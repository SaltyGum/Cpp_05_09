#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Bureaucrat Jerfin("Jerfin", 1);
	Bureaucrat Noob("Jerfin", 149);
	Intern someRandomIntern;
	AForm *PardonForm = someRandomIntern.makeForm("presidential pardon", "Arthur");
	AForm *TreeForm = someRandomIntern.makeForm("shrubbery creation", "TheTown");
	AForm *RobotomyForm = someRandomIntern.makeForm("robotomy request", "Bender");
	// AForm *WrongForm = someRandomIntern.makeForm("WrongForm", "Noice");
	PardonForm->beSigned(Jerfin);
	TreeForm->beSigned(Jerfin);
	RobotomyForm->beSigned(Jerfin);
	std::cout << "***Execute Pardon Form***" << std::endl;
	// PardonForm->execute(Noob);
	 PardonForm->execute(Jerfin);
	std::cout << "\n***Execute TreeForm***" << std::endl;
	// TreeForm->execute(Noob);
	TreeForm->execute(Jerfin);
	std::cout << "\n***Execute RobotomyForm***" << std::endl;
	// RobotomyForm->execute(Noob);
	RobotomyForm->execute(Jerfin); 

	// std::cout << "\n***Execute WrongForm***" << std::endl;
	// RobotomyForm->execute(Noob);
	// WrongForm->execute(Jerfin); 

	delete PardonForm;
	delete TreeForm;
	delete RobotomyForm;
}