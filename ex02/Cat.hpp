#ifndef CAT_HPP
#define CAT_HPP

// #include "Animal.hpp"
#include "AAnimal.hpp"
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

/*
	Adding "override" keywords to tell compiler to show error
	if there is mismatch of function signature

	Missing "override" keywords won't affect compilation

	Override does not available in C++98 but available in C++11 and above

	If u have pure virtual function in base class, 
		your derived class must implement override function
		otherwise ur derived class inherit abstract properties of base class
		and cannot instantiate
*/
class	Cat : public AAnimal
{
	private:
		Brain	*_brain;

	public:
		Cat(void);
		Cat(const Cat &other);
		Cat	&operator=(const Cat &other);
		~Cat(void);

		void	makeSound(void) const;

		// Setters
		void	setIdeas(std::string p_ideas, size_t p_index);

		// Getters
		std::string		getIdeas(size_t p_index) const;
};

std::ostream	&operator<<(std::ostream &output, const Cat &other);

#endif