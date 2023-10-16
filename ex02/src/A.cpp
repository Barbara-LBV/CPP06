/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:41:22 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/16 18:40:55 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/A.hpp"

A::A() : Base()
{
	std::cout << YELLOW  "A constructor -> called" DEFAULT << std::endl;
	_aType = "Je suis A";
}

A::~A()
{
	std::cout << YELLOW  "A destructor -> called" DEFAULT << std::endl;
}

std::ostream &operator<<(std::ostream &c, const A &a)
{
	c << a._aType;
	return (c);
}