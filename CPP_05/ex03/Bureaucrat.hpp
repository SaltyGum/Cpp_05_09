#ifndef BUREUCRAT_CLASS
#define BUREUCRAT_CLASS

#include "AForm.hpp"
#include <iostream>
#define MIN_GRADE 150
#define MAX_GRADE 1

class AForm;

class Bureaucrat {
public:

    // Constructor / Destructor
    Bureaucrat(std::string name, unsigned int grade);
    ~Bureaucrat();

    // Operators
    Bureaucrat(Bureaucrat const &copy);
    Bureaucrat& operator=(Bureaucrat const &copy);

    // Getters / Setters
    std::string const getName() const;
    int getGrade() const;
    void setGrade(int grade);

    // Utils
    void gradeIncrement();
    void gradeDecrement();
    void signForm(AForm& form);
    void executeForm(AForm const & form);

    // Exceptions
    class GradeTooHighException : public std::logic_error {
    public:
        GradeTooHighException();
    };

    class GradeTooLowException : public std::logic_error {
    public:
        GradeTooLowException();
    };

private:
    std::string const name;
    unsigned int grade;
};

    std::ostream &operator<<(std::ostream &out, Bureaucrat const &copy);

#endif