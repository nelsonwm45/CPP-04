#include "Cat.hpp"

// Default Constructor
Cat::Cat(void):
	AAnimal("Cat"), _brain(new Brain)
{
	std::cout << MAGENTA << "[Cat] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << MAGENTA << "[Cat] " << GREEN << _type << " is constructed" << RESET << std::endl;
	std::cout << MAGENTA << "[Cat] " << GREEN << "Brain address: " << _brain << RESET << std::endl;
}
/*
	For Copy Constructor and Copy Assignment Operator
	We cant simply this->brain = other._brain as it is shallow copy
	shallow copy will cause two objects point to same "Brain" memory address
	so deep copy is good to let only one object to one "Brain" memory address

	1. Create a new memory address
	2. Use copy constructor of Brain class to copy the content of old memory address
	3. Assign it to _brain
*/

// Copy Constructor
Cat::Cat(const Cat &other):
	AAnimal(other._type)
{
	std::cout << MAGENTA << "[Cat] " << GREEN << "Copy construtor called\n" << RESET;
	std::cout << MAGENTA << "[Cat] " << GREEN << _type << " is constructed" << RESET << std::endl;
	this->_brain = new Brain(*other._brain); // using deep copy to create new memory address, refer above
	std::cout << MAGENTA << "[Cat] " << GREEN << "Brain address: " << _brain << RESET << std::endl;
}

// Copy Assignment Operator
Cat	&Cat::operator=(const Cat &other)
{
	std::cout << MAGENTA << "[Cat] " << GREEN << "Copy assignment operator called\n" << RESET;
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain; // we need to delete the previous memory address when we reassign, so won't leak
		this->_brain = new Brain(*other._brain); // using deep copy to create new memory address
	}
	return (*this);
}

// Destructor
// Since we involves dynamic memory allocation using new here, we must destroy the allocation when destruction time
Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << MAGENTA << "[Cat] " << GREEN << "Destructor called\n" << RESET;
}

void	Cat::makeSound(void) const
{
	std::cout << MAGENTA << "[Cat] " << GREEN << "Meow~~~~~~\n" << RESET;
}

/*
	Cat doesn’t inherit from Brain
	Cat cannot directly call Brain::setIdeas() or Brain::getIdeas() like this
	Instead, you should call these methods on the _brain pointer:
*/
void	Cat::setIdeas(std::string p_ideas, size_t p_index)
{
	this->_brain->setIdeas(p_ideas, p_index);
}

std::string	Cat::getIdeas(size_t p_index) const
{
	return (this->_brain->getIdeas(p_index));
}

std::ostream	&operator<<(std::ostream &output, const Cat &other)
{
	output << other.getType();
	return (output);
}
