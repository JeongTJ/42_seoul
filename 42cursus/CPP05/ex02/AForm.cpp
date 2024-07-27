#include "AForm.hpp"
#include <iomanip>

/* -------------------------------------------------------------------------- */
/*                                   AForm                                    */
/* -------------------------------------------------------------------------- */

AForm::AForm(const std::string& name, const unsigned int& gradeToSign, const unsigned int& gradeToExecute):
	name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSign(false) {
	if (this->gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (this->gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (this->gradeToSign > 150)
		throw AForm::GradeTooLowException();
	if (this->gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {

}

AForm::AForm(const AForm &other): name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), isSign(other.isSign) {

}

AForm& AForm::operator=(const AForm &other) {
	if (this == &other)
		return *this;
	return *this;
}

const std::string& AForm::getName() const{
	return name;
}

unsigned int AForm::getGradeToSign() const{
	return gradeToSign;
}

unsigned int AForm::getGradeToExecute() const{
	return gradeToExecute;
}

bool AForm::getIsSign() const{
	return isSign;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->isSign = true;
}

/* -------------------------------------------------------------------------- */
/*                            GradeTooHighException                           */
/* -------------------------------------------------------------------------- */

AForm::GradeTooHighException::GradeTooHighException(): std::exception() {
	// 구현체 없음
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {
	// 구현체 없음
}

AForm::GradeTooHighException::GradeTooHighException(const AForm::GradeTooHighException &other): std::exception(other) {
	// 구현체 없음
}

AForm::GradeTooHighException &AForm::GradeTooHighException::operator=(const AForm::GradeTooHighException &other) {
	if (this == &other)
		return *this;
	std::exception::operator=(other);
	return *this;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "AForm::GradeTooHighException";
}

/* -------------------------------------------------------------------------- */
/*                            GradeTooLowException                            */
/* -------------------------------------------------------------------------- */

AForm::GradeTooLowException::GradeTooLowException(): std::exception() {
	// 구현체 없음
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {
	// 구현체 없음
}

AForm::GradeTooLowException::GradeTooLowException(const AForm::GradeTooLowException &other): std::exception(other) {
	// 구현체 없음
}

AForm::GradeTooLowException &AForm::GradeTooLowException::operator=(const AForm::GradeTooLowException &other) {
	if (this == &other)
		return *this;
	std::exception::operator=(other);
	return *this;
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "AForm::GradeTooLowException";
}

/* -------------------------------------------------------------------------- */
/*                                  insertion                                 */
/* -------------------------------------------------------------------------- */

std::ostream &operator<<(std::ostream &ostrm, const AForm &aForm) {
	ostrm << std::left << std::setw(15) << "name" << ": " << aForm.getName() << std::endl;
	ostrm << std::left << std::setw(15) << "gradeToSign" << ": " << aForm.getGradeToSign() << std::endl;
	ostrm << std::left << std::setw(15) << "gradeToExecute" << ": " << aForm.getGradeToExecute() << std::endl;
	ostrm << std::left << std::setw(15) << "isSign" << ": " << (aForm.getIsSign() ? "true" : "false") << std::endl;
	return ostrm;
}
