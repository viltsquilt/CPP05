#pragma once

#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	private:
			const std::string	_name;
			bool				_sign;
			const int			_signGrade;
			const int			_executeGrade;
	public:
			Form();
			Form(const std::string &name, const int signGrade, const int executeGrade);
			Form(const Form& orig);
			Form&	operator=(const Form& orig);
			virtual ~Form();
			void		beSigned(Bureaucrat& bureaucrat);
			virtual std::string	getName() const = 0;
			bool		getSignStatus() const;
			int			getSignGrade() const;
			int			getExecuteGrade() const;
	class GradeTooHighException : public std::exception
	{
		private:
				std::string	_message;
		public:
				GradeTooHighException(const std::string message);
				const char*	what() const noexcept override;
	};
	class GradeTooLowException : public std::exception
	{
		private:
				std::string	_message;
		public:
				GradeTooLowException(const std::string message);
				const char*	what() const noexcept override;
	};
	class FormAlreadySignedException : public std::exception
	{
		private:
				std::string	_message;
		public:
				FormAlreadySignedException(const std::string message);
				const char*	what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& os, const Form& orig);
