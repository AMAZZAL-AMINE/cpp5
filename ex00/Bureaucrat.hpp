/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:48:41 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 17:48:42 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "main.h"

class Bureaucrat {
  private :
    const std::string name;
    int   grade;
  public :
    Bureaucrat();
    Bureaucrat(const Bureaucrat &);
    ~Bureaucrat();
    Bureaucrat & operator=(const Bureaucrat &);

    Bureaucrat(std::string name, int grade);
    class GradeTooHighException : public std::exception {
      const char *what() const throw() {
        return "Error : GradeTooHighException";
      }
    };

    class GradeTooLowException : public std::exception {
      const char *what() const throw() {
        return "Error : GradeTooLowException";
      }
    };
    std::string getName() const;
    int getGrade() const;
    void gradeIncrement();
    void gradeDecrement();
};

std::ostream & operator<<(std::ostream & os, Bureaucrat & biro);

#endif