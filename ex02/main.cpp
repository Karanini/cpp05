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
#include "AForm.hpp"
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

    printHeader("AForm Tests (ex01)");
    try
    {
        printHeader("AForm creation and insertion operator");
        AForm f1("A32", 45, 30);
        std::cout << f1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        printHeader("AForm creation invalid grades (too low)");
        AForm fLow("LowAForm", 151, 150);
    }
    catch (std::exception &e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    try
    {
        printHeader("AForm creation invalid grades (too high)");
        AForm fHigh("HighAForm", 1, 0);
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
        AForm important("Important AForm", 10, 10);
        AForm easy("Easy AForm", 150, 150);

        std::cout << important << "\n" << std::endl;
        
        printHeader("Intern tries to sign important form (Should fail)");
        intern.signAForm(important);
        
        printHeader("Boss tries to sign important form (Should succeed)");
        boss.signAForm(important);
        std::cout << important << std::endl;

        printHeader("Intern tries to sign easy form (Should succeed)");
        intern.signAForm(easy);
        std::cout << easy << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    printHeader("AForm beSigned() directly");
    try
    {
        Bureaucrat mid("Mid", 75);
        AForm f75("AForm75", 75, 75);
        AForm f74("AForm74", 74, 74);

        std::cout << "Mid grade 75, AForm75 sign grade 75" << std::endl;
        f75.beSigned(mid);
        std::cout << "Success: " << (f75.getSigned() ? "Signed" : "Not signed") << std::endl;

        std::cout << "Mid grade 75, AForm74 sign grade 74" << std::endl;
        f74.beSigned(mid);
    }
    catch (std::exception &e)
    {
        std::cout << "Expected exception from beSigned: " << e.what() << std::endl;
    }

    return (0);
}