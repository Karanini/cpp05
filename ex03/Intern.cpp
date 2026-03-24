/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:34:21 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/24 15:34:25 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern(void)
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = copy;
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& copy)
{
    std::cout << "Intern assignment operator called" << std::endl;
    if (this != &copy) {
        // copy data members here
    }
    return (*this);
}