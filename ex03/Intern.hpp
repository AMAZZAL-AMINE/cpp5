/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:07:09 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 18:07:10 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "main.h"

class Intern {
  private : 

  public :
   Intern();
   Intern(const Intern & intern);
   ~Intern();
   Intern & operator=(const Intern & intern);
   AForm *makeForm(std::string, std::string);

   class Error : public std::exception {
    const char* what() const throw() {
      return "Intern Error : Name u provided was not found";
    }
   };
};

#endif