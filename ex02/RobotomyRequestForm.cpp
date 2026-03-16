#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target)
{
	std::cout << "Robotomy Request Form parametrised constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& orig) : AForm(orig), _target(orig._target)
{
	std::cout << "Form copy constructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& orig)
{
	std::cout << "Robotomy Request Form copy assignment operator called" << std::endl;
	if (this != &orig)
	{
		AForm::operator=(orig);
		_target = orig._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form destructor called" << std::endl;
}

void	RobotomyRequestForm::beExecuted() const
{
	std::cout << "*OBNOXIOUS DRILLING NOISES*" << std::endl;
	if(rand() % 2 == 0)
	{
		std::cout << _target + " robotomized successfully." << std::endl;
	}
	else
	{
		std::cout << " failed to be robotomized." << std::endl;
	}
}
