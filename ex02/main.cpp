#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Helper.hpp"

/*
	In this exercise, you just seeing whether it's pure virtual function or not
	if pure virtual function present in base but not in derived class, cannot instantiate derived class too
	it must be both present to allow derived class to instantiate

	Animal class now cannot instantiate, but you can use animal pointer to create new class

	Pay attention to 
	- makesound_test
	- pointer_test
	- ocf_test
	- from_pdf
*/
void	deep_copy_test(void)
{
	deepcopy_cat_test();
	deepcopy_dog_test();
}
void	pointer_test(void)
{
	// animal_pointer();
	cat_pointer();
	dog_pointer();
}

void	makeSound_test(void)
{
	// animal_makeSound();
	cat_makeSound();
	dog_makeSound();
}

void	ocf_test(void)
{
	// animal_ocf_test();
	cat_ocf_test();
	dog_ocf_test();
}

int	main()
{
	ocf_test();
	// setter_test();
	makeSound_test();
	pointer_test();
	from_pdf();
	brain_pdf_test();
	animal_array_test();
	deep_copy_test();
}
