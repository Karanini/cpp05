/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:34:31 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/24 16:57:46 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "../ex02/AForm.hpp"

enum form_code
{
    eShrubbery,
    eRobotomy,
    ePardon,
    eUndefined
};

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
    AForm *makeForm(std::string name, std::string target);

protected:
    // ---------- Protected Data Members ---------------------

private:
    // ---------- Private Data members -------------------------
    static form_code hashit(std::string const &name);
};

#endif // INTERN_HPP