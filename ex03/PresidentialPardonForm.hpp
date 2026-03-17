#pragma once

#include "Bureaucrat.hpp"

class AForm;

class	PresidentialPardonForm : public AForm
{
	private:
			std::string	_target;
	public:
			PresidentialPardonForm();
			PresidentialPardonForm(const std::string target);
			PresidentialPardonForm(const PresidentialPardonForm& orig);
			PresidentialPardonForm&	operator=(const PresidentialPardonForm& orig);
			~PresidentialPardonForm();
			void			beExecuted()const override;
};
