#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a("Jenni", 1);
	std::cout << a << std::endl;
	try
	{
		a.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		a.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	return (0);
}
