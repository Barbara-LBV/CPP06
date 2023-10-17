/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:41:25 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/17 17:52:56 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/B.hpp"

B::B() : Base()
{
	std::cout << YELLOW  "B constructor -> called" DEFAULT << std::endl;
	_bType = "I'm B class.";
}

B::~B()
{
	std::cout << YELLOW  "B destructor -> called" DEFAULT << std::endl;
}

std::ostream &operator<<(std::ostream &c, const B &b)
{
	c << b._bType;
	return (c);
}