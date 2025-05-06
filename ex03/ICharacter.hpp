#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

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
	forward declaration to prevent inclusion loop
	
	main.cpp → MateriaSource.hpp → AMateria.hpp → ICharacter.hpp → AMateria.hpp (again)

*/
class	AMateria;
/*
	Concrete Class:
	 - a normal class
	 - can instantiate
	 - all methods fully implemented
	 - contains data members
	 - no virtual fx

	Abstract Class:
	 - cannot instantiate
	 - contains at least one virtual fx (no need implementation)
	 - contains data members and concrete function
	
	Interfaces/Pure Abstract Class:
	 - cannot instantiate
	 - contains all virtual fx (no implementation)
	 - contains no data members and concrete fx.
	 - C++ no interface keywords, but js has it
*/
class	ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif