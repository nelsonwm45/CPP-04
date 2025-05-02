#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

# ifndef INT32_MAX
#  define INT32_MAX 2147483647
# endif 

# ifndef UINT32_MAX
#  define UINT32_MAX 4294967295U
# endif

class	Dog : public Animal
{
	private:
		Brain	*_brain;
		
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog	&operator=(const Dog &other);
		~Dog(void);

		void	makeSound(void) const;
};

std::ostream	&operator<<(std::ostream &output, const Dog &other);

#endif