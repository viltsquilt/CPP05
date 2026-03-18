#include "Intern.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	a("Jenni", 2);
		AForm*	rrf;
		AForm*	rrf2;
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
		rrf2 = someRandomIntern.makeForm("robotomy request", "Joa");
		b.signForm(*rrf);
		b.executeForm(*rrf);
		b.signForm(*rrf2);
		b.executeForm(*rrf2);
		delete rrf;
		delete rrf2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	a("Jenni", 10);
		AForm*	scf;
		Intern	someRandomIntern;
		scf = someRandomIntern.makeForm("shrubbery creation", "trees");
		a.signForm(*scf);
		a.executeForm(*scf);
		delete scf;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	b("Miika", 4);
		AForm*	ppf;
		Intern	someRandomIntern;
		ppf = someRandomIntern.makeForm("presidential pardon", "Joa");
		b.signForm(*ppf);
		b.executeForm(*ppf);
		delete ppf;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	d("Joa", 5);
		AForm*	rand;
		Intern	someRandomIntern;
		rand = someRandomIntern.makeForm("gabagool", "Ayyy");
		d.signForm(*rand);
		d.executeForm(*rand);
		delete rand;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
