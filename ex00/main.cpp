/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:34:52 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/18 15:42:22 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string.h>
#include <iostream>

int main(void)
{
    try
    {
        Bureaucrat Wilfrid = Bureaucrat("Wilfrid", 160);
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "main catched a GradeTooLowException" << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "main catched a GradeTooHighException" << std::endl;
    }
    return (0);
}