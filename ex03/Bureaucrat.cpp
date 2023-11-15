/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:07:02 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 18:07:03 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat & biro) {
  *this = biro;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &biro) {
  this->grade = biro.getGrade();
  return *this;
}

Bureaucrat::Bureaucrat(std::string Name, int Grade) :  name(Name) {
  if (Grade > 150)
    throw Bureaucrat::GradeTooLowException();
  else if (Grade < 1)
    throw Bureaucrat::GradeTooHighException();
  this->grade = Grade;
}

std::string Bureaucrat::getName() const {return this->name;}
int Bureaucrat::getGrade() const {return this->grade;}
 
void Bureaucrat::gradeIncrement() {
  if (this->grade - 1 < 1)
    throw Bureaucrat::GradeTooHighException();
  this->grade--;
}

void Bureaucrat::gradeDecrement() {
  if (this->grade + 1 > 150)
    throw Bureaucrat::GradeTooLowException();
  this->grade++;
}

std::ostream & operator<<(std::ostream & os, Bureaucrat & biro) {
  os << biro.getName() <<  " bureaucrat grade "  << biro.getGrade() << "\n";
  return os;
}


void Bureaucrat::executeForm(AForm const & form) {
  if (form.getIsSigned())
    std::cout << this->name << " executed " << form.getName();
  else
    std::cout << this->name << " failt to  execut" << form.getName();
}


void Bureaucrat::signForm(AForm & form) const {
  if (form.getIsSigned())
    std::cout << this->name << " signed "  << form.getName() << std::endl;
  else 
    std::cout << this->name << " couldn’t sign "  << form.getName() << " because " \
      << " signe type false " << std::endl;
}
