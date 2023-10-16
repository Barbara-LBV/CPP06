/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:41:01 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/16 15:57:58 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Data.hpp"

Data::Data()
{
	std::cout << "Default constructor -> called" <<std::endl;
}

Data::Data(std::string cast)
{
	std::cout << "Overloaded constructor -> called" <<std::endl;
	_cast = cast;
}

Data::Data(Data const &s)
{
	std::cout << "Copy constructor -> called" <<std::endl;
	*this = s;
}

Data 	&Data::operator=(Data const &s)
{
	std::cout << "Assignment operator -> called" <<std::endl;
	if (this != &s)
		*this = s;
	return (*this);
}

Data::~Data()
{
	std::cout << "Destructor -> called" <<std::endl;
}

void	Data::setCast(int cast)
{
	_cast = cast;
}

std::string 	Data::getCast(void) const
{
	return (_cast);
}

std::ostream &operator<<(std::ostream &c, const Data &d)
{
	c << d.getCast();
	return (c);
}