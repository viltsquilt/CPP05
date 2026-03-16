#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), _target(target)
{
	std::cout << "Presidential Pardon Form parametrised constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& orig) : AForm(orig), _target(orig._target)
{
	std::cout << "Presidential Pardon Form copy constructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& orig)
{
	std::cout << "Presidential Pardon Form copy assignment operator called" << std::endl;
	if (this != &orig)
	{
		AForm::operator=(orig);
		_target = orig._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form destructor called" << std::endl;
}

void	PresidentialPardonForm::beExecuted() const
{
	std::cout << _target + " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
