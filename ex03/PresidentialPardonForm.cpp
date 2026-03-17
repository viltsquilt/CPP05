#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& orig) : AForm(orig), _target(orig._target)
{

}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& orig)
{
	if (this != &orig)
	{
		AForm::operator=(orig);
		_target = orig._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void	PresidentialPardonForm::beExecuted() const
{
	std::cout << _target + " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
