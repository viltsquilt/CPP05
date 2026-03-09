#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a("Jenni", 1);
	Bureaucrat	b("Joa", 150);

	std::cout << a << std::endl;
	try
	{
		a.incrementGrade();
		std::cout << a << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		a.decrementGrade();
		std::cout << a << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b << std::endl;
	try
	{
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b << std::endl;
	return (0);
}
