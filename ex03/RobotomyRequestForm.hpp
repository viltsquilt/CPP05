#pragma once

#include "Bureaucrat.hpp"

class AForm;

class	RobotomyRequestForm : public AForm
{
	private:
			std::string	_target;
	public:
			RobotomyRequestForm();
			RobotomyRequestForm(const std::string target);
			RobotomyRequestForm(const RobotomyRequestForm& orig);
			RobotomyRequestForm&	operator=(const RobotomyRequestForm& orig);
			~RobotomyRequestForm();
			void		beExecuted()const override;
};
