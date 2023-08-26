#ifndef AFORM_CLASS
#define AFORM_CLASS

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
public:

    // Constructor / Destructor
    AForm();
    AForm(std::string name, int signGrade, int executeGrade);
    virtual ~AForm();
    AForm(AForm const &cp);

    // Operators
    AForm& operator=(AForm const &cp);

    // Getters / Setters / Checks
    std::string getName() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(Bureaucrat b);
    bool isSign()const;
    void validateGrade();
    void execute(Bureaucrat const & executor) const;

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
    class NotSignException : public std::logic_error {
    public:
        NotSignException();
    };

protected:
    virtual void toExecute() const = 0;

private:
    std::string const name;
    bool sign;
    int const signGrade;
    int const executeGrade;
};

std::ostream& operator<<(std::ostream &io, AForm const &cp);

#endif
