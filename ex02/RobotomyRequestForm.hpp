/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:03:05 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 18:03:06 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTMYREQUEST_HPP
#define ROBOTMYREQUEST_HPP

#include "main.h"

class RobotomyRequestForm : public AForm {
  private : 
    std::string target;
  public :
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm & shrubbery);
    ~RobotomyRequestForm();
    RobotomyRequestForm & operator=(const RobotomyRequestForm & shrubbery);

    RobotomyRequestForm(std::string target);
    void execute(Bureaucrat const & executor) const;
    class GradeTooLowException :  public std::exception {
      char const *what() const throw() {
        return "Error in  Robotomy Reques :  exception : faild to execute";
      }
    };
};

#endif