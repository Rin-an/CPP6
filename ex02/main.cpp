/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 06:09:03 by ssadiki           #+#    #+#             */
/*   Updated: 2023/01/01 18:08:33 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"
#include <cstdlib>
#include <time.h>

Base * generate(void)
{
	srand(time(NULL));
	int	rd = rand() % 3 + 1;
	
	switch (rd)
	{
		case 1 :
		{
			std::cout << "Class A was created!" << std::endl;
			return new A;
		}
		case 2 :
		{
			std::cout << "Class B was created!" << std::endl;
			return new B;
		}
		case 3 :
		{
			std::cout << "Class C was created!" << std::endl;
			return new C;
		}
		default:
		{
			std::cout << "Something went wrong" << std::endl;
			return (NULL);
		}
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Could not identify the class." << std::endl;
}

void identify(Base& p)
{
	try
	{
		 (void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast& bc)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast& bc)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch (std::bad_cast& bc)
			{
				std::cout << "Could not convert!" << std::endl;
			}
		}
	}
}

int	main()
{
	Base* ptr;
//	Base	bs;
//	B*		pb;
//	B		nb;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
/*
	pb = dynamic_cast<B*>(&bs);
	if (!pb)
		std::cout << "Error!" << std::endl;
	ptr = dynamic_cast<Base*> (&nb);
	if (!ptr)
		std::cout << "Error!" << std::endl;*/
	return (0);
}

