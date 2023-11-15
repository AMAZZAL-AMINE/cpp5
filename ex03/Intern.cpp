/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:07:07 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 18:07:08 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Intern::Intern() {}
Intern::Intern(const Intern & __unused intern) {}
Intern::~Intern() {}
Intern & Intern::operator=(const Intern & __unused  intern) { return *this; }

AForm *Intern::makeForm(std::string name, std::string target) {
  std::string namesArr[] = {"presidential pardonForm", "robotomy request", "shrubbery creation"};
  int i = 0;
  int found = -1;
  while (i < 3) {
    if (namesArr[i] == name) {
      found = i;
      break;
    }
    i++;
  }

  switch (found)
  {
    case 0:
      std::cout << " Intern creates " << name << std::endl;
      return new PresidentialPardonForm(target);
    case 1:
      std::cout << "Intern creates " << name << std::endl;
      return new RobotomyRequestForm(target);
    case 2:
      std::cout << " Intern creates " << name << std::endl;
      return new ShrubberyCreationForm(target);
    default:
      break;
  }
  throw Intern::Error();
}
