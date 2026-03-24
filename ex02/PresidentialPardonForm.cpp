/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:00:00 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/24 15:00:00 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon", 25, 5), _target("default")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm("Presidential Pardon", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &copy) {
        this->AForm::operator=(copy);
        this->_target = copy._target;
    }
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    this->AForm::execute(executor);

    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
