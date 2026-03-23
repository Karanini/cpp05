/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:21:34 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/23 17:36:20 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("Shrubbery Creation", 145, 137), _target(target)
{
    std::cout << "AForm parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

/*
Copying only the `_signed` state as other attributes are `const` 
*/
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &copy) {
        this->AForm::operator=(copy);
    }
    return (*this);
}

const char* ShrubberyCreationForm::FileOpeningException::what() const throw()
{
    return "ShrubberyCreationForm: Error opening or creating file.";
}

/*
Creates a file <target>_shrubbery in the working directory and writes ASCII trees
inside it.
*/
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->AForm::execute(executor);

	std::string		filename = this->_target + "_shrubbery";
	std::ofstream	ofs(filename.c_str());
	if (!ofs.is_open())
        throw FileOpeningException();
	else
	{
		std::cout << "I will now draw a nice ASCII tree :)" << std::endl;
	}    
}
