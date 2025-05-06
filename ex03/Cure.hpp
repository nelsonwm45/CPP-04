#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

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

/*
	Concrete class: 
		a class that has full implementation of functions,
		and able to instantiate directly
	
	Abstrac Class and Interfaces are opposite of concrete class
*/

class	Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &other);
		Cure	&operator=(const Cure &other);
		~Cure(void);

		AMateria *clone(void) const;
		void	use(ICharacter &target);
};

std::ostream	&operator<<(std::ostream &output, const Cure &other);

#endif