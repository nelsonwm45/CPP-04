#include "Brain.hpp"

// Default Constructor
// Since std::string's default constructor already set them to empty, so not actually needs to initialize them
Brain::Brain(void)
{
	std::cout << BLUE << "[Brain] " << GREEN << "Default constructor called\n" << RESET;
}

// Copy Constructor
Brain::Brain(const Brain &other)
{
	std::cout << BLUE << "[Brain] " << GREEN << "Copy construtor called\n" << RESET;
	for (size_t	i = 0; i < 100; i++)
	{
		this->_ideas[i] = other._ideas[i];
	}
}

// Copy Assignment Operator
Brain	&Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 100; i++)
		{
			this->_ideas[i] = other._ideas[i];
		}
	}
	std::cout << BLUE << "[Brain] " << GREEN << "Copy assignment operator called\n" << RESET;
	return (*this);
}

// Destructor
Brain::~Brain(void)
{
	std::cout << BLUE << "[Brain] " << GREEN << "Destructor called\n" << RESET;
}

// Setters
void	Brain::setIdeas(std::string	p_ideas, size_t p_index)
{
	this->_ideas[p_index] = p_ideas;
}

// Getters
std::string	Brain::getIdeas(size_t p_index) const
{
	return (this->_ideas[p_index]);
}

// std::ostream	&operator<<(std::ostream &output, const Brain &other)
// {
// 	output << other.getIdeas();
// 	return (output);
// }
