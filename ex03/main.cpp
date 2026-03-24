/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:34:52 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/24 16:50:16 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ex02/Bureaucrat.hpp"
#include "../ex02/AForm.hpp"
#include "../ex02/ShrubberyCreationForm.hpp"
#include "../ex02/RobotomyRequestForm.hpp"
#include "../ex02/PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
    Intern michael = Intern();
    std::cout << "\n";
    AForm *robot = michael.makeForm("robotomy request", "Pont_des_Arts");
    std::cout << "\n";
    AForm *perfectForm = michael.makeForm("perfect form", "Paradise");
    std::cout << "\n";
    delete robot;
    (void)perfectForm;
    return (0);
}