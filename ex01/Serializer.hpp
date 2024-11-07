/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:59:52 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/07 19:31:21 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

typedef unsigned long uintptr_t;

typedef struct 
{
	std::string name;
	int lvl;
	float hp;
	float amor;
} Data;

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &copy);
		~Serializer();
	
	public:
		static uintptr_t serializer(Data *ptr);
		static Data *deserializer(uintptr_t raw);

		Serializer &operator=(Serializer const &copy); 

};
#endif