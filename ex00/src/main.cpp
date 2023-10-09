/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:24:49 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/09 17:55:21 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ScalarConvert.hpp"

bool	parse_input(std::string *input)
{
	if ()
		
}


int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			Scalar scalar(argv[1]);
			std::cout << scalar;
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