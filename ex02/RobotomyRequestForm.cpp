/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:00:00 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/24 13:16:43 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm("Robotomy Request", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    *this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &copy) {
        this->AForm::operator=(copy);
        this->_target = copy._target;
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    this->AForm::execute(executor);

    std::cout << "* Vrrrzzzzzz... drilling noises... *" << std::endl;
    
    // Seed randomization (only once is better, but this works for demonstration)
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(0));
        seeded = true;
    }

    if (std::rand() % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << this->_target << " failed." << std::endl;
    }
}
