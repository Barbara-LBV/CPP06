/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:09:13 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/09 17:54:14 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <string>
# include <stdexcept>

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define MAGENTA "\001\033[1;95m\002"
# define BOLD "\001\033[1;89m\002"
# define GREEN "\001\033[1;92m\002"
# define BLUE "\001\033[1;36m\002"

class ScalarConvert
{
	public:
		ScalarConvert(std::string *nb);
		ScalarConvert(ScalarConvert const &s);
		~ScalarConvert();

		ScalarConvert &operator=(ScalarConvert const &s);

		static int	convert(std::string *nb);
		char		toChar(void)const;
		float		toFloat(void)const;
		double		toDouble(void)const;
		int			toInt(void)const;

	private:
		ScalarConvert();
		std::string		_input;
		char			_charScalar;
		int				_intScalar;
		float			_floatScalar;
		double			_doubleScalar;

		/*
		enum scalarType {charType, intType, floatType, doubleType} _type;
		       ou
		static const int noType = -1;
		static const int charType = 0;
		static const int intType = 1;
		static const int floatType = 2;
		static const int doubleType = 3;*/
	
	public:
		class InvalidInput: public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return (MAGENTA "Invalid Input" DEFAULT);
			}
		};

		class ImpossibleConvert: public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return (MAGENTA "Input Impossible to Convert"  DEFAULT);
			}
		};
		class NonDisplayable: public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return (MAGENTA "Input Non Displayable"  DEFAULT);
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

/*
nan = NotANumber
-inf = -infini negatif

*/