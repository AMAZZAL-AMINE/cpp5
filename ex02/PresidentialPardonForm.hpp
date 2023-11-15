/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:03:00 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 18:03:01 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "main.h"

class PresidentialPardonForm : public AForm {
  private : 
    std::string target;
  public :
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm & shrubbery);
    ~PresidentialPardonForm();
    PresidentialPardonForm & operator=(const PresidentialPardonForm & shrubbery);

    PresidentialPardonForm(std::string target);
    void execute(Bureaucrat const & executor) const;

    class GradeTooLowException :  public std::exception {
      char const *what() const throw() {
        return "Error in SPresidential PardonForm :  exception : faild to execute";
      }
    };
};

#endif