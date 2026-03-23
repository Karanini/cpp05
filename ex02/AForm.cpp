/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:23:13 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/23 14:22:33 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm(void) : _name("default"), _signed(false), _gradeToSign(32), _gradeToExecute(32)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute) 
    : _name(name), 
      _signed(false),
      _gradeToSign(gradeToSign < 1 ? throw AForm::GradeTooHighException() : 
                   gradeToSign > 150 ? throw AForm::GradeTooLowException() : gradeToSign),
      _gradeToExecute(gradeToExecute < 1 ? throw AForm::GradeTooHighException() : 
                      gradeToExecute > 150 ? throw AForm::GradeTooLowException() : gradeToExecute)
{
    std::cout << "AForm parameterized constructor called" << std::endl;
}


AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), 
    _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm(void)
{
    std::cout << "AForm destructor called" << std::endl;
}

/*
Copying only the `_signed` state as other attributes are `const` 
*/
AForm& AForm::operator=(const AForm& copy)
{
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &copy) {
        this->_signed = copy._signed;
    }
    return (*this);
}

std::string  AForm::getName(void) const
{
    return (this->_name);
}

bool         AForm::getSigned(void) const
{
    return (this->_signed);
}

unsigned int AForm::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

unsigned int AForm::getGradeToExecute(void) const
{
    return (this->_gradeToExecute);
}

void    AForm::beSigned(Bureaucrat &Otis)
{
    if (Otis.getGrade() <= this->getGradeToSign())
        this->_signed = true;
    else
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat's grade too high exception!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat's grade too low exception!");
}

std::ostream &operator<<(std::ostream &output, AForm const &f)
{
    output << "AForm name: " << f.getName() << "\n"
           << "Signed: " << (f.getSigned() ? "yes" : "no") << "\n"
           << "Grade to sign: " << f.getGradeToSign() << "\n"
           << "Grade to execute: " << f.getGradeToExecute();
    return (output);
}
