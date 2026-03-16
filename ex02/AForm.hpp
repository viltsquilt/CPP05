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
			AForm();
			AForm(const std::string &name, const int signGrade, const int executeGrade);
			AForm(const AForm& orig);
			AForm&	operator=(const AForm& orig);
			virtual ~AForm();
			void			beSigned(Bureaucrat& bureaucrat);
			std::string		getName() const;
			bool			getSignStatus() const;
			int				getSignGrade() const;
			int				getExecuteGrade() const;
			void			execute(Bureaucrat const &executor) const;
			virtual void	beExecuted() const = 0;
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
	class FormNotSignedException : public std::exception
	{
		private:
				std::string _message;
		public:
				FormNotSignedException(const std::string message);
				const char*	what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& orig);
