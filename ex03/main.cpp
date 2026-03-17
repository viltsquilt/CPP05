#include "Intern.hpp"

int	main(void)
{
	AForm*	rrf;
	AForm*	scf;
	AForm*	ppf;
	AForm*	rand;
	try
	{
		Bureaucrat	a("Jenni", 2);
		a.decrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		Bureaucrat	b("Joa", 5);
		Bureaucrat	c(b);
		b.decrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		Intern	someRandomIntern;
		rrf = someRandomIntern.makeForm("robotomy request", "Joa");
		b.signForm(*rrf);
		b.executeForm(*rrf);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	a("Jenni", 10);
		Intern	someRandomIntern;
		scf = someRandomIntern.makeForm("shrubbery creation", "trees");
		a.signForm(*scf);
		a.executeForm(*scf);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	b("Miika", 4);
		Intern	someRandomIntern;
		ppf = someRandomIntern.makeForm("presidential pardon", "Joa");
		b.signForm(*ppf);
		b.executeForm(*ppf);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	d("Joa", 5);
		Intern	someRandomIntern;
		rand = someRandomIntern.makeForm("gabagool", "Ayyy");
		d.signForm(*rand);
		d.executeForm(*rand);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete rrf;
	delete scf;
	delete ppf;
	delete rand;
	return (0);
}
