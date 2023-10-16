/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:41:06 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/16 15:58:07 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP	

#include <iostream>
#include <string>

class Data
{
	public:
		Data();
		Data(std::string cast);
		Data(Data const &s);
		Data &operator=(Data const &d);
		~Data();
		
		std::string getCast(void) const;
		void		setCast(int  cast);		

	private:
		std::string _cast;

};

std::ostream &operator<<(std::ostream &c, const Data &d);

#endif