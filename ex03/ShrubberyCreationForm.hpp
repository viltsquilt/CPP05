#pragma once

#include "Bureaucrat.hpp"

class AForm;

class	ShrubberyCreationForm : public AForm
{
	private:
			std::string	_target;
	public:
			ShrubberyCreationForm();
			ShrubberyCreationForm(const std::string target);
			ShrubberyCreationForm(const ShrubberyCreationForm& orig);
			ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& orig);
			~ShrubberyCreationForm();
			void		beExecuted()const override;
};
