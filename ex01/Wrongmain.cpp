#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();

	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the animal sound!
	meta->makeSound(); // output animal sound!

	delete i;
	delete meta;
	return 0;
}
