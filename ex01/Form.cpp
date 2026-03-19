/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:23:13 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/19 13:14:03 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form(void) : _name("default"), _signed(false), _gradeToSign(32), _gradeToExecute(32)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute) 
    : _name(name), 
      _signed(false),
      _gradeToSign(gradeToSign < 1 ? throw Form::GradeTooHighException() : 
                   gradeToSign > 150 ? throw Form::GradeTooLowException() : gradeToSign),
      _gradeToExecute(gradeToExecute < 1 ? throw Form::GradeTooHighException() : 
                      gradeToExecute > 150 ? throw Form::GradeTooLowException() : gradeToExecute)
{
    std::cout << "Form parameterized constructor called" << std::endl;
}


Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), 
    _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(void)
{
    std::cout << "Form destructor called" << std::endl;
}

/*
Copying only the `_signed` state as other attributes are `const` 
*/
Form& Form::operator=(const Form& copy)
{
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &copy) {
        this->_signed = copy._signed;
    }
    return (*this);
}

std::string  Form::getName(void) const
{
    return (this->_name);
}

bool         Form::getSigned(void) const
{
    return (this->_signed);
}

unsigned int Form::getGradeToSign(void) const
{
    return (this->_gradeToSign);
}

unsigned int Form::getGradeToExecute(void) const
{
    return (this->_gradeToExecute);
}

std::ostream &operator<<(std::ostream &output, Form const &f)
{
    output << "Form name: " << f.getName() << "\n"
           << "Signed: " << (f.getSigned() ? "yes" : "no") << "\n"
           << "Grade to sign: " << f.getGradeToSign() << "\n"
           << "Grade to execute: " << f.getGradeToExecute();
    return (output);
}
