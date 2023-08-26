#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){

//Form errorWithGrade("Medical issue", 180, 20);
// Increment
	Form TEB("Atestado Medico", 60, 60);
    Bureaucrat	jerfin("jerfin", 15);
	Bureaucrat	doctor("Doutor", 1);
	std::cout << jerfin << std::endl;
	std::cout << doctor << std::endl;
	std::cout << TEB << std::endl;

	try
	{
		for (int cur = 0; cur < 3; cur++)
		{
			std::cout<<cur<< " tentative"<<std::endl;
			jerfin.gradeIncrement();
			jerfin.signForm(TEB);
			std::cout << jerfin << std::endl;
			std::cout << TEB << std::endl;
			std::cout<<"----------------"<<std::endl;
		}
		doctor.signForm(TEB);
		std::cout << TEB << std::endl;
	}
	catch (Form::GradeTooLowException &exept){
		std::cout << "\n" << exept.what() << std::endl;}
	catch (Bureaucrat::GradeTooHighException &exept2){
        std::cout << "\n" << exept2.what() << std::endl;}
	catch (std::exception &exept3){
		std::cout << "\n" << "Houston we have a problem" << std::endl;}

}