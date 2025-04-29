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

/*
	Adding virtual to base class function allows it to be overridden by derived class
		at runtime (polymorphism)/dynamic polymorphism

	Compile-time polymorphism
		Function overloading
		Operator overloading
		Template programming

	Adding virtual to destructor
		- allows deleting a base class pointer to a derived object safely 
		— destroying the derived part first, then the base class
*/
class	Animal
{
	protected:
		std::string		_type;

	public:
		Animal(void);
		Animal(std::string p_type);
		Animal(const Animal &other);
		Animal	&operator=(const Animal &other);
		virtual	~Animal(void);

		virtual void	makeSound() const;

		// Setters
		void	setType(std::string p_type);

		// Getters
		std::string		getType() const;
};

std::ostream	&operator<<(std::ostream &output, const Animal &other);

#endif