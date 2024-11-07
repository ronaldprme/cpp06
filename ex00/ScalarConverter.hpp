/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:11:38 by rprocopi          #+#    #+#             */																																																																																																																																																																																																																																																																																																																																																																														
/*   Updated: 2024/11/07 16:15:35 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>

enum types
{
	INVALID,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &copy);
		~ScalarConverter(void);

		ScalarConverter &operator=(ScalarConverter const &src);

		static void printChar(const char c);
		static void printInt(const int nb);
		static void printFloat(const float nb);
		static void printDouble(const double nb);

		static char 	stoc(const std::string &str);
		static int 		stoi(const std::string &str);
		static float 	stof(const std::string &str);
		static double 	stod(const std::string &str);

	public:
		static void convert(std::string str);
};

bool isInt(const std::string str);
bool isDouble(const std::string str);
bool isFlout(const std::string str);

#endif