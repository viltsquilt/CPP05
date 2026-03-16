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
		Bureaucrat	d("Miika", 12);
		Bureaucrat	b("Joa", 5);
		ShrubberyCreationForm	tree("shrub");
		PresidentialPardonForm	pardon("Jenni");
		RobotomyRequestForm	drill("Joa");
		d.signForm(drill);
		b.signForm(pardon);
		a.signForm(tree);
		d.executeForm(drill);
		b.executeForm(pardon);
		a.executeForm(tree);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
