#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << YELLOW << "[MateriaSource] " << GREEN << "Default constructor called\n" << RESET;
	for (size_t i = 0; i < 4; i++)
		this->_AMateria[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << YELLOW << "[MateriaSource] " << GREEN << "Copy constructor called\n" << RESET;
	for (size_t i = 0; i < 4; i++)
	{
		if (other._AMateria[i])
			this->_AMateria[i] = other._AMateria[i]->clone();
		else
			this->_AMateria[i] = NULL;
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << YELLOW << "[MateriaSource] " << GREEN << "Copy assignment operator called\n" << RESET;
	if (this != &other)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (this->_AMateria[i] && other._AMateria[i])
			{
				delete this->_AMateria[i];
				this->_AMateria[i] = other._AMateria[i]->clone();
			}
			else if (this->_AMateria[i] && other._AMateria[i] == NULL)
			{
				delete this->_AMateria[i];
				this->_AMateria[i] = NULL;
			}
			else if (this->_AMateria[i] == NULL && other._AMateria[i])
			{
				this->_AMateria[i] = other._AMateria[i]->clone();
			}
			else
			{
				this->_AMateria[i] = NULL;
			}
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	std::cout << YELLOW << "[MateriaSource] " << GREEN << "Default Destructor is called\n" << RESET;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_AMateria[i])
			delete this->_AMateria[i];
	}
}

void	MateriaSource::learnMateria(AMateria *m)
{
	std::cout << YELLOW << "[MateriaSource] " << GREEN << "learnMateria is called\n" << RESET;
	size_t	i = 0;

	for (i = 0; i < 4; i++)
	{
		if (this->_AMateria[i] == NULL)
		{
			this->_AMateria[i] = m;
			break;
		}
	}
	if (i == 4)
	{
		std::cout << YELLOW <<  "[MateriaSource] "
			<< "Reached the max limit of Materia learnings\n" << RESET;
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	std::cout << YELLOW << "[MateriaSource] " << GREEN << "createMateria is called\n" << RESET;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_AMateria[i] != NULL && this->_AMateria[i]->getType() == type) // add a NULL checker so that it won't crash if it contains ntg
		{
			std::cout << YELLOW << "[MateriaSource] " << GREEN << "Create another copy of "
				 << this->_AMateria[i]->getType() << RESET << std::endl;
			return (this->_AMateria[i]->clone());
		}
	}
	std::cout << YELLOW << "[MateriaSource] " << RED << "No Match Found!\n" << RESET;
	return (NULL);
}
