/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:03:02 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 18:03:03 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45) {
  this->target = "default_target";
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & shrubbery) : AForm("Robotomy Request", 72, 45) {
  *this = shrubbery;
}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & shrubbery) {
  if (this != &shrubbery) {
    this->target = shrubbery.target;
  }
  return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45) {
  this->target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
  if (!this->getIsSigned() || executor.getGrade() > this->getExecGrade())
    throw RobotomyRequestForm::GradeTooLowException();
  std::cout << this->target << " has been robotomized successfully 50% of the time " << std::endl;
}
