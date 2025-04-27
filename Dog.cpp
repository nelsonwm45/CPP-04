#include "Dog.hpp"

// Default Constructor
Dog::Dog(void):
	_type("Dog")
{
	std::cout << YELLOW << "[Dog] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << YELLOW << "[Dog] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Constructor
Dog::Dog(const Dog &other):
	_type(other._type)
{
	std::cout << YELLOW << "[Dog] " << GREEN << "Copy construtor called\n" << RESET;
	std::cout << YELLOW << "[Dog] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Assignment Operator
Dog	&Dog::operator=(const Dog &other)
{
	if (this != other)
		this->_type = other._type;
		std::cout << YELLOW << "[Dog] " << GREEN << "Copy assignment operator called\n" << RESET;
	return (*this);
}

// Destructor
Dog::~Dog(void)
{
	std::cout << YELLOW << "[Dog] " << GREEN << "Bark~~~~~~\n" << RESET;
}
