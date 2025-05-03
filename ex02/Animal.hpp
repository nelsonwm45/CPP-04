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
	Abstract class 
		-> a class that cannot instantiated directly
		-> serves as a base blueprint for other class
		-> define abstract methods (methods without a body) 
			that force subclasses to implement them.
		-> can have regular methods and member variables
		-> enforce a common interface or contract
	
	How to make an abstract class
		-> making at least 1 virtual fx = 0 / pure virtual function
		virtual void makeSound() = 0;
		
		then derived class put
		void makeSound()

	If you don't missing "overidden function" for a pure virtual function
		Your derived class will be abstract class, because you
			inherit the abstract properties
		Your derived class now unable to instantiate directly
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