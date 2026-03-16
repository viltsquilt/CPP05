#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	Bureaucrat	a("Jenni", 1);

	std::cout << a << std::endl;
	try
	{
		a.decrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		Bureaucrat	b("Joa", 151);
		Bureaucrat	c(b);
		b.decrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	a("Jenni", 10);
		ShrubberyCreationForm	tree("shrub");
		a.signForm(tree);
		a.executeForm(tree);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	b("Miika", 12);
		PresidentialPardonForm	pardon("Jenni");
		b.signForm(pardon);
		b.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	d("Joa", 5);
		RobotomyRequestForm	drill("Joa");
		d.signForm(drill);
		d.executeForm(drill);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
