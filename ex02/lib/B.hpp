/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:41:13 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/17 15:31:43 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base
{
	public:
		B();
		~B();
		std::string	_bType;
};

std::ostream &operator<<(std::ostream &c, const B &b);

#endif