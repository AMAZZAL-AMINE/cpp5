/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:55:05 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 17:55:06 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("bureu_default_name"), grade(1) {}
Bureaucrat::Bureaucrat(const Bureaucrat & biro) : name(biro.getName()), grade(biro.getGrade()) {}
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

void Bureaucrat::signForm(Form & form) const {
  if (form.getIsSigned())
    std::cout << this->name << " signed "  << form.getName() << std::endl;
  else 
    std::cout << this->name << " couldn’t sign "  << form.getName() << " because " \
      << " signe type false " << std::endl;
}
