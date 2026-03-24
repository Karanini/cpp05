/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:34:52 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/24 13:20:54 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void printHeader(std::string title)
{
    std::cout << "\n--- " << title << " ---" << std::endl;
}

int main(void)
{
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
    }

    {
        printHeader("RobotomyRequestForm Tests");
        
        try {
            Bureaucrat boss("Boss", 1);
            Bureaucrat midLevel("MidLevel", 50);
            RobotomyRequestForm robot("Bender");

            std::cout << robot << std::endl;

            printHeader("Sign Robotomy with MidLevel (Should fail sign grade 72)");
            // wait, 50 IS HIGHER than 72 (smaller number)
            // sign 72, exec 45
            // midLevel 50 should succeed to sign, but fail to execute
        } catch (std::exception &e) {}

        try {
            Bureaucrat boss("Boss", 1);
            Bureaucrat lowLevel("LowLevel", 100);
            RobotomyRequestForm robot("R2D2");

            printHeader("Sign Robotomy with LowLevel (Should fail sign grade 72)");
            robot.beSigned(lowLevel);
        } catch (std::exception &e) {
            std::cerr << "Expected failure: " << e.what() << std::endl;
        }

        try {
            Bureaucrat boss("Boss", 1);
            Bureaucrat midLevel("MidLevel", 50);
            RobotomyRequestForm robot("Wall-E");

            printHeader("Sign Robotomy with MidLevel (Should succeed grade 72)");
            midLevel.signForm(robot);

            printHeader("Execute Robotomy with MidLevel (Should fail exec grade 45)");
            midLevel.executeForm(robot);

            printHeader("Execute Robotomy with Boss (Should succeed - 50% chance)");
            boss.executeForm(robot);
            boss.executeForm(robot);
            boss.executeForm(robot);
            boss.executeForm(robot);
        } catch (std::exception &e) {
            std::cerr << "Unexpected exception: " << e.what() << std::endl;
        }
    }

    {
        printHeader("PresidentialPardonForm Tests");
        
        try {
            Bureaucrat boss("Boss", 1);
            Bureaucrat assistant("Assistant", 20);
            PresidentialPardonForm pardon("Arthur Dent");

            std::cout << pardon << std::endl;

            printHeader("Sign Pardon with Assistant (Should succeed sign grade 25)");
            assistant.signForm(pardon);

            printHeader("Execute Pardon with Assistant (Should fail exec grade 5)");
            assistant.executeForm(pardon);

            printHeader("Execute Pardon with Boss (Should succeed sign grade 5)");
            boss.executeForm(pardon);
        } catch (std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    {
        printHeader("OCF (Orthodox Canonical Form) Tests");

        Bureaucrat boss("Boss", 1);
        
        printHeader("ShrubberyCreationForm OCF");
        ShrubberyCreationForm s1("target1");
        s1.beSigned(boss);
        ShrubberyCreationForm s2(s1); // Copy constructor
        ShrubberyCreationForm s3;
        s3 = s1; // Assignment operator

        std::cout << "Original (s1): " << s1 << std::endl;
        std::cout << "Copy (s2): " << s2 << std::endl;
        std::cout << "Assigned (s3): " << s3 << std::endl;

        printHeader("RobotomyRequestForm OCF");
        RobotomyRequestForm r1("target2");
        r1.beSigned(boss);
        RobotomyRequestForm r2(r1);
        RobotomyRequestForm r3;
        r3 = r1;

        std::cout << "Original (r1): " << r1 << std::endl;
        std::cout << "Copy (r2): " << r2 << std::endl;
        std::cout << "Assigned (r3): " << r3 << std::endl;

        printHeader("PresidentialPardonForm OCF");
        PresidentialPardonForm p1("target3");
        p1.beSigned(boss);
        PresidentialPardonForm p2(p1);
        PresidentialPardonForm p3;
        p3 = p1;

        std::cout << "Original (p1): " << p1 << std::endl;
        std::cout << "Copy (p2): " << p2 << std::endl;
        std::cout << "Assigned (p3): " << p3 << std::endl;
    }

    printHeader("Global Unsigned execution test");
    try {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot2("Marvin");
        
        printHeader("Execute unsigned robotomy (Should fail)");
        boss.executeForm(robot2);
    } catch (std::exception &e) {
        std::cerr << "Expected Exception: " << e.what() << std::endl;
    }

    return (0);
}
