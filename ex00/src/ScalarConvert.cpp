/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:14:27 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/13 18:57:12 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ScalarConvert.hpp"

ScalarConvert::ScalarConvert()
{}

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

//void	ScalarConvert::specLit(std::string nb)
//{
	
//}

//void	ScalarConvert::fromChar(std::string nb)
//{
	
//}

//void	ScalarConvert::fromInt(std::string nb)
//{
	
//}

//void	ScalarConvert::fromDouble(std::string nb)
//{
	
//}

//void	ScalarConvert::fromFloat(std::string nb)
//{
	
//}

int		ScalarConvert::findType(std::string nb)
{
	if (isprint(nb[1]) && !isdigit(nb[1]))
		return (5);
	if (!isdigit(nb[nb.length()-1]) && nb[nb.length()-1] != 'f')
		return (6);
	if (!isdigit(nb[nb.length()- 2]) && nb[nb.length()-1] == 'f')
		return (7);
	if (nb.size() == 1 && isprint(nb[0]) && !isdigit(nb[0]))
	{
		_toChar = nb[0];
		_toInt = static_cast<int>(_toChar[0]);
		_toDouble = static_cast<double>(_toInt);
		_toFloat = static_cast<float>(_toDouble);
		return (1);
	}
	if (nb[nb.length() - 1] == 'f')
	{
		_toFloat = strtod(nb.c_str(), NULL);
		_toDouble = static_cast<double>(_toFloat);
		_toInt = static_cast<int>(_toFloat);
		if (_toFloat >= 32 && _toFloat <= 126)
			_toChar = static_cast<char>(_toFloat);
		else if (nb != "nan" || nb != "nanf" || nb != "inf" || nb != "inff" || nb != "-inff" || nb != "-inf")
			_toChar = "Non displayable";
		return (4);
	}
	for (size_t i = 0; i < nb.size(); i++)
	{
		if (nb[i] == '.')
		{
			_toDouble = strtod(nb.c_str(), NULL);
			_toFloat = static_cast<float>(_toDouble);
			_toInt = static_cast<int>(_toDouble);
			if (_toDouble >= 32 && _toDouble <= 126)
				_toChar = static_cast<char>(_toFloat);
			else
				_toChar = "Non displayable";
			return (3);
		}
	}
	{
		_toInt = atoi(nb.c_str());
		_toDouble = static_cast<double>(_toInt) + 0.0;
		_toFloat = static_cast<float>(_toInt);
		if (_toInt >= 32 && _toInt <= 126)
			_toChar = static_cast<char>(_toInt);
		else
			_toChar = "Non displayable";
		return (2);
	}
	return (0);
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
			//ScalarConvert::specLit(nb);
			ScalarConvert::printData(i, nb);
			break ;
		case 1:
			//ScalarConvert::fromChar(nb);
			ScalarConvert::printData(i, nb);
			break ;
		case 2:
			//ScalarConvert::fromInt(nb);
			ScalarConvert::printData(i, nb);
			break ;
		case 3:
			//ScalarConvert::fromDouble(nb);
			ScalarConvert::printData(i, nb);
			break ;
		case 4:
			//ScalarConvert::fromFloat(nb);
			ScalarConvert::printData(i, nb);
			break ;
		default:
			throw::ScalarConvert::ImpossibleConvert();
			break ;
	}
}
	
	//if (option[i] == 1)
	//{
	//	_toChar = nb[0];
	//	_toInt = static_cast<int>(_toChar);
	//	_toDouble = static_cast<double>(_toInt);
	//	_toFloat = static_cast<float>(_toDouble);
	//	return ;
	//}
	//for (int i= 0; i < 4; i++)
	//{
		
	//}
	//if (nb.c_str() > "~" && nb != toChar)
	//	toChar = "Non Displayable";
	//if (nb.size() == 1 && isprint(nb[0]) && !isdigit(nb[0]))
	//{
	//	toChar = nb[0];
	//	toInt = static_cast<int>(toChar[0]);
	//	toDouble = static_cast<double>(toInt);
	//	toFloat = static_cast<float>(toDouble);
	//	return ;
	//}
	//if (nb.size() != 1 && isprint(nb[0]) && !isdigit(nb[0]))
	//{
	//	toChar = "impossible";
	//	//toInt = static_cast<char>(toChar[0]);
	//	//toDouble = static_cast<double>(toInt);
	//	//toFloat = static_cast<float>(toDouble);
	//	return ;
	//}
	//toInt = std::atoi(nb.c_str());
	
	//if (toInt > 126 || toInt < 32)
	//{
	//	toChar = "Non displayable";
	//	toDouble = static_cast<double>(toInt);
	//	toFloat = static_cast<float>(toDouble);
	//	return ;
	//}

	//if (toInt <= 126 && toInt >= 32)
	//{
	//	toChar = static_cast<char>(toInt);
	//	toDouble = static_cast<double>(toInt);
	//	toFloat = static_cast<float>(toDouble);
	//	return ;
	//}
	
	//if (nb[nb.size()-1] == 'f')
	//{
	//	toFloat = toInt + 0.0;
	//	toChar = static_cast<char>(toInt);
	//	toDouble = static_cast<double>(toInt);
	//	toFloat = static_cast<float>(toDouble);
	//}
	//if (nb[nb.size()-1] == 'f')
	//{
	//	toInt = stoi(nb);
	//	toChar = static_cast<char>(toInt);
	//	toDouble = static_cast<double>(toInt);
	//	toFloat = static_cast<float>(toDouble);
	//}


	
		/*std::string		_input;
		char			_charScalar;
		int				_intScalar;
		float			_floatScalar;
		double			_doubleScalar;
		enum scalarType {charType, intType, floatType, doubleType} _type;
		       ou
		static const int noType = -1;
		static const int charType = 0;
		static const int intType = 1;
		static const int floatType = 2;
		static const int doubleType = 3;*/