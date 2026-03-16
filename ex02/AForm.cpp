#include "AForm.hpp"

AForm::AForm() : _name("name"), _sign(false), _signGrade(1), _executeGrade(1)
{
	std::cout << "AAForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, const int signGrade, const int executeGrade) : _name(name), _sign(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "AForm parametrized constructor called" << std::endl;
	if (_signGrade < 1)
	{
		throw GradeTooHighException("AForm " + _name + 
		" grade needed for signing cannot be above 1!");
	}
	if (_executeGrade < 1)
	{
		throw GradeTooHighException("AForm " + _name + 
		" grade needed for executing cannot be above 1!");
	}
	if (_signGrade > 150)
	{
		throw GradeTooLowException("AForm " + _name + 
		" grade needed for signing cannot be below 150!");
	}
	if (_executeGrade > 150)
	{
		throw GradeTooLowException("AForm " + _name + 
		" grade needed for executing cannot be below 150!");
	}
}

AForm::AForm(const AForm& orig) : _name(orig._name), _sign(orig._sign), _signGrade(orig._signGrade), _executeGrade(orig._executeGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm&	AForm::operator=(const AForm& orig)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &orig)
		_sign = false;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const AForm& orig)
{
	os << "AForm: " << orig.getName() << std::endl << "Grade needed to sign: " 
	<< orig.getSignGrade() << std::endl << "Grade needed to execute: " 
	<< orig.getExecuteGrade() << std::endl;

	if (orig.getSignStatus())
	{
		std::cout << "AForm is already signed\n";
	}
	else
	{
		std::cout << "AForm is not signed\n";
	}
	return (os);
}

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getSignStatus() const
{
	return (_sign);
}

int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecuteGrade() const
{
	return (_executeGrade);
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
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

void	AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _executeGrade)
	{
		throw GradeTooLowException(" grade is too low to sign!");
	}
	if (!getSignStatus())
	{
		throw FormNotSignedException(" form not signed!");
	}
	beExecuted();
}

void	AForm::beExecuted() const
{
	std::cout << "stuff happens" << std::endl;
}

AForm::GradeTooLowException::GradeTooLowException(const std::string message)
{
	_message = message;
}

const char*	AForm::GradeTooLowException::what() const noexcept
{
	return (_message.c_str());
}

AForm::GradeTooHighException::GradeTooHighException(const std::string message)
{
	_message = message;
}

const char*	AForm::GradeTooHighException::what() const noexcept
{
	return (_message.c_str());
}

AForm::FormAlreadySignedException::FormAlreadySignedException(const std::string message)
{
	_message = message;
}

const char*	AForm::FormAlreadySignedException::what() const noexcept
{
	return (_message.c_str());
}

AForm::FormNotSignedException::FormNotSignedException(const std::string message)
{
	_message = message;
}

const char*	AForm::FormNotSignedException::what() const noexcept
{
	return (_message.c_str());
}
