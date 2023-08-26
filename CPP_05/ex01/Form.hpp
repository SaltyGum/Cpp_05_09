#ifndef FORM_CLASS
#define FORM_CLASS

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form {
public:

    // Constructor / Destructor
    Form();
    Form(std::string name, int signGrade, int executeGrade);
    ~Form();
    Form(Form const &cp);

    // Operators
    Form& operator=(Form const &cp);

    // Getters / Setters / Checks
    std::string getName() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(Bureaucrat b);
    bool isSign()const;
    void validateGrade();

    // Exceptions
    class GradeTooHighException : public std::logic_error {
    public:
        GradeTooHighException();
    };

    class GradeTooLowException : public std::logic_error {
    public:
        GradeTooLowException();
    };

    class AlreadySignException : public std::logic_error {
    public:
        AlreadySignException();
    };
    
private:
    std::string const name;
    bool sign;
    int const signGrade;
    int const executeGrade;
};

std::ostream& operator<<(std::ostream &io, Form const &cp);

#endif
