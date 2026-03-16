#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target)
{
	std::cout << "Shrubbery Creation Form parametrised constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& orig) : AForm(orig), _target(orig._target)
{
	std::cout << "Shrubbery Creation Form copy constructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& orig)
{
	std::cout << "Shrubbery Creation Form copy assignment operator called" << std::endl;
	if (this != &orig)
	{
		AForm::operator=(orig);
		_target = orig._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form destructor called" << std::endl;
}

void	ShrubberyCreationForm::beExecuted() const
{
	std::ofstream outfile(_target + "_shrubbery");
	if (!outfile)
	{
		throw std::runtime_error("Unable to create outfile");
	}
	outfile << "               ; ; ;\n";
	outfile << "       ;        ;  ;     ;;    ;\n";
	outfile << "   ;                 ;         ;  ;\n";
	outfile << "                ;\n";
	outfile << "               ;                ;;\n";
	outfile << ";           ;            ;              ;\n";
	outfile << ";             ';,        ;               ;\n";
	outfile << " ;                 'b      *\n";
	outfile << "   ;                 '$    ;;                ;;\n";
	outfile << "      ;    ;           $:   ;:               ;\n";
	outfile << "       ;;  ;  ;;      *;  @):        ;   ; ;\n";
	outfile << "                ;     :@,@):   ,;**:'   ;\n";
	outfile << "    ;      ;,         :@@*: ;;**'      ;   ;\n";
    outfile << "          ';o;    ;:(@';@*""'  ;\n";
	outfile << "    ;  ;       'bq,;;:,@@*'   ,*      ;  ;\n";
	outfile << "              ,p$q8,:@)'  ;p*'      ;\n";
	outfile << "      ;     '  ; '@@Pp@@*'    ;  ;\n";
	outfile << "       ;  ; ;;    Y7'.'     ;  ;\n";
	outfile << "                 :@):.\n";
	outfile << "                .:@:'.\n";
	outfile << "              .::(@:.\n";
	outfile << "------------------------------------------------\n";
}
