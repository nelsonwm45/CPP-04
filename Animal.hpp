#ifndef ANIMAL_HPP
#define ANIMAL_HPP

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


class	Animal
{
	protected:
		std::string		_type;

	public:
		Animal(void);
		Animal(const Animal &other);
		Animal	&operator=(const Animal &other);
		virtual	~Animal(void);

		void	makeSound();

		// Setters
		void	setType(std::string p_type);

		// Getters
		std::string		getType() const;
};


#endif