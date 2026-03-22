/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:40:57 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/22 14:53:02 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form;

class Bureaucrat {
public:
    // ---------- Constructors / Destructor ----------

    Bureaucrat(void);
    Bureaucrat(std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat &copy);
    ~Bureaucrat(void);

    // ---------- Overloading Operators Methods -------

    Bureaucrat& operator=(const Bureaucrat &copy);

    // ---------- Getter and Setter Methods ------------

    std::string getName() const;
    unsigned int getGrade() const;

    // ---------- Member Methods -----------------------

    void incrementGrade();
    void decrementGrade();
    void signForm(Form &LaissezPassezRoseA32);

    // ---------- Exception classes -----------------------

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

protected:
    // ---------- Protected Data Members ---------------------

private:
    // ---------- Private Data members -------------------------
    std::string const   _name;
    unsigned int        _grade;
};

// operator << overload
std::ostream &operator<<(std::ostream &output, Bureaucrat const &b);

#endif // BUREAUCRAT_HPP