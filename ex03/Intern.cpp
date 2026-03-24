/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:34:21 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/24 16:59:56 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "../ex02/PresidentialPardonForm.hpp"
#include "../ex02/RobotomyRequestForm.hpp"
#include "../ex02/ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}
form_code	Intern::hashit(std::string const &name)
{
	if (name == "shrubbery creation")
		return (eShrubbery);
	if (name == "robotomy request")
		return (eRobotomy);
	if (name == "presidential pardon")
		return (ePardon);
    return (eUndefined);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm	*form = NULL;

	switch (hashit(name))
	{
        case eShrubbery:
        {
            form = new ShrubberyCreationForm(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            break;
        }
        case eRobotomy:
        {
            form = new RobotomyRequestForm(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            break;
        }
        case ePardon:
        {
            form = new PresidentialPardonForm(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            break;
        }
        case eUndefined:
            std::cout << "Form name does not exist. Read the F*ck*ng 3200 pages bureaucracy manual it's not that complicated!" << std::endl;
	}
    return (form);
}
