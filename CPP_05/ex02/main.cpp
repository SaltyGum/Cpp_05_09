#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(){

	ShrubberyCreationForm a("Amazonia");
	RobotomyRequestForm b("Bender");
	PresidentialPardonForm c("Arthur Dent");
    Bureaucrat	HighBureucrat("Ford Prefect", 1);
	Bureaucrat	MediumBureucrat("Marvin", 43);
	Bureaucrat	LowBureucrat("Arthur", 149);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	
	std::cout << "\n\n->Arthur will never sign this :("<<std::endl;
	LowBureucrat.executeForm(c);
	HighBureucrat.signForm(c);
	LowBureucrat.executeForm(c);
	HighBureucrat.executeForm(c);

	std::cout << "\n\n->Marvin is too lazy to execute but Ford Prefect can"<<std::endl;
	MediumBureucrat.executeForm(b);
	HighBureucrat.signForm(b);
	MediumBureucrat.executeForm(b);

	std::cout << "\n\n->Execute After grade increment"<<std::endl;
	LowBureucrat.executeForm(a);
	HighBureucrat.signForm(a);
	LowBureucrat.gradeIncrement();
	LowBureucrat.gradeIncrement();
	LowBureucrat.gradeIncrement();
	LowBureucrat.executeForm(a);
}