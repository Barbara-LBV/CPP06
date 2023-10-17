/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:41:04 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/17 13:27:08 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* notion = reinterpret_cast*/

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP	
#define BOLD "\001\033[1;89m\002"
#define DEFAULT "\001\033[0;39m\002"

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	public:
		~Serializer();
		static uintptr_t 	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(Serializer const &s);
		Serializer 			&operator=(Serializer const &s);
};

#endif

/*
Reinterpret Cast

->permet de realiser des re-interpretation en plus des up et down cast.
le + permissif, le compilateur ne va pas faire de verification, par contre potentiel prob a l'exec.
 reinterpret_cast<type *>(param)
tres utilise pour le re-typage comme lorsqu'on recoit une donnee dont on ne connait pas le type, exemple variable void * pour 
recevoir une suite d'octet, on s'apercoit qu c'est un char, on peut avec reinterpret_cast retyper le void * en char pour interpreter correctement donnee recue.
*/