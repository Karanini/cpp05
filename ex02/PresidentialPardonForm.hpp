/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:00:00 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/24 13:16:46 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& copy);
    ~PresidentialPardonForm(void);

    PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);

    void execute(Bureaucrat const & executor) const;

private:
    std::string _target;
};

#endif
