/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:03:32 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 18:03:33 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "main.h"

class AForm;
class Bureaucrat {
  private :
    const std::string name;
    int   grade;
  public :
    Bureaucrat();
    Bureaucrat(const Bureaucrat &);
    ~Bureaucrat();
    Bureaucrat & operator=(const Bureaucrat &);

    void executeForm(AForm const & form);
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
    void signForm(AForm & form) const;
};

std::ostream & operator<<(std::ostream & os, Bureaucrat & biro);

#endif

// I have two classes both defined in separate header files. Each file has a field that is type of other class. Now I included in header of each file the header of other file, but compiler is generating errors. What am i missing?