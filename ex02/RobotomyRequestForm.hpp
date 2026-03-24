/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:00:00 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/24 13:14:35 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& copy);
    ~RobotomyRequestForm(void);

    RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);

    void execute(Bureaucrat const & executor) const;

private:
    std::string _target;
};

#endif
