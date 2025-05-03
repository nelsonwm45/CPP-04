#include "AAnimal.hpp"

// Default Constructor
AAnimal::AAnimal(void):
	_type("General")
{
	std::cout << BLUE << "[AAnimal] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << BLUE << "[AAnimal] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// String Constructor
AAnimal::AAnimal(std::string p_type):
	_type(p_type)
{
	std::cout << BLUE << "[AAnimal] " << GREEN << "String constructor called\n" << RESET;
	std::cout << BLUE << "[AAnimal] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Constructor
AAnimal::AAnimal(const AAnimal &other):
	_type(other._type)
{
	std::cout << BLUE << "[AAnimal] " << GREEN << "Copy construtor called\n" << RESET;
	std::cout << BLUE << "[AAnimal] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Assignment Operator
AAnimal	&AAnimal::operator=(const AAnimal &other)
{
	std::cout << BLUE << "[AAnimal] " << GREEN << "Copy assignment operator called\n" << RESET;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

// Destructor
AAnimal::~AAnimal(void)
{
	std::cout << BLUE << "[AAnimal] " << GREEN << "Destructor called\n" << RESET;
}
/*
	Have to remove this because it will cause linker error
	Creating a pure virtual function does not need implementation
*/

// void	AAnimal::makeSound(void) const
// {
// 	std::cout << BLUE << "[AAnimal] " << GREEN << "Some general animal's noise~~~~~~\n" << RESET;
// }

// Setters
void	AAnimal::setType(std::string	p_type)
{
	this->_type = p_type;
}

// Getters
std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

std::ostream	&operator<<(std::ostream &output, const AAnimal &other)
{
	output << other.getType();
	return (output);
}