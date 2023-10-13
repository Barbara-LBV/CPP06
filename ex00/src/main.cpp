/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:24:49 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/13 18:51:09 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ScalarConvert.hpp"

std::string ScalarConvert::_toChar = "";
int ScalarConvert::_toInt = 0;
float ScalarConvert::_toFloat = 0;
double ScalarConvert::_toDouble = 0;

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			ScalarConvert::convert(av[1]);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Usage: ./convert <value>" << std::endl;
	return (0);
}

//int main() 
//{
//    int myInt;
//    double myDouble;
//    float myFloat;
//    const char* myString = "42.2f";

//    myInt = atoi(myString);
//    myDouble = std::stod(myString);
//    myFloat = std::stof(myString);
//    std::cout << "myInt: " << myInt << std::endl;
//    std::cout << "myDouble: " << myDouble << std::endl;
//    std::cout << "myFloat: " << myFloat << "f" << std::endl;

//    return 0;
//}