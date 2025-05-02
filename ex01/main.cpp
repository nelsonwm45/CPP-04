#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Helper.hpp"

void	pointer_test(void)
{
	animal_pointer();
	cat_pointer();
	dog_pointer();
}

void	makeSound_test(void)
{
	animal_makeSound();
	cat_makeSound();
	dog_makeSound();
}

void	ocf_test(void)
{
	animal_ocf_test();
	cat_ocf_test();
	dog_ocf_test();
}

int	main()
{
	ocf_test();
	setter_test();
	makeSound_test();
	pointer_test();
	from_pdf();
	brain_pdf_test();
}
