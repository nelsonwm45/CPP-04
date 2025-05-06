#include "Ice.hpp"

// Default Constructor
Ice::Ice(void):
	AMateria("ice")
{
	std::cout << MAGENTA << "[Ice] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << MAGENTA << "[Ice] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Constructor
Ice::Ice(const Ice &other):
	AMateria(other._type)
{
	std::cout << MAGENTA << "[Ice] " << GREEN << "Copy construtor called\n" << RESET;
	std::cout << MAGENTA << "[Ice] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Assignment Operator
Ice	&Ice::operator=(const Ice &other)
{
	std::cout << MAGENTA << "[Ice] " << GREEN << "Copy assignment operator called\n" << RESET;
	(void)other;
	return (*this);
}

// Destructor
Ice::~Ice(void)
{
	std::cout << MAGENTA << "[Ice] " << GREEN << "Destructor called\n" << RESET;
}

AMateria	*Ice::clone(void) const
{
	std::cout << MAGENTA << "[Ice] " << GREEN << "Clone function called\n" << RESET;
	return (new Ice);
}

void	Ice::use(ICharacter &target)
{
	std::cout << MAGENTA << "[Ice] " << GREEN << "Use function called\n" << RESET;
	std::cout << MAGENTA << "* shoots an ice bolt at " << target.getName() << " *" 
		<< RESET << std::endl;
}
std::ostream	&operator<<(std::ostream &output, const Ice &other)
{
	output << other.getType();
	return (output);
}
