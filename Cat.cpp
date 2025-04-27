#include "Cat.hpp"

// Default Constructor
Cat::Cat(void):
	_type("Cat")
{
	std::cout << MAGENTA << "[Cat] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << MAGENTA << "[Cat] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat &other):
	_type(other._type)
{
	std::cout << MAGENTA << "[Cat] " << GREEN << "Copy construtor called\n" << RESET;
	std::cout << MAGENTA << "[Cat] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Assignment Operator
Cat	&Cat::operator=(const Cat &other)
{
	if (this != other)
		this->_type = other._type;
		std::cout << MAGENTA << "[Cat] " << GREEN << "Copy assignment operator called\n" << RESET;
	return (*this);
}

// Destructor
Cat::~Cat(void)
{
	std::cout << MAGENTA << "[Cat] " << GREEN << "Destructor called\n" << RESET;
}

void	Cat::makeSound(void)
{
	std::cout << MAGENTA << "[Cat] " << GREEN << "Meow~~~~~~\n" << RESET;
}
