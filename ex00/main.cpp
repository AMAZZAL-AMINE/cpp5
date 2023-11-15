/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:48:47 by mamazzal          #+#    #+#             */
/*   Updated: 2023/11/14 17:49:54 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main() {
  try
  {
    Bureaucrat biro("amine", -1);
    biro.gradeIncrement();
    std::cout << biro;

    std::cout << "------ 1 =====\n";
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  std::cout << "------ 2 =====\n";
  
  return 0;
}