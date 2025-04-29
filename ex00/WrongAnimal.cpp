#include "Animal.hpp"

// Default Constructor
Animal::Animal(void):
	_type("General")
{
	std::cout << BLUE << "[Animal] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << BLUE << "[Animal] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// String Constructor
Animal::Animal(std::string p_type):
	_type(p_type)
{
	std::cout << BLUE << "[Animal] " << GREEN << "String constructor called\n" << RESET;
	std::cout << BLUE << "[Animal] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Constructor
Animal::Animal(const Animal &other):
	_type(other._type)
{
	std::cout << BLUE << "[Animal] " << GREEN << "Copy construtor called\n" << RESET;
	std::cout << BLUE << "[Animal] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Assignment Operator
Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		std::cout << BLUE << "[Animal] " << GREEN << "Copy assignment operator called\n" << RESET;
	}
	return (*this);
}

// Destructor
Animal::~Animal(void)
{
	std::cout << BLUE << "[Animal] " << GREEN << "Destructor called\n" << RESET;
}

void	Animal::makeSound(void) const
{
	std::cout << BLUE << "[Animal] " << GREEN << "Some general animal's noise~~~~~~\n" << RESET;
}

// Setters
void	Animal::setType(std::string	p_type)
{
	this->_type = p_type;
}

// Getters
std::string	Animal::getType(void) const
{
	return (this->_type);
}

std::ostream	&operator<<(std::ostream &output, const Animal &other)
{
	output << other.getType();
	return (output);
}