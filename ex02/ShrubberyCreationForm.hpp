/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:21:47 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/23 14:21:57 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>

class ShrubberyCreationForm {
public:
    // ---------- Constructors / Destructor ----------

    ShrubberyCreationForm(void);
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    ~ShrubberyCreationForm(void);

    // ---------- Overloading Operators Methods -------

    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);

    // ---------- Getter and Setter Methods ------------

    // ---------- Member Methods -----------------------

protected:
    // ---------- Protected Data Members ---------------------

private:
    // ---------- Private Data members -------------------------
};

#endif // SHRUBBERYCREATIONFORM_HPP