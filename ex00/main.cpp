/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:34:52 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/19 12:04:03 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string.h>
#include <iostream>

int main(void)
{
    try
    {
        // Bureaucrat Mark = Bureaucrat("Mark Scout", 160);
        // Bureaucrat Helly = Bureaucrat("Helly R.", 0);
        Bureaucrat Irving = Bureaucrat("Irving Bailiff", 32);
        std::cout << Irving << std::endl;
        Irving.decrementGrade();
        Irving.decrementGrade();
        std::cout << "Irving grade should be 34: " << Irving << std::endl;
        Irving.incrementGrade();
        Irving.incrementGrade();
        Irving.incrementGrade();
        Irving.incrementGrade();
        std::cout << "Irving grade should be 30: " << Irving << std::endl;

        //Grade too high exception on incrementation
        // Bureaucrat Seth = Bureaucrat("Seth Milchick", 1);
        // std::cout << Seth << std::endl;
        // Seth.incrementGrade();

        //Grade too low exception on decrementation
        Bureaucrat PoubelleDuParc = Bureaucrat("La Poubelle du Parc Astérix", 150);
        std::cout << PoubelleDuParc << std::endl;
        PoubelleDuParc.decrementGrade();

    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}