#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade)
{
	std::cout << "Parametrised constructor called" << std::endl;
	_name = name;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException;
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException;
	else
		_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& orig)
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator<<(const Bureaucrat& orig)
{
	std::cout << _name << "bureaucrat grade" << _grade << std::endl;
	if (this != orig&)
	{
		_name = orig._name;
		_grade = orig._name;
	}
	return (*this);
}

const std::string	Bureaucrat::getName()
{
	return (_name);
}

unsigned int	Bureaucrat::getgrade()
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	_grade += 1;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string message)
{
	_message = message;	
}

const char*	Bureaucrat::GradeTooLowException::what()
{
	return (_message.c_string);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string message)
{
	_message = message;	
}

const char*	Bureaucrat::GradeTooLowException::what()
{
	return (_message.c_string);
}
