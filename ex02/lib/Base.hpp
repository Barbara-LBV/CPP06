/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:41:15 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/17 15:34:21 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define BOLD "\001\033[1;89m\002"

class Base
{
	public:
		virtual ~Base();
};

Base 	*generate(void);
void 	identify(Base& p);
void 	identify(Base* p);

#endif

/*

DYNAMIC CAST

A lieu a l'execution et non a la compilation !!
Il faut donc implementer son code de telle facon que le prog puisse detecter un bug eventuel du cast a l'execution.
Ne fonctionne qu'en polyformisme par sous-type -> methode virtual.
ne fonctionne que sur pointeur ou reference
syntaxe pointeur = dynamic_cast<type *>(param);

syntaxe ref = dynamic_cast<type &>(*param);
try and catch avec exception std::badcast car la reference ne pas etre NULL, cela permet d'eviter cela. 

*/