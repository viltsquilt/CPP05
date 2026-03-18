#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& orig) : AForm(orig), _target(orig._target)
{

}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& orig)
{
	if (this != &orig)
	{
		AForm::operator=(orig);
		_target = orig._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

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
		std::cout << _target + " failed to be robotomized." << std::endl;
	}
}
