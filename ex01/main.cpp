/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:34:52 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/22 14:53:02 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void printHeader(std::string title)
{
    std::cout << "\n--- " << title << " ---" << std::endl;
}

int main(void)
{
    printHeader("Bureaucrat tests (ex00)");
    try
    {
        Bureaucrat irving("Irving", 32);
        std::cout << irving << std::endl;
        irving.incrementGrade();
        std::cout << "After increment: " << irving << std::endl;
        irving.decrementGrade();
        std::cout << "After decrement: " << irving << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        printHeader("Invalid Bureaucrat (too low)");
        Bureaucrat tooLow("TooLow", 151);
    }
    catch (std::exception &e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    try
    {
        printHeader("Invalid Bureaucrat (too high)");
        Bureaucrat tooHigh("TooHigh", 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    printHeader("Form Tests (ex01)");
    try
    {
        printHeader("Form creation and insertion operator");
        Form f1("A32", 45, 30);
        std::cout << f1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        printHeader("Form creation invalid grades (too low)");
        Form fLow("LowForm", 151, 150);
    }
    catch (std::exception &e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    try
    {
        printHeader("Form creation invalid grades (too high)");
        Form fHigh("HighForm", 1, 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    printHeader("Signing Tests");
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        Form important("Important Form", 10, 10);
        Form easy("Easy Form", 150, 150);

        std::cout << important << "\n" << std::endl;
        
        printHeader("Intern tries to sign important form (Should fail)");
        intern.signForm(important);
        
        printHeader("Boss tries to sign important form (Should succeed)");
        boss.signForm(important);
        std::cout << important << std::endl;

        printHeader("Intern tries to sign easy form (Should succeed)");
        intern.signForm(easy);
        std::cout << easy << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    printHeader("Form beSigned() directly");
    try
    {
        Bureaucrat mid("Mid", 75);
        Form f75("Form75", 75, 75);
        Form f74("Form74", 74, 74);

        std::cout << "Mid grade 75, Form75 sign grade 75" << std::endl;
        f75.beSigned(mid);
        std::cout << "Success: " << (f75.getSigned() ? "Signed" : "Not signed") << std::endl;

        std::cout << "Mid grade 75, Form74 sign grade 74" << std::endl;
        f74.beSigned(mid);
    }
    catch (std::exception &e)
    {
        std::cout << "Expected exception from beSigned: " << e.what() << std::endl;
    }

    return (0);
}