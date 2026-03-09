#include "Form.hpp"

Form::Form() : _name("name"), _sign(false), _signGrade(1), _executeGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, const int signGrade, const int executeGrade) : _name(name), _sign(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Form parametrized constructor called" << std::endl;
	if (_signGrade < 1)
	{
		throw GradeTooHighException("Form " + _name + 
		" grade needed for signing cannot be above 1!");
	}
	if (_executeGrade < 1)
	{
		throw GradeTooHighException("Form " + _name + 
		" grade needed for executing cannot be above 1!");
	}
	if (_signGrade > 150)
	{
		throw GradeTooLowException("Form " + _name + 
		" grade needed for signing cannot be below 150!");
	}
	if (_executeGrade > 150)
	{
		throw GradeTooLowException("Form " + _name + 
		" grade needed for executing cannot be below 150!");
	}
}

Form::Form(const Form& orig) : _name(orig._name), _sign(orig._sign), _signGrade(orig._signGrade), _executeGrade(orig._executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form&	Form::operator=(const Form& orig)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &orig)
		_sign = false;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Form& orig)
{
	os << "Form: " << orig.getName() << std::endl << "Grade needed to sign: " 
	<< orig.getSignGrade() << std::endl << "Grade needed to execute: " 
	<< orig.getExecuteGrade() << std::endl;

	if (orig.getSignStatus())
	{
		std::cout << "Form is already signed\n";
	}
	else
	{
		std::cout << "Form is not signed\n";
	}
	return (os);
}

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getSignStatus() const
{
	return (_sign);
}

int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecuteGrade() const
{
	return (_executeGrade);
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (getSignStatus())
	{
		throw FormAlreadySignedException(_name + " is already signed!");
	}
	if (bureaucrat.getGrade() > _signGrade)
	{
		_sign = false;
		throw GradeTooLowException(" grade is too low to sign!");
	}
	_sign = true;
}

Form::GradeTooLowException::GradeTooLowException(const std::string message)
{
	_message = message;
}

const char*	Form::GradeTooLowException::what() const noexcept
{
	return (_message.c_str());
}

Form::GradeTooHighException::GradeTooHighException(const std::string message)
{
	_message = message;
}

const char*	Form::GradeTooHighException::what() const noexcept
{
	return (_message.c_str());
}

Form::FormAlreadySignedException::FormAlreadySignedException(const std::string message)
{
	_message = message;
}

const char*	Form::FormAlreadySignedException::what() const noexcept
{
	return (_message.c_str());
}
