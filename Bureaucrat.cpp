/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:40:03 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/17 13:08:12 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(32)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string &name, unsigned int grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &copy) {
        this->_grade = copy._grade;
    }
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
    return (_grade);
}

/*
* this function must be a non-member one, because in C++, the left-hand operand
of a member operator function must be an instance of the class it belongs to.
This weird sentence means that if `operator<<()` would have been a member function,
the syntax to use would be `Fixed << std::cout;`, but we want to implement the
standard `std::cout << Fixed;`

In general, the `operator<<()` function takes two arguments: 
 - `std::ostream &output` representing the left-hand operand, the stream
 - `const YourClass &object` representing the right-hand operand, the object to 
 print
*/
std::ostream &operator<<(std::ostream &output, Bureaucrat const &b)
{
    output << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (output);
}