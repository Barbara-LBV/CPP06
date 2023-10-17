/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:41:30 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/17 17:53:08 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/C.hpp"

C::C() : Base()
{
	std::cout << YELLOW  "C constructor -> called" DEFAULT << std::endl;
	_cType = "I'm C class.";
}

C::~C()
{
	std::cout << YELLOW  "C destructor -> called" DEFAULT << std::endl;
}

std::ostream &operator<<(std::ostream &co, const C &c)
{
	co << c._cType;
	return (co);
}