#include "Dog.hpp"

// Default Constructor
Dog::Dog(void):
	Animal("Dog"), _brain(new Brain)
{
	std::cout << YELLOW << "[Dog] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << YELLOW << "[Dog] " << GREEN << _type << " is constructed" << RESET << std::endl;
	std::cout << MAGENTA << "[Dog] " << GREEN << "Brain address: " << _brain << RESET << std::endl;
}

/*
	For Copy Constructor and Copy Assignment Operator
	We cant simply this->brain = other._brain as it is shallow copy
	shallow copy will cause two objects point to same "Brain" memory address
	so deep copy is good to let only one object to one "Brain" memory address
*/
// Copy Constructor
Dog::Dog(const Dog &other):
	Animal(other._type)
{
	std::cout << YELLOW << "[Dog] " << GREEN << "Copy construtor called\n" << RESET;
	std::cout << YELLOW << "[Dog] " << GREEN << _type << " is constructed" << RESET << std::endl;
	this->_brain = new Brain(*other._brain); // using deep copy
	std::cout << MAGENTA << "[Dog] " << GREEN << "Brain address: " << _brain << RESET << std::endl;
}

// Copy Assignment Operator
Dog	&Dog::operator=(const Dog &other)
{
	std::cout << YELLOW << "[Dog] " << GREEN << "Copy assignment operator called\n" << RESET;
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain; // delete old address
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

// Destructor
Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << YELLOW << "[Dog] " << GREEN << "Destructor called\n" << RESET;
}

void	Dog::makeSound(void) const
{
	std::cout << YELLOW << "[Dog] " << GREEN << "Bark~~~~~~\n" << RESET;
}

void	Dog::setIdeas(std::string p_ideas, size_t p_index)
{
	this->setIdeas(p_ideas, p_index);
}

std::string	Dog::getIdeas(size_t p_index) const
{
	return (this->getIdeas(p_index));
}

std::ostream	&operator<<(std::ostream &output, const Dog &other)
{
	output << other.getType();
	return (output);
}
