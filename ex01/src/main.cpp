/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:40:58 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/17 13:23:06 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Data.hpp"
#include "../lib/Serializer.hpp"

int main()
{
	Data		*ptr = new Data();
	Data		*new_ptr;
	uintptr_t	raw;

	ptr->cast = "I'm a Data.";
	raw = Serializer::serialize(ptr);
	new_ptr = Serializer::deserialize(raw);
	std::cout << BOLD "ptr->cast = " DEFAULT << ptr->cast << std::endl;
	std::cout << BOLD "new_ptr->cast = " DEFAULT << new_ptr->cast << std::endl;
	delete ptr;
	
	return (0);
}