/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:14:27 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/17 17:47:25 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ScalarConvert.hpp"

ScalarConvert::ScalarConvert()
{
	std::cout << "Default constructor -> called" << std::endl;
}

ScalarConvert::ScalarConvert(ScalarConvert const &s)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = s;
}

ScalarConvert	&ScalarConvert::operator=(ScalarConvert const &s)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &s)
	{
		*this = s;
	}
	return (*this);
}

ScalarConvert::~ScalarConvert()
{
	std::cout << "Destructor called" << std::endl;
}

void 	ScalarConvert::printData(int option, std::string nb)
{
	if (option != 0)
	{
		if (_toChar == "Non displayable")
			std::cout << BOLD "char: " DEFAULT << _toChar << std::endl;
		else
			std::cout << BOLD "char: " DEFAULT << "'" << _toChar << "'" << std::endl;
		std::cout << BOLD "int: " DEFAULT << _toInt << std::endl;
		std::cout <<  BOLD "double: " DEFAULT << _toDouble << std::endl;
		std::cout <<  BOLD "float: " DEFAULT << _toFloat << "f" << std::endl;
	}
	else if (option == 0)
	{
		std::cout << BOLD "char: " DEFAULT << "impossible" << std::endl;
		std::cout << BOLD "int: " DEFAULT << "impossible" << std::endl;
		if (nb == "nan" || nb == "nanf")
		{
			std::cout <<  BOLD "double: " DEFAULT << "nan" << std::endl;
			std::cout <<  BOLD "float: " DEFAULT << "nan" << "f" << std::endl;
		}
		else if (nb == "inf" || nb == "inff")
		{
			std::cout <<  BOLD "double: " DEFAULT << "inf" << std::endl;
			std::cout <<  BOLD "float: " DEFAULT << "inf" << "f" << std::endl;
		}
		else if (nb == "-inf" || nb == "-inff")
		{
			std::cout <<  BOLD "double: " DEFAULT << "-inf" << std::endl;
			std::cout <<  BOLD "float: " DEFAULT << "-inf" << "f" << std::endl;
		}
	}
}

void	ScalarConvert::fromChar(std::string nb)
{
	_toChar = nb[0];
	_toInt = static_cast<int>(_toChar[0]);
	_toDouble = static_cast<double>(_toInt);
	_toFloat = static_cast<float>(_toDouble);
}

void	ScalarConvert::fromInt(std::string nb)
{
	_toInt = atoi(nb.c_str());
	_toDouble = static_cast<double>(_toInt) + 0.0;
	_toFloat = static_cast<float>(_toInt);
	if (_toInt >= 32 && _toInt <= 126)
		_toChar = static_cast<char>(_toInt);
	else
		_toChar = "Non displayable";
}

void	ScalarConvert::fromDouble(std::string nb)
{
	_toDouble = strtod(nb.c_str(), NULL);
	_toFloat = static_cast<float>(_toDouble);
	_toInt = static_cast<int>(_toDouble);
	_toInt = roundf(_toFloat);
	if (_toDouble >= 32 && _toDouble <= 126)
		_toChar = static_cast<char>(_toFloat);
	else
		_toChar = "Non displayable";
}

void	ScalarConvert::fromFloat(std::string nb)
{
	_toFloat = strtod(nb.c_str(), NULL);
		_toDouble = static_cast<double>(_toFloat);
		_toInt = static_cast<int>(_toFloat);
		_toInt = roundf(_toFloat);
		if (_toFloat >= 32 && _toFloat <= 126)
			_toChar = static_cast<char>(_toFloat);
		else if (nb != "nan" || nb != "nanf" || nb != "inf" || nb != "inff" || nb != "-inff" || nb != "-inf")
			_toChar = "Non displayable";
}

int		ScalarConvert::findType(std::string nb)
{
	if (nb.size() == 1 && isprint(nb[0]) && !isdigit(nb[0]))
	{
		ScalarConvert::fromChar(nb);
		return (1);
	}
	if (nb.size() > 1)
	{
		int flag = 0;
		for (size_t i = 0; i < nb.size()-1 ; i++)
		{
			if (nb[i] == '.')
				flag++;
			if (!isdigit(nb[i]) && nb[i] != '.')
				return (5);
		}
		if (nb[nb.size()-1] != 'f')
			return (6);
		if (flag > 1)
			return (7);
	}
	if (nb[nb.length() - 1] == 'f')
	{
		ScalarConvert::fromFloat(nb);
		return (4);
	}
	for (size_t i = 0; i < nb.size(); i++)
	{
		if (nb[i] == '.')
		{
			ScalarConvert::fromDouble(nb);
			return (3);
		}
	}
	ScalarConvert::fromInt(nb);
	return (2);
}

void	ScalarConvert::convert(std::string nb)
{
	std::string special_lit[6] = {"inf", "-inf", "nan", "inff", "-inff", "nanf"};
	int i(0);
	int j(0);
	
	for ( ; j < 6; j++)
	{
		if (nb == special_lit[j])
			break ;
	}
	if (j == 6)
		i = ScalarConvert::findType(nb);
	switch(i)
	{
		case 0:
			ScalarConvert::printData(i, nb);
			break ;
		case 1:
			ScalarConvert::printData(i, nb);
			break ;
		case 2:
			ScalarConvert::printData(i, nb);
			break ;
		case 3:
			ScalarConvert::printData(i, nb);
			break ;
		case 4:
			ScalarConvert::printData(i, nb);
			break ;
		default:
			throw::ScalarConvert::ImpossibleConvert();
			break ;
	}
}
