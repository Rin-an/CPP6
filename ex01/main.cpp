/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 05:53:14 by ssadiki           #+#    #+#             */
/*   Updated: 2023/01/01 06:03:58 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int	main()
{
	Data* 		d = new Data;
	uintptr_t	x;
	Data*		ptr;

	d->name = "dummy";
	d->age = 1000;
	std::cout << "Address= " << d << "\nName = " << d->name << "\nAge= " << d->age << std::endl;
	x = serialize(d);
	ptr = deserialize(x);
	std::cout << "Address= " << ptr << "\nName = " << ptr->name << "\nAge= " << ptr->age << std::endl;
	return (0);
}
