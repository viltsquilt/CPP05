#pragma once

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
			const std::string	_name;
			unsigned int		_grade;
	public:
			Bureaucrat();
			Bureaucrat(const Bureaucrat& orig);
			Bureaucrat& operator<<(const Bureaucrat& orig);
			~Bureaucrat();
			const std::string	getName();
			unsigned int		getGrade();
			void	incrementGrade();
			void	decrementGrade();
	class GradeTooHighException : public std::exception
	{
		private:
				std::string	_message;
		public:
				GradeTooHighException(const std::string message);
				const char* what() const noexcept override;
	}
	class GradeTooLowException : public std::exception
	{
		private:
				std::string	_message;
		public:
				GradeTooLowException(const std::string message);
				const char*	what() const noexcept override;
	}
}
