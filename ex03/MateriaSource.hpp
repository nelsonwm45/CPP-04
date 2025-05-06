#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#include <iostream>
#include <cstddef> // size_t

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

class	MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_AMateria[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		MateriaSource	&operator=(const MateriaSource &other);

		~MateriaSource(void);
		void	learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const &type);
};

#endif