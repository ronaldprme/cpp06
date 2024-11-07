/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:23:28 by rprocopi          #+#    #+#             */
/*   Updated: 2024/11/07 20:40:15 by rprocopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	Base *base;
	int n = rand() %3;
	switch (n)
	{
		case 0:
			base = new A();
			std::cout << "Base A randomly created!" << std::endl;
			break;
		case 1:
			base = new B();
			std::cout << "Base B randomly created!" << std::endl;
			break;
		case 2:
			base = new C();
			std::cout << "Base C randomly created!" << std::endl;
			break;
	}
	return (Base);
}

void identify(Base *p)
{
	std::cout << "Identify from pointer: ";
	try
	{
		if (dynamic_cast<A *>(p))
			std::cout << "A";
		else if (dynamic_cast<B *>(p))
			std::cout << "B";
		else if (dynamic_cast<C *>(p))
			std::cout << "C";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}

void identity (Base &p)
{
	std::cout << "Identify from reference: ";
	try
	{
		A& baseA = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)baseA;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		B& baseB = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)baseB;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		C& baseC = dynamic_cast<B &>(p);
		std::cout << "C" << std::endl;
		(void)BaseC;
	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}

int main(void)
{
	 td::srand(time(NULL));
    Base * base;

    base = generate();
    identify(base); // pointer
    identify(*base); // reference
    delete base;

    std::cout << std::endl;

    base = generate();
    identify(base); // pointer
    identify(*base); // reference
    delete base;

    std::cout << std::endl;

    base = generate();
    identify(base); // pointer
    identify(*base); // reference
    delete base;
	
	return (0);
}