#include "AMateria.hpp"

// Default Constructor
AMateria::AMateria(void):
	_type("General")
{
	std::cout << BLUE << "[AMateria] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << BLUE << "[AMateria] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// String Constructor
AMateria::AMateria(std::string const p_type):
	_type(p_type)
{
	std::cout << BLUE << "[AMateria] " << GREEN << "String constructor called\n" << RESET;
	std::cout << BLUE << "[AMateria] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Constructor
AMateria::AMateria(const AMateria &other):
	_type(other._type)
{
	std::cout << BLUE << "[AMateria] " << GREEN << "Copy construtor called\n" << RESET;
	std::cout << BLUE << "[AMateria] " << GREEN << _type << " is constructed" << RESET << std::endl;
}

// Copy Assignment Operator
/*
	might not needed because it's const std::string, you can't reassign
*/
AMateria	&AMateria::operator=(const AMateria &other)
{
	std::cout << BLUE << "[AMateria] " << GREEN << "Copy assignment operator called\n" << RESET;
	// if (this != &other)
	// {
	// 	this->_type = other._type;
	// }
	(void)other;
	return (*this);
}

// Destructor
AMateria::~AMateria(void)
{
	std::cout << BLUE << "[AMateria] " << GREEN << "Destructor called\n" << RESET;
}

// Setters
// void	AMateria::setType(std::string const	p_type)
// {
// 	this->_type = p_type;
// }

// Getters
std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << BLUE << "[AMateria] " << GREEN << this->_type << " is so confused and used on "
		<< target.getName() << RESET << std::endl;
}
std::ostream	&operator<<(std::ostream &output, const AMateria &other)
{
	output << other.getType();
	return (output);
}