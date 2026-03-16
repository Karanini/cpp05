/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:40:57 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/16 17:57:05 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
public:
    // ---------- Constructors / Destructor ----------

    Bureaucrat(void);
    Bureaucrat(const Bureaucrat& copy);
    ~Bureaucrat(void);

    // ---------- Overloading Operators Methods -------

    Bureaucrat& operator=(const Bureaucrat& copy);

    // ---------- Getter and Setter Methods ------------

    Bureaucrat getName() const;
    Bureaucrat getGrade() const;

    // ---------- Member Methods -----------------------

protected:
    // ---------- Protected Data Members ---------------------

private:
    // ---------- Private Data members -------------------------
};

// operator << overload
std::ostream &operator<<(std::ostream &output, Bureaucrat const &b);

#endif // BUREAUCRAT_HPP