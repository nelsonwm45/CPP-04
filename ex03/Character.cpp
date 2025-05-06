#include "Character.hpp"

Character::Character(void):
	_name("General_Character")
{
	std::cout << MAGENTA << "[Character] " << GREEN << "Default constructor called\n" << RESET;
	// Assign ntg to each inventory since The inventory is empty at construction
	for (size_t	i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string p_name):
	_name(p_name)
{
	std::cout << MAGENTA << "[Character] " << GREEN << "String constructor called\n" << RESET;
	// Assign ntg to each inventory since The inventory is empty at construction
	for (size_t	i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

/*
	Need to use deep copy to duplicate two AMateria to equip
*/
Character::Character(const Character &other):
	_name(other._name)
{
	std::cout << MAGENTA << "[Character] " << GREEN << "Copy constructor called\n" << RESET;
	for (size_t i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone(); // clone of each AMateria will return a pointer to new derived object
		else
			this->_inventory[i] = NULL;
	}
}

/*
	Careful: It's a deep copy, so need to delete previous memory before reassign
*/
Character	&Character::operator=(const Character &other)
{
	std::cout << MAGENTA << "[Character] " << GREEN << "Copy assignment operator called\n" << RESET;
	if (this != &other)
	{
		_name = other._name;
		for (size_t i = 0; i < 4; i++)
		{
			if (this->_inventory[i] && other._inventory[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = other._inventory[i]->clone();
			}
			else if (this->_inventory[i] && other._inventory[i] == NULL)
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
			else if (this->_inventory[i] == NULL && other._inventory[i])
			{
				this->_inventory[i] = other._inventory[i]->clone();
			}
			else
			{
				this->_inventory[i] = NULL;
			}
		}
	}
	return (*this);
}

Character::~Character(void)
{
	std::cout << MAGENTA << "[Character] " << GREEN << "Default Destructor is called\n" << RESET;
	for (size_t	i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

std::string const	&Character::getName(void) const
{
	// std::cout << MAGENTA << "[Character] " << GREEN << "getName is called\n" << RESET;
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	// std::cout << MAGENTA << "[Character] " << GREEN << "equip is called\n" << RESET;
	if (!m)
	{
		std::cout << MAGENTA << "[Character] " << RED << this->_name 
				<< " cannot equip a null Materia" << RESET << std::endl;
		return;
	}
	size_t	i = 0;

	for (i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << MAGENTA << "[Character] " << GREEN << this->_name 
				<< " equips with " << m->getType() << RESET << std::endl;
			break;
		}
	}
	if (i == 4)
	{
		std::cout << MAGENTA <<  "[Character] " << GREEN << this->_name 
			<< " has full inventory\n" << RESET;
	}
}

void	Character::unequip(int idx)
{
	// std::cout << MAGENTA << "[Character] " << GREEN << "unequip is called\n" << RESET;

	if (idx < 0 || idx >= 4)
	{
		std::cout << MAGENTA << "[Character] " << RED << "Invalid Index\n" << RESET;
		return ;
	}
	if (this->_inventory[idx])
	{
		this->_inventory[idx] = NULL; // set the slot to ntg and not destroying the object
		std::cout << MAGENTA << "[Character] " << GREEN << this->_name 
				<< " unequips inventory slot " << idx << RESET << std::endl;
	}
	else
	{
		std::cout << MAGENTA << "[Character] " << GREEN << this->_name 
				<< " does not have anything equipped on this slot " << RESET << std::endl;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	// std::cout << MAGENTA << "[Character] " << GREEN << "use is called\n" << RESET;

	if (idx < 0 || idx >= 4)
	{
		std::cout << MAGENTA << "[Character] " << RED << "Invalid Index\n" << RESET;
		return ;
	}
	if (this->_inventory[idx])
	{
		_inventory[idx]->use(target);
	}
}
