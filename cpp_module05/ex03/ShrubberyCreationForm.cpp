
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : 
    AForm("ShrubberyCreationForm", 145, 137), 
    target(_target){}
    
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), target(src.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this == &src)
		return *this;
	AForm::operator=(src);
	target = src.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if ( this->getIsSigned() == false )
        throw AForm::FormNotSigned();
    else if ( executor.getGrade() > this->getGradeToExecute() ) {
        throw AForm::GradeTooLowException();
    }    
    std::string fileName = std::string(target+"_shrubbery");

    std::ofstream outfile (target.c_str());

    outfile << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
    outfile << "            {/{/\\}{/{/\\}(\\}{/{/\\} _" << std::endl;
    outfile << "           {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
    outfile << "        {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
    outfile << "       {/{/(_)/}{\\{/)}{\\(_){/}/}/}/}" << std::endl;
    outfile << "      _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
    outfile << "     {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
    outfile << "     _{\\{/{\\{(/_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
    outfile << "    {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
    outfile << "     {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
    outfile << "      {/{\\{\\/}{/{\\{\\/}/}{\\{\\/}/}\\}(_)_" << std::endl;
    outfile << "     {/{\\{\\/}{/){\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
    outfile << "      {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
    outfile << "        {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
    outfile << "         (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
    outfile << "           {/{\\{\\/}{/{\\{\\/}/}{\\{\\(_)" << std::endl;
    outfile << "            {/{\\{\\/}/}{\\{\\\\}/}" << std::endl;
    outfile << "             {){/ {\\/}{\\/} \\}\\}" << std::endl;
    outfile << "             (_)  \\.-'.-/" << std::endl;
    outfile << "         __...--- |'-.-'| --...__" << std::endl;
    outfile << "  _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl;
    outfile << "-\"    ' .  . '    |.'-._| '  . .  '   " << std::endl;
    outfile << ".  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
    outfile << "         ' ..     |'-_.-|" << std::endl;
    outfile << " .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
    outfile << "             .'   |'- .-|   '." << std::endl;
    outfile << " ..-'   ' .  '.   `-._.-´   .'  '  - ." << std::endl;
    outfile << "  .-' '        '-._______.-'     '  ." << std::endl;
    outfile << "       .      ~," << std::endl;
    outfile << "   .       .   |\\   .    ' '-." << std::endl;

    outfile.close();
}