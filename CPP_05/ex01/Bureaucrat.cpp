
#include "Bureaucrat.hpp"
#include "Form.hpp"

// Getters / Setters
std::string const Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::setGrade(int grade) {
  if (grade < 1) {
    throw GradeTooHighException();
  } else if (grade > 150) {
    throw GradeTooLowException();
  }
  this->grade = grade;
}

// Constructor / Destructor
Bureaucrat::~Bureaucrat() {
  std::cout<<"Calling destructor of:"<<this<<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name(name)
{
  setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.getName()), grade(copy.getGrade())
{
}

// Utils
Bureaucrat::GradeTooHighException::GradeTooHighException() : std::logic_error("Grade Too High, maximum grade is 1"){}

Bureaucrat::GradeTooLowException::GradeTooLowException() : std::logic_error("Grade Too Low, minimum grade is 150"){}

void Bureaucrat::signForm(Form& form)
{
  try
  { 
    form.beSigned(*this);
    std::cout<<name<<" signed "<<form.getName() << std::endl;
  }
  catch(std::exception &exept){
    std::cout<<name<<" could't sign "<<form.getName()<<" because " << exept.what()<<std::endl;}
}

// Operations
void Bureaucrat::gradeIncrement() {
  if(grade - 1 < MAX_GRADE)
    throw GradeTooHighException();
  setGrade(grade - 1);
}

void Bureaucrat::gradeDecrement() {
  if(grade + 1 > MIN_GRADE)
    throw GradeTooLowException();
  setGrade(grade + 1);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &copy){
  out << copy.getName() <<", bureaucrat grade "<< copy.getGrade()<< std::endl;
  return out;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& copy)
{
  if (this != &copy) {
    grade = copy.getGrade();
  }
  return *this;
}