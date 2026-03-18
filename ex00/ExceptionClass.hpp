/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExceptionClass.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:40:27 by michel_32         #+#    #+#             */
/*   Updated: 2026/03/18 11:46:09 by michel_32        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class ExceptionClass
{
private:
    std::string _name;
public:
    ExceptionClass(std::string &name);
    const std::string &getError() const;
};