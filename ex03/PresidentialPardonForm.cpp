/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:07:18 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 18:07:19 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential PardonForm", 25, 5) {
  this->target = "default_target";
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & shrubbery) : AForm("Presidential PardonForm", 25, 5) {
  *this = shrubbery;
}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & shrubbery) {
  if (this != &shrubbery) {
    this->target = shrubbery.target;
  }
  return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential PardonForm", 25, 5) {
  this->target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
  if (!this->getIsSigned() || executor.getGrade() > this->getExecGrade())
    throw PresidentialPardonForm::GradeTooLowException();
  std::cout << this->target << " has been pardoned by Zaphod Beeblebrox " << std::endl;
}
