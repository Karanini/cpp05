/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:40:03 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/22 14:56:58 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(32)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

//good practice to use init list for `_name` even if exception check afterwards. 
//more efficient
Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
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

void Bureaucrat::incrementGrade()
{
    if (this->getGrade() == 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->getGrade() == 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::signForm(Form &LaissezPassezRoseA32)
{
    try
    {
        LaissezPassezRoseA32.beSigned(*this);
        std::cout << this->getName() << " signed " << LaissezPassezRoseA32.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << LaissezPassezRoseA32.getName() << " because " << e.what() << "." << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high exception!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low exception!");
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