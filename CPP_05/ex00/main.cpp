#include "Bureaucrat.hpp"

int main(){
    std::cout<<"\nIncrement Error ->"<<std::endl;

// Increment Error
    Bureaucrat	cleitin("cleitin", 3);
	std::cout << cleitin << std::endl;

	try
	{
		for (int cur = 0; cur < 3; cur++)
		{
			cleitin.gradeIncrement();
			std::cout << "" << cleitin << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooHighException &e){
        std::cout << "\n" << e.what() << std::endl;}
	catch (std::exception &e){
		std::cout << "\n" << "Houston we have a problem" << std::endl;}

    std::cout<<"\nDecrement Error ->"<<std::endl;

// Decrement Error
    Bureaucrat	byob("byob", 147);
	std::cout << byob << std::endl;
	try
	{
		for (int cur = 147; cur < 151; cur++)
		{
			byob.gradeDecrement();
			std::cout << "" << byob << std::endl;
		}
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cout << "\n" << e.what() << std::endl;}
    catch (std::exception &e){
		std::cout << "\n" << "Houston we have a problem" << std::endl;}

// Construction Error
    std::cout<<"\nconstructor failure with THROW ->"<<std::endl;
	try
	{
		Bureaucrat	avaliator("youarebeautiful", 152);
		std::cout << avaliator << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Generic error message" << std::endl;
	}

    try
	{
		Bureaucrat	avaliator2("youarebeautiful", -1);
		std::cout << avaliator2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Generic error message" << std::endl;
	}
	return 0;    
}