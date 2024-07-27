#include "Form.hpp"
#include <iomanip>

/* -------------------------------------------------------------------------- */
/*                                    Form                                    */
/* -------------------------------------------------------------------------- */

Form::Form(const std::string& name, const unsigned int& gradeToSign, const unsigned int& gradeToExecute):
	name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSign(false) {
	if (this->gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (this->gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (this->gradeToSign > 150)
		throw Form::GradeTooLowException();
	if (this->gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {

}

Form::Form(const Form &other): name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), isSign(other.isSign) {

}

Form& Form::operator=(const Form &other) {
	if (this == &other)
		return *this;
	return *this;
}

const std::string& Form::getName() const{
	return name;
}

unsigned int Form::getGradeToSign() const{
	return gradeToSign;
}

unsigned int Form::getGradeToExecute() const{
	return gradeToExecute;
}

bool Form::getIsSign() const{
	return isSign;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	else
		this->isSign = true;
}

/* -------------------------------------------------------------------------- */
/*                            GradeTooHighException                           */
/* -------------------------------------------------------------------------- */

Form::GradeTooHighException::GradeTooHighException(): std::exception() {
	// 구현체 없음
}

Form::GradeTooHighException::~GradeTooHighException() throw() {
	// 구현체 없음
}

Form::GradeTooHighException::GradeTooHighException(const Form::GradeTooHighException &other): std::exception(other) {
	// 구현체 없음
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(const Form::GradeTooHighException &other) {
	if (this == &other)
		return *this;
	std::exception::operator=(other);
	return *this;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Form::GradeTooHighException";
}

/* -------------------------------------------------------------------------- */
/*                            GradeTooLowException                            */
/* -------------------------------------------------------------------------- */

Form::GradeTooLowException::GradeTooLowException(): std::exception() {
	// 구현체 없음
}

Form::GradeTooLowException::~GradeTooLowException() throw() {
	// 구현체 없음
}

Form::GradeTooLowException::GradeTooLowException(const Form::GradeTooLowException &other): std::exception(other) {
	// 구현체 없음
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(const Form::GradeTooLowException &other) {
	if (this == &other)
		return *this;
	std::exception::operator=(other);
	return *this;
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form::GradeTooLowException";
}

/* -------------------------------------------------------------------------- */
/*                                  insertion                                 */
/* -------------------------------------------------------------------------- */

std::ostream &operator<<(std::ostream &ostrm, const Form &form) {
	ostrm << std::left << std::setw(15) << "name" << ": " << form.getName() << std::endl;
	ostrm << std::left << std::setw(15) << "gradeToSign" << ": " << form.getGradeToSign() << std::endl;
	ostrm << std::left << std::setw(15) << "gradeToExecute" << ": " << form.getGradeToExecute() << std::endl;
	ostrm << std::left << std::setw(15) << "isSign" << ": " << (form.getIsSign() ? "true" : "false") << std::endl;
	return ostrm;
}
