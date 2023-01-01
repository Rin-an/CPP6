/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:26:10 by ssadiki           #+#    #+#             */
/*   Updated: 2023/01/01 05:52:49 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

void	print_ninf(std::string str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else
	{
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
}

void	print_float(float f)
{
	if (fmod(f,static_cast<int>(f)) == 0)
	{
		std::cout.precision(1);
		std::cout << std::fixed << "float: " << f << "f" <<  std::endl;
	}
	else
		std::cout << "float: " << f << "f" <<  std::endl;
}

void	print_double(double d)
{
	if (fmod(d,static_cast<int>(d)) == 0)
	{
		std::cout.precision(1);
		std::cout << std::fixed << "float: " << static_cast<float>(d) << "f" <<  std::endl;
	}
	else
		std::cout << "float: " << static_cast<float>(d) << "f" <<  std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Too many or too few arguments. Here is the usage: " << argv[0] << " <literal>" << std::endl;
	else {
		try{
			char				c;
			float				f;
			long				i;
			double				d;
			std::string	str = argv[1];

			if (str == "nan" || str == "nanf" || (str.find("inf") != std::string::npos))
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				print_ninf(str);
				return (0);
			}
			//CHAR CASE
			if (str.size() == 1)
			{
				if (isprint(str[0]) && !isdigit(str[0]))
				{
					c = str[0];
					std::cout << "char: '" << c << "'" << std::endl;
					std::cout << "int: " << static_cast<int>(c) << std::endl;
					print_double(c);
					std::cout << "double: " << static_cast<double>(c) << std::endl;
				}
				else
				{
					std::cout << "char: Non displayable" << std::endl;
					std::cout << "int: 0" << std::endl;
					std::cout << "float: 0.0f" << std::endl;
					std::cout << "double: 0.0" << std::endl;
				}
				return (0);
			}
			//DOUBLE CASE
			if (str.find(".") != std::string::npos && str.find(".") == str.rfind("."))
			{
				if (str[str.size() - 1] == 'f')
				{
					f = stof(str);	
					if (f)
					{
						std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
						std::cout << "int: " << static_cast<int>(f) << std::endl;
						print_float(f);
						std::cout << "double: " << static_cast<double>(f) << std::endl;
						return (0);
					}
				}
				d = stod(str);
				if (d)
				{
					std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
					std::cout << "int: " << static_cast<int>(d) << std::endl;
					print_double(d);
					std::cout << "double: " << d << std::endl;
					return (0);
				}
			}
			else if (str.find(".") != std::string::npos)
				throw ("Something is wrong with the provided literal");
			//INT CASE
			i = stol(str);
			if (i)
			{
				if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
					throw ("Limits error for int type");
				i = static_cast<int>(i);
				if (i >= 32 && i < 127)
					std::cout << "char: '" << static_cast<char>(i) << "'" <<  std::endl;
				else
					std::cout << "char: Non displayable" << std::endl;
				std::cout << "int: " << i << std::endl;
				print_double(i);
				std::cout << "double: " << static_cast<double>(i) << std::endl;
				return (0);
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (const char *msg)
		{
			std::cout << msg << std::endl;
		}
	}
	return (0);
}
