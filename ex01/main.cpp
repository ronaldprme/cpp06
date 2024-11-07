/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:10:50 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/07 19:32:09 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data ptr;

	ptr.name = "Ronald";
	ptr.lvl = 8;
	ptr.hp = 100;
	ptr.amor = 20;

	std::cout << "Address of ptf: "	<< &ptr << std::endl;
	std::cout << "Name: " << ptr.name << std::endl;
	std::cout << "Level: " << ptr.lvl << std::endl;
	std::cout << "Health Poin: " << ptr.hp << std::endl;
	std::cout << "Amor: " << ptr.amor << std::endl;
	
	uintptr_t a = Serializer::serializer(&ptr);
	std::cout << "\nUnsigned int: " << a << std::endl;
	
	Data *newptr = Serializer::deserializer(a);
	std::cout << "\nAnddress of newptr: " << newptr << std::endl;
	std::cout << "Name: " << newptr->name << std::endl;
	std::cout << "Level: " << newptr->lvl << std::endl;
	std::cout << "Health Point: " << newptr->hp << std::endl;
	return (0);
}

