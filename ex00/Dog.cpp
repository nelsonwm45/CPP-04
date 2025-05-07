#include "Dog.hpp"

// Default Constructor
Dog::Dog(void):
	Animal("Dog")
{
	std::cout << YELLOW << "[Dog] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << YELLOW << "[Dog] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Constructor
Dog::Dog(const Dog &other):
	Animal(other._type)
{
	std::cout << YELLOW << "[Dog] " << GREEN << "Copy construtor called\n" << RESET;
	std::cout << YELLOW << "[Dog] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Assignment Operator
Dog	&Dog::operator=(const Dog &other)
{
	std::cout << YELLOW << "[Dog] " << GREEN << "Copy assignment operator called\n" << RESET;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

// Destructor
Dog::~Dog(void)
{
	std::cout << YELLOW << "[Dog] " << GREEN << "Destructor called\n" << RESET;
}

void	Dog::makeSound(void) const
{
	std::cout << YELLOW << "[Dog] " << GREEN << "Bark~~~~~~\n" << RESET;
}

std::ostream	&operator<<(std::ostream &output, const Dog &other)
{
	output << other.getType();
	return (output);
}
