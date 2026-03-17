#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& orig)
{
	(void)orig;
}

Intern&	Intern::operator=(const Intern& orig)
{
	(void)orig;
	return (*this);
}

Intern::~Intern()
{

}

AForm*	Intern::makeForm(const std::string name, const std::string target)
{
	std::string	levels[3]
	{
		"presidential pardon",
		"shrubbery creation",
		"robotomy request"
	};
	int	count = 0;
	for (int i = 0; i < 3; i++)
	{
		if (name == levels[i])
			count = i + 1;
	}
	switch (count)
	{
		case(1):
		{
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return (new	PresidentialPardonForm(target));
		}
		case(2):
		{
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return (new	ShrubberyCreationForm(target));
		}
		case(3):
		{
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return (new	RobotomyRequestForm(target));
		}
		default:
		{
			throw FormDoesNotExistException("Requested form does not exist!");
		}
	}
}

Intern::FormDoesNotExistException::FormDoesNotExistException(const std::string message)
{
	_message = message;
}

const char*	Intern::FormDoesNotExistException::what() const noexcept
{
	return (_message.c_str());
}
