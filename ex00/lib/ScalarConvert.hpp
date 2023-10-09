/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:09:13 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/09 17:30:38 by blefebvr         ###   ########.fr       */
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
		void		printChar(void);
		void		printFloat(void);
		void		printDouble(void);
		void		printInt(void);

	private:
		ScalarConvert();
		int		_selectedType;
		char	_charScalar;
		int		_intScalar;
		float	_floatScalar;
		double	_doubleScalar;

		static const int noType = -1;
		static const int charType = 0;
		static const int intType = 1;
		static const int floatType = 2;
		static const int doubleType = 3;
	
	public:
		class Truc: public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return (MAGENTA ".........." DEFAULT);
			}
		};

		class Bitin: public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return (MAGENTA ".........."  DEFAULT);
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