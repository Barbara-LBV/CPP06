/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:09:13 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/17 13:35:46 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <string>
# include <stdexcept>
# include <cstdlib>
#include <cmath>

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define BOLD "\001\033[1;89m\002"


class ScalarConvert
{
	public:
		~ScalarConvert();
		static void			convert(std::string nb);
		static void			printData(int option, std::string nb);
		static int			findType(std::string nb);
		static void			specLit(std::string nb);
		static void			fromChar(std::string nb);
		static void			fromInt(std::string nb);
		static void			fromDouble(std::string nb);
		static void			fromFloat(std::string nb);
		
		static std::string	_toChar;
		static int			_toInt;
		static double		_toDouble;
		static float		_toFloat;

	private:
		ScalarConvert();
		ScalarConvert(ScalarConvert const &s);
		ScalarConvert &operator=(ScalarConvert const &s);
	
	public:
		class ImpossibleConvert: public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return (RED "Input Impossible to Convert"  DEFAULT);
			}
		};
};

#endif

/*

notion du day = static_cast
	
permet de faire des convertions simple et de naviguer dans l'arbre d'heritage.
syntaxe -> static_cast<type>(param)   -> on veut convertir le param en le type entre chevrons.
Peut etre une demotion ou une promotion.
Meme prob cependant : autorise la compile de cast entre de classes filles d'un meme parent ...
avantage  de static_cast : il detecte quand on veut faire des cast entre des classes qui ne sont pas liees (pas dans un meme arbre d'heritage).
*/