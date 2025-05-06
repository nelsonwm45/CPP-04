#include "Cure.hpp"

// Default Constructor
Cure::Cure(void):
	AMateria("cure")
{
	std::cout << MAGENTA << "[Cure] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << MAGENTA << "[Cure] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Constructor
Cure::Cure(const Cure &other):
	AMateria(other._type)
{
	std::cout << MAGENTA << "[Cure] " << GREEN << "Copy construtor called\n" << RESET;
	std::cout << MAGENTA << "[Cure] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Assignment Operator
Cure	&Cure::operator=(const Cure &other)
{
	std::cout << MAGENTA << "[Cure] " << GREEN << "Copy assignment operator called\n" << RESET;
	(void)other;
	return (*this);
}

// Destructor
Cure::~Cure(void)
{
	std::cout << MAGENTA << "[Cure] " << GREEN << "Destructor called\n" << RESET;
}

AMateria	*Cure::clone(void) const
{
	std::cout << MAGENTA << "[Cure] " << GREEN << "Clone function called\n" << RESET;
	return (new Cure);
}

void	Cure::use(ICharacter &target)
{
	std::cout << MAGENTA << "[Cure] " << GREEN << "Use function called\n" << RESET;
	std::cout << MAGENTA << "* heals " << target.getName() << "'s wounds *" 
		<< RESET << std::endl;
}

std::ostream	&operator<<(std::ostream &output, const Cure &other)
{
	output << other.getType();
	return (output);
}
