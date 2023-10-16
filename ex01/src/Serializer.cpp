/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:40:53 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/16 15:52:38 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default constructor -> called" <<std::endl;
}

Serializer::Serializer(Serializer const &s)
{
	std::cout << "Copy constructor -> called" <<std::endl;
	*this = s;
}

Serializer 	&Serializer::operator=(Serializer const &s)
{
	std::cout << "Assignment operator -> called" <<std::endl;
	if (this != &s)
		*this = s;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Destructor -> called" <<std::endl;
}

uintptr_t 	Serializer::serialize(Data* ptr)
{
	uintptr_t	raw;
	
	raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	Data	*d;

	d = reinterpret_cast<Data *>(raw);
	return (d);
}