#pragma once

#include <iostream>
#include <exception>
#include <fstream>
#include "Form.hpp"

class	Form;
class	Bureaucrat
{
	private:
			const std::string	_name;
			int					_grade;
	public:
			Bureaucrat();
			Bureaucrat(const std::string& name, int grade);
			Bureaucrat(const Bureaucrat& orig);
			Bureaucrat&	operator=(const Bureaucrat& orig);
			~Bureaucrat();
			const std::string	getName() const;
			int		getGrade() const;
			void	incrementGrade();
			void	decrementGrade();
			void	signForm(Form& form);
	class GradeTooHighException : public std::exception
	{
		private:
				std::string	_message;
		public:
				GradeTooHighException(const std::string message);
				const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception
	{
		private:
				std::string	_message;
		public:
				GradeTooLowException(const std::string message);
				const char*	what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& orig);
