/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:55:14 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 17:55:15 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP


#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
  private : 
    const std::string name;
    bool isSigned;
    const int grade;
    const int execGrade;
  public :
    Form();
    Form(const Form & form);
    ~Form();
    Form & operator=(const Form & form);

    Form(std::string name, int grade, int execGrade);
    std::string getName() const;
    int getGrade() const;
    int getExecGrade() const;
    bool getIsSigned() const;
    void beSigned(Bureaucrat & biro);
    class GradeTooHighException  : public std::exception {
      const char *what() const throw() {
        return "Error : GradeTooHighException";
      }
    };

    class GradeTooLowException  : public std::exception {
      const char *what() const throw() {
        return "Error : GradeTooLowException";
      }
    };
};

std::ostream & operator<<(std::ostream & os, Form &  form);

#endif