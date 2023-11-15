/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:07:28 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 18:07:29 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137) {
  this->target = "default_target";
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & shrubbery) : AForm("Shrubbery Creation", 145, 137) {
  *this = shrubbery;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & shrubbery) {
  if (this != &shrubbery) {
    this->target = shrubbery.target;
  }
  return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137) {
  this->target = target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
  if (!this->getIsSigned() || executor.getGrade() > this->getExecGrade())
    throw ShrubberyCreationForm::GradeTooLowException();
  std::ofstream file;
  std::string filename = this->target;
  filename.append("_shrubbery");
  file.open(filename);
  std::string tree[7] = {
    "    /\\    ",
    "   /  \\   ",
    "  /____\\  ",
    "    /\\    ",
    "   /  \\   ",
    "  /____\\  ",
    "    ||    "
  };
  int i = 0;
  while (i < 7) {
    file << tree[i] << std::endl;;
    i++;
  }
}
