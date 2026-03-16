/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:40:03 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/16 17:46:12 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = copy;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &copy) {
        // copy data members here
    }
    return (*this);
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
	// output << i.toFloat();
    output << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (output);
}