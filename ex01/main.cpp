#include "Bureaucrat.hpp"

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
		Bureaucrat	d("Miika", 120);
		Bureaucrat	b("Joa", 100);
		Form	form("Vin Diesel-themed Valentine's Day card for Joa", 120, 50);
		Form	form1("Hatsune Miku body pillow gift-gard for Peter", 150, 100);
		Form	form2("a confession detailing how she doesn't actually even like Taylor Swift that much.", 100, 50);
		d.signForm(form);
		b.signForm(form1);
		a.signForm(form2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
