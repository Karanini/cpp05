/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:21:34 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/24 10:59:52 by michel_32        ###   ########.fr       */
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
    : AForm(copy)
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
        this->_target = copy._target;
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

    std::string     filename = this->_target + "_shrubbery";
    std::ofstream   ofs(filename.c_str());
    if (!ofs.is_open())
        throw FileOpeningException();

    ofs << "          *          " << std::endl;
    ofs << "         / \\         " << std::endl;
    ofs << "        / 3 \\        " << std::endl;
    ofs << "       /  2  \\       " << std::endl;
    ofs << "      /   *   \\      " << std::endl;
    ofs << "     / 1     0 \\     " << std::endl;
    ofs << "    /    *      \\    " << std::endl;
    ofs << "   /  4     5    \\   " << std::endl;
    ofs << "  /      *        \\  " << std::endl;
    ofs << " /  6        7     \\ " << std::endl;
    ofs << "/________*__________\\" << std::endl;
    ofs << "        |   |        " << std::endl;
    ofs << "        |___|        " << std::endl;
    ofs << std::endl;
    ofs << "   Merry 32 Christmas!  " << std::endl;
    
    ofs.close();
    std::cout << "Shrubbery created in " << filename << std::endl;
}
