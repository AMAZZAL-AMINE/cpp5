/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:07:13 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 18:07:14 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main() {
  try
  {
    Bureaucrat bureaucrat("biro", 3);
    ShrubberyCreationForm shrubby("Shrubbery");
    RobotomyRequestForm robbot("robbot");
    PresidentialPardonForm presidential("presidential");
    robbot.beSigned(bureaucrat);
    shrubby.beSigned(bureaucrat);
    presidential.beSigned(bureaucrat);
    shrubby.execute(bureaucrat);
    robbot.execute(bureaucrat);
    presidential.execute(bureaucrat);
    ShrubberyCreationForm gg("gg");
    gg.beSigned(bureaucrat);
    bureaucrat.signForm(gg);
    Intern intern;
    AForm *form = intern.makeForm("robotomy request", "Bender");
    std::cout << "FORM NAME : " << form->getName() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
  return 0;
}
