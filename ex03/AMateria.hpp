#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

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

class	AMateria
{
	protected:
		std::string const		_type;

	public:
		AMateria(void);
		AMateria(std::string const p_type);
		AMateria(const AMateria &other);
		AMateria	&operator=(const AMateria &other);
		virtual	~AMateria(void);

		// Setters
		// void	setType(std::string p_type); // do not need cus const

		// Getters
		std::string const	&getType() const;

		virtual AMateria *clone() const = 0; // Pure virtual function, no implementation needed
		virtual void use(ICharacter &target);


};

std::ostream	&operator<<(std::ostream &output, const AMateria &other);

#endif