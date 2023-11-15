/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:06:58 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 18:06:59 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP


#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
  private : 
    const std::string name;
    bool isSigned;
    const int grade;
    const int execGrade;
  public :
    AForm();
    AForm(const AForm & form);
    ~AForm();
    AForm & operator=(const AForm & form);

    AForm(std::string name, int grade, int execGrade);
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
    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream & operator<<(std::ostream & os, AForm &  form);

#endif