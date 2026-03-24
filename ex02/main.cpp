/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:34:52 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/24 13:04:50 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void printHeader(std::string title)
{
    std::cout << "\n--- " << title << " ---" << std::endl;
}

int main(void)
{
    printHeader("ShrubberyCreationForm Tests");
    
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 148);
        ShrubberyCreationForm shrub("garden");

        std::cout << shrub << std::endl;

        printHeader("Sign Shrubbery with Intern (Should fail sign grade 145)");
        shrub.beSigned(intern);
    }
    catch (std::exception &e) {
        std::cerr << "Exception catch in main: " << e.what() << std::endl;
    }
    std::cout << "\n";
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 148);
        ShrubberyCreationForm shrub("garden");
        
        printHeader("Sign Shrubbery with Boss (Should succeed)");
        shrub.beSigned(boss);
        std::cout << shrub << std::endl;

        printHeader("Execute Shrubbery with Boss (Should succeed)");
        boss.executeForm(shrub);

        printHeader("Execute Shrubbery with Intern (Should fail exec grade 137)");
        intern.executeForm(shrub);

    } catch (std::exception &e) {
        std::cerr << "Exception catch in main: " << e.what() << std::endl;
    }

    printHeader("Shrubbery Unsigned execution test");
    try {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub2("parking");
        
        printHeader("Execute unsigned form (Should fail)");
        boss.executeForm(shrub2);
    } catch (std::exception &e) {
        std::cerr << "Expected Exception catch in main: " << e.what() << std::endl;
    }

    return (0);
}
