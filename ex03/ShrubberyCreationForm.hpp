/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:07:31 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 18:07:32 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "main.h"

class ShrubberyCreationForm : public AForm {
  private : 
    std::string target;
  public :
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm & shrubbery);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm & operator=(const ShrubberyCreationForm & shrubbery);

    ShrubberyCreationForm(std::string target);
    void execute(Bureaucrat const & executor) const;
    class GradeTooLowException :  public std::exception {
      char const *what() const throw() {
        return "Error in Shrubbery Creation :  exception : faild to execute";
      }
    };
};

#endif