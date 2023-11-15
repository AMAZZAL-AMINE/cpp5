/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:03:16 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 18:03:17 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "main.h"

AForm::AForm() : name("default_name"), grade(150), execGrade(150) {
  this->isSigned = false;
}

AForm::AForm(const AForm & form) : name(form.name), grade(form.grade), execGrade(form.execGrade) {
  *this = form;
}

AForm::~AForm() {}

AForm & AForm::operator=(const AForm & form) {
  this->isSigned = form.isSigned;
  return *this;
}

AForm::AForm(std::string Name, int Grade, int ExecGrade) 
  : name(Name), grade(Grade), execGrade(ExecGrade) {
    if (Grade > 150 || ExecGrade > 150)
      throw AForm::GradeTooLowException();
    else if (Grade < 1 || ExecGrade < 1)
      throw AForm::GradeTooHighException();
}

std::string AForm::getName() const {
  return this->name;
}
int  AForm::getGrade() const {
  return this->grade;
}
int  AForm::getExecGrade() const {
  return this->execGrade;
}
bool  AForm::getIsSigned() const {
  return this->isSigned;
}

void AForm::beSigned(Bureaucrat & biro) {
  if (biro.getGrade() > this->grade)
    throw AForm::GradeTooLowException();
  this->isSigned = true;
}

std::ostream & operator<<(std::ostream & os, AForm &  form) {
  os << "AForm NAME : " << form.getName() << "\n"; 
  os << "AForm GRADE : " << form.getGrade() << "\n"; 
  os << "AForm EXEC_GRADE : " << form.getExecGrade() << "\n"; 
  os << "AForm IS_SIGNED : " << (form.getIsSigned() ? "true" : "false"); 
  return os;
}
