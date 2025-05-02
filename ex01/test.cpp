#include "Helper.hpp"

void	animal_ocf_test(void)
{
	std::cout << YELLOW << "----------ANIMAL OCF TEST----------\n" << RESET;
	Animal	a1;
	Animal	a2(a1);
	Animal	a3;

	a3 = a2;
	std::cout << BLUE << "a3: " << a3.getType() << RESET << std::endl;
}

void	cat_ocf_test(void)
{
	std::cout << YELLOW << "----------CAT OCF TEST----------\n" << RESET;
	Cat	c1;
	Cat	c2(c1);
	Cat	c3;

	c3 = c2;
	std::cout << BLUE << "c3: " << c3.getType() << RESET << std::endl;
}

void	dog_ocf_test(void)
{
	std::cout << YELLOW << "----------DOG OCF TEST----------\n" << RESET;
	Dog	d1;
	Dog	d2(d1);
	Dog	d3;

	d3 = d2;
	std::cout << BLUE << "d3: " << d3.getType() << RESET << std::endl;
}

void	setter_test(void)
{
	std::cout << YELLOW << "----------SETTER TEST----------\n" << RESET;
	Animal	a1;

	a1.setType("General_UwU");
	std::cout << BLUE << "a1: " << a1.getType() << RESET << std::endl;

	Cat	c1;
	c1.setType("Cat_UwU");
	std::cout << BLUE << "c1: " << c1.getType() << RESET << std::endl;
	
	Dog	d1;
	d1.setType("Dog_UwU");
	std::cout << BLUE << "d1: " << d1.getType() << RESET << std::endl;
}

void	animal_makeSound(void)
{
	std::cout << YELLOW << "----------ANIMAL MAKESOUND TEST----------\n" << RESET;
	Animal	a1;

	a1.makeSound();
}

void	cat_makeSound(void)
{
	std::cout << YELLOW << "----------CAT MAKESOUND TEST----------\n" << RESET;
	Cat	c1;

	c1.makeSound();
}

void	dog_makeSound(void)
{
	std::cout << YELLOW << "----------DOG MAKESOUND TEST----------\n" << RESET;
	Dog	d1;

	d1.makeSound();
}

void	animal_pointer(void)
{
	std::cout << YELLOW << "----------ANIMAL POINTER TEST----------\n" << RESET;
	Animal	*a1 = new Animal;
	a1->makeSound();
	delete a1;

	a1 = new Cat;
	a1->makeSound();
	delete a1;

	a1 = new Dog;
	a1->makeSound();
	delete a1;
}

/*
	A Derived class Pointer cannot point back to Base class
	Base class is a derived class, but an derived class is not necessarily to be base class
	Cat is an animal, but animal is not necessary to be a cat

	The following is WRONG ~~
	Cat	*c1 = new Animal;
	c1->makeSound();
	delete c1;

	Derived class cannot point to each other because they are unrelatable
	This also WRONG ~~~
	c1 = new Dog;
	c1->makeSound();
*/
void	cat_pointer(void)
{
	std::cout << YELLOW << "----------CAT POINTER TEST----------\n" << RESET;
	Cat	*c1;

	c1 = new Cat;
	c1->makeSound();
	delete c1;
}

void	dog_pointer(void)
{
	std::cout << YELLOW << "----------DOG POINTER TEST----------\n" << RESET;
	Dog	*d1;

	d1 = new Dog;
	d1->makeSound();
	delete d1;
}

void	from_pdf(void)
{
	std::cout << YELLOW << "----------FROM PDF EX00 TEST----------\n" << RESET;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl; // Dog
	std::cout << i->getType() << " " << std::endl; // Cat
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete i; // Delete Cat
	delete j; // Delete Dog
	delete meta; // Delete Animal
}

void	brain_pdf_test(void)
{
	std::cout << YELLOW << "----------FROM PDF EX01 TEST----------\n" << RESET;
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; //should not create a leak
	delete i;
}
