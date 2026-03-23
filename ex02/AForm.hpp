/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:23:21 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/23 15:29:52 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class AForm {
public:
    // ---------- Constructors / Destructor ----------

    AForm(void);
    AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
    AForm(const AForm& copy);
    virtual ~AForm(void);

    // ---------- Overloading Operators Methods -------

    AForm& operator=(const AForm& copy);

    // ---------- Getter and Setter Methods ------------

    virtual std::string  getName(void) const = 0;
    bool         getSigned(void) const;
    unsigned int getGradeToSign(void) const;
    unsigned int getGradeToExecute(void) const;

    // ---------- Member Methods -----------------------

    void         execute(Bureaucrat const & executor) const;
    void         beSigned(Bureaucrat &Otis);

    // ---------- Exception classes -----------------------

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

protected:
    // ---------- Protected Data Members ---------------------

private:
    // ---------- Private Data members -------------------------
    const std::string _name;
    bool              _signed;
    const unsigned int  _gradeToSign;
    const unsigned int  _gradeToExecute;
};

// operator << overload
std::ostream &operator<<(std::ostream &output, AForm const &f);

#endif // AFORM_HPP