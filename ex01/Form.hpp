/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:23:21 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/19 13:11:52 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Form {
public:
    // ---------- Constructors / Destructor ----------

    Form(void);
    Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
    Form(const Form& copy);
    ~Form(void);

    // ---------- Overloading Operators Methods -------

    Form& operator=(const Form& copy);

    // ---------- Getter and Setter Methods ------------

    std::string  getName(void) const;
    bool         getSigned(void) const;
    unsigned int getGradeToSign(void) const;
    unsigned int getGradeToExecute(void) const;

    // ---------- Member Methods -----------------------

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
    const std::string _name;
    bool              _signed;
    const unsigned int  _gradeToSign;
    const unsigned int  _gradeToExecute;
};

// operator << overload
std::ostream &operator<<(std::ostream &output, Form const &f);

#endif // FORM_HPP