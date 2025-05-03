#include "Cat.hpp"

// Default Constructor
Cat::Cat(void):
	Animal("Cat")
{
	std::cout << MAGENTA << "[Cat] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << MAGENTA << "[Cat] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat &other):
	Animal(other._type)
{
	std::cout << MAGENTA << "[Cat] " << GREEN << "Copy construtor called\n" << RESET;
	std::cout << MAGENTA << "[Cat] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Assignment Operator
Cat	&Cat::operator=(const Cat &other)
{
	std::cout << MAGENTA << "[Cat] " << GREEN << "Copy assignment operator called\n" << RESET;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

// Destructor
Cat::~Cat(void)
{
	std::cout << MAGENTA << "[Cat] " << GREEN << "Destructor called\n" << RESET;
}

void	Cat::makeSound(void) const
{
	std::cout << MAGENTA << "[Cat] " << GREEN << "Meow~~~~~~\n" << RESET;
}

std::ostream	&operator<<(std::ostream &output, const Cat &other)
{
	output << other.getType();
	return (output);
}
