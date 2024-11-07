/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:28:59 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/07 18:39:59 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy)
{
	if (this != &copy)
		return (*this);
	return (*this);
}

bool isInt(const std::string str)
{
	std::stringstream sstr(str);
	int a;
	
	sstr >> a;
	if (!sstr.fail() && sstr.eof())
		return (true);
	return (false);
}

bool isDouble(const std::string str)
{
	std::stringstream sstr(str);
	double a;
	
	sstr >> a;
	if (!sstr.fail() && sstr.eof())
		return (true);
	return (false);
}

bool isFlout(const std::string str)
{
	if (str.size()< 2){
		return (false);
	}
	if (str[str.size() -1] != 'f' && str[str.size() -1] != 'F'){
		return (false);
	} 
	std::istringstream iss(str.substr(0, str.size() -1));
	float f;
	return (iss >> f) && (iss.eof());
}

void pintDataType(types t)
{
	switch (t)
	{
		case INT: 	{std::cout << "input type found: INT" << std::endl; break;}
		case CHAR:	{std::cout << "input type found: CHAR" << std::endl; break;}
		case FLOAT:	{std::cout << "input type found: FLOAT" << std::endl; break;}
		case DOUBLE:{std::cout << "input type found: DOUBLE" << std::endl; break;}
		default:	break;
	}
}

int getType(std::string str)
{
	int type = 0;
	
	if (str.size() == 1 && !isdigit(str[0]))
		type = CHAR;
	else if (str == "-inff" || str == "+inff" || str == "nanf")
		type = FLOAT;
	else if (str == "-inf" || str == "+inf" || str == "nan")
		type = DOUBLE;
	else if (str.find('.') != std::string::npos)
	{
		if (isDouble(str))
			type = DOUBLE;
		else if (isFlout(str))
			type = FLOAT;
	}
	else if (isInt(str))
		type = INT;
	else
		type = INVALID;
	return (type);
}

void ScalarConverter::convert(std::string str)
{
	int type = getType(str);
	
	switch (type)
	{
		case INVALID:
			std::cout << "Invalid input!" << std::endl;
			break;
		case CHAR:
		{
			char c = stoc(str);
			printChar(c);
			printInt(static_cast<int>(c));
			printFloat(static_cast<float>(c));
			printDouble(static_cast<double>(c));
			break;
		}
		case INT:
		{
			int nb = stoi(str);
			printChar(static_cast<char>(nb));
			printInt(nb);
			printFloat(static_cast<float>(nb));
			printDouble(static_cast<double>(nb));
			break;
		}
		case FLOAT:
		{
			float nb = stof(str);
			printChar(static_cast<char>(nb));
			printInt(static_cast<int>(nb));
			printFloat(static_cast<float>(nb));
			printDouble(static_cast<double>(nb));
			break;
		}
		case DOUBLE:
		{
			double nb = stod(str);
			printChar(static_cast<char>(nb));
			printInt(static_cast<int>(nb));
			printFloat(static_cast<float>(nb));
			printDouble(nb);
			break;
		}

	}
}

void ScalarConverter::printChar(const char c)
{
	std::cout << "Char: ";
	if (c < 32 || c > 126)
		std::cout << "Non displayble";
	else
		std::cout << "'" << c << "'";
	std::cout << std::endl;
}

void ScalarConverter::printInt(const int nb)
{
	std::cout << "Int: ";
	std::cout << nb << std::endl;
}

void ScalarConverter::printFloat(const float nb)
{
	std::cout << "Float: ";
	std::cout << nb;
	if (nb != std::numeric_limits<float>::infinity() && nb != -std::numeric_limits<float>::infinity()
		&& (nb - floor(nb)) <= 0.0f)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(const double nb)
{
	std::cout << "Double: ";
	std::cout << nb;
	if (nb != std::numeric_limits<double>::infinity() && nb != -std::numeric_limits<double>::infinity()
		&& (nb - floor(nb)) <= 0.0f)
			std::cout << ".0";
	std::cout << std::endl;
}

char ScalarConverter::stoc(std::string const &str)
{
	std::istringstream sstr(str);
	char c;

	sstr >> c;
	if (str[0] == ' ')
		c = ' ';
	return (c);
}

int ScalarConverter::stoi(std::string const &str)
{
	std::istringstream sstr(str);
	int nb;
	
	sstr >> nb;
	return (nb);
}

float ScalarConverter::stof(std::string const &str)
{
	std::istringstream sstr(str);
	float nb;
	
	sstr >> nb;
	if (sstr.fail())
	{
		if (str == "+inff")
			nb = std::numeric_limits<float>::infinity();
		else if (str == "nanf")
			nb = -std::numeric_limits<float>::infinity();
		else if (str == "nanf")
			nb = std::numeric_limits<float>::quiet_NaN();
	}
	return (nb);
}

double ScalarConverter::stod(std::string const &str)
{
	std::istringstream sstr(str);
	double nb;

	sstr >> nb;
	if (sstr.fail())
	{
			if (str == "+inf")
				nb = std::numeric_limits<double>::infinity();
			else if (str == "-inf")
				nb = -std::numeric_limits<double>::infinity();
			else if (str == "nan")
				nb = std::numeric_limits<double>::quiet_NaN();
	}
	return (nb);
}
