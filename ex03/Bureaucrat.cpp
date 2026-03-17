#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException("Bureaucrat " + _name + "'s grade already lowest");
	else if (grade < 1)
		throw GradeTooHighException("Bureaucrat " + _name + "'s grade already highest");
	else
		_grade = grade;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& orig) : _name(orig._name), _grade(orig._grade)
{

}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& orig)
{
	if (this != &orig)
	{
		_grade = orig._grade;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& orig)
{
	std::string	message = orig.getName() + " bureaucrat grade " + std::to_string(orig.getGrade());
	os << message;
	return (os);
}

const std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	_grade -= 1;
	if (_grade < 1)
	{
		_grade = 1;
		throw GradeTooHighException("Bureaucrat " + _name + "'s grade already highest");
	}
}

void	Bureaucrat::decrementGrade()
{
	_grade += 1;
	if (_grade > 150)
	{
		_grade = 150;
		throw GradeTooLowException("Bureaucrat " + _name + "'s grade already lowest");
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string message)
{
	_message = message;	
}

const char*	Bureaucrat::GradeTooHighException::what() const noexcept
{
	return (_message.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string message)
{
	_message = message;	
}

const char*	Bureaucrat::GradeTooLowException::what() const noexcept
{
	return (_message.c_str());
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "Bureaucrat: " + this->_name + " signed " + form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat: " + this->_name + " couldn't sign form " + form.getName() + " because" << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		std::cout << this->_name + " executed " + form.getName() << std::endl;
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat: " + this->_name + " couldn't sign form " + form.getName() + " because" << e.what() << std::endl; 
	}
}
