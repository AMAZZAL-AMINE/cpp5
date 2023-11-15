/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:55:10 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 17:55:11 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "main.h"

Form::Form() : name("default_name"), grade(150), execGrade(150) {
  this->isSigned = false;
}

Form::Form(const Form & form) : name(form.name), grade(form.grade), execGrade(form.execGrade) {
  *this = form;
}

Form::~Form() {}

Form & Form::operator=(const Form & form) {
  this->isSigned = form.isSigned;
  return *this;
}

Form::Form(std::string Name, int Grade, int ExecGrade) : name(Name), grade(Grade), execGrade(ExecGrade) {
    if (Grade > 150 || ExecGrade > 150)
      throw Form::GradeTooLowException();
    else if (Grade < 1 || ExecGrade < 1)
      throw Form::GradeTooHighException();
    this->isSigned = false;
}

std::string Form::getName() const {return this->name;}
int  Form::getGrade() const {return this->grade;}
int  Form::getExecGrade() const {return this->execGrade;}
bool  Form::getIsSigned() const {return this->isSigned;}


void Form::beSigned(Bureaucrat & biro) {
  if (biro.getGrade() > this->grade)
    throw Form::GradeTooLowException();
  this->isSigned = true;
}

std::ostream & operator<<(std::ostream & os, Form &  form) {
  os << "FORM NAME : " << form.getName() << "\n"; 
  os << "FORM GRADE : " << form.getGrade() << "\n"; 
  os << "FORM EXEC_GRADE : " << form.getExecGrade() << "\n"; 
  os << "FORM IS_SIGNED : " << (form.getIsSigned() ? "true" : "false"); 
  return os;
}
