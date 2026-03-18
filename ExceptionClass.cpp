/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExceptionClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:40:44 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/18 11:47:27 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ExceptionClass.hpp"

ExceptionClass::ExceptionClass(std::string &name) : _name(name)
{

}

std::string const &ExceptionClass::getError() const
{
    return (this->_name);
}
