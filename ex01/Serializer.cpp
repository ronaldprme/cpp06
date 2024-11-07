/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:05:10 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/07 19:10:11 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	return ;
}

Serializer::Serializer(Serializer const &copy)
{
	*this = copy;
	return ;
}

Serializer::~Serializer()
{
	return ;
}

Serializer &Serializer::operator=(Serializer const &copy)
{
	if (this != &copy)
		return (*this);
	return (*this);
}

uintptr_t Serializer::serializer(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserializer(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}