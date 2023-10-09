/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:14:27 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/09 17:06:28 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Use of static_cast */

#include "../lib/ScalarConvert.hpp"

ScalarConvert::ScalarConvert():
{
	std::cout << "Default constructor called" << std::endl;
};

ScalarConvert::ScalarConvert(std::string *nb):
{
	std::cout << "Parametric constructor called" << std::endl;
	_nb = nb;
};

ScalarConvert::~ScalarConvert()
{
	std::cout << "Destructor called" << std::endl;
};

ScalarConvert::ScalarConvert(ScalarConvert const &s)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = s;
}

ScalarConvert	ScalarConvert::&operator=(ScalarConvert const &s)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &s)
	{
		/**/
	}
	return (*this);
}

void	ScalarConvert::convert(std::string nb)
{
	
}

void	ScalarConvert::printChar(void)
{
	
}

void	ScalarConvert::printInt(void)
{
	
}

void	ScalarConvert::printDouble(void)
{
	
}

void	ScalarConvert::printFloat(void)
{
	
}