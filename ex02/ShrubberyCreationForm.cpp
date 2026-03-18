#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& orig) : AForm(orig), _target(orig._target)
{

}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& orig)
{
	if (this != &orig)
	{
		AForm::operator=(orig);
		_target = orig._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

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
