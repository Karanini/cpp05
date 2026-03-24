/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:34:31 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/24 15:34:34 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class Intern {
public:
    // ---------- Constructors / Destructor ----------

    Intern(void);
    Intern(const Intern& copy);
    ~Intern(void);

    // ---------- Overloading Operators Methods -------

    Intern& operator=(const Intern& copy);

    // ---------- Getter and Setter Methods ------------

    // ---------- Member Methods -----------------------

protected:
    // ---------- Protected Data Members ---------------------

private:
    // ---------- Private Data members -------------------------
};

#endif // INTERN_HPP