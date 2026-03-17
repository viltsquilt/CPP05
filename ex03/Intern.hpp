#pragma once

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
			Intern();
			Intern(const Intern& orig);
			Intern&	operator=(const Intern& orig);
			~Intern();
			AForm*	makeForm(const std::string name, const std::string target);
	class FormDoesNotExistException : public std::exception
	{
		private:
				std::string	_message;
		public:
				FormDoesNotExistException(const std::string message);
				const char*	what() const noexcept override;
	};
};
