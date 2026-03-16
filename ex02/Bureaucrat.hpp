#pragma once

#include <iostream>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class	AForm;
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
			void	signForm(AForm &form);
			void	executeForm(AForm const &form) const;
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
