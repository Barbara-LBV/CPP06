/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:41:32 by blefebvr          #+#    #+#             */
/*   Updated: 2023/10/16 19:10:17 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base 	*generate(void)
{
	Base *p = NULL;
	int i = std::rand() % 3;
	
	switch (i)
	{
		case 0:
			p = new A();
			break;
		case 1:
			p = new B();
			break;
		case 2:
			p = new C();
			break;
		default:
			break;
	}
	return (p);
}

void 	identify(Base *p)
{
	if (!p)
	{
		std::cout << "The pointer in param is NULL." << std::endl;
		return ;
	}
	else
	{
		A 	*a = dynamic_cast<A *>(p);
		B	*b = dynamic_cast<B *>(p);
		C 	*c = dynamic_cast<C *>(p);
		
		if (a)
			std::cout << *a << std::endl;
		else if (b)
			std::cout << *b << std::endl;
		else if (c)
			std::cout << *c << std::endl;
		else
		{
			std::cout << "The conversion failed." << std::endl;
			return ;
		}
	}
}

void 	identify(Base &p)
{
	try 
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << a << std::endl;
	}
	catch(const std::bad_cast &e)
	{
		std::cerr << e.what() << '\n';
	}
	try 
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << b << std::endl;
	}
	catch(const std::bad_cast &e)
	{
		std::cerr << e.what() << '\n';
	}
	try 
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << c << std::endl;
	}
	catch(const std::bad_cast &e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	Base	*base;

	std::cout << BOLD "*** By pointers ***" DEFAULT << std::endl << std::endl;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	std::cout << std::endl << BOLD "*** By references ***" DEFAULT << std::endl
		<< std::endl;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	return (0);
}