/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:40:58 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/16 15:59:31 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Data.hpp"
#include "../lib/Serializer.hpp"

int main ()
{
	Data		*ptr = new Data ("Hi, how's going");
	Data		*new_ptr;
	uintptr_t	raw;

	raw = Serializer::serialize(ptr);
	new_ptr = Serializer::deserialize(raw);
	std::cout << "new_ptr->cast = " << *new_ptr << std::endl;
	
	return (0);
}