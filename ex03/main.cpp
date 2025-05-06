#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void basicTest()
{
	std::cout << "\n===== Basic Test =====\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void overflowTest()
{
	std::cout << "\n===== Overflow Test =====\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	for (int i = 0; i < 5; ++i)
		me->equip(src->createMateria(i % 2 == 0 ? "ice" : "cure"));

	delete me;
	delete src;
}

void unequipAndEquipTest()
{
	std::cout << "\n===== Unequip and Equip Test =====\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");
	me->equip(src->createMateria("ice"));
	me->unequip(0);
	me->equip(src->createMateria("ice"));

	delete me;
	delete src;
}

void invalidIndexTest()
{
	std::cout << "\n===== Invalid Index Test =====\n";
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	me->use(-1, *bob);
	me->use(10, *bob);
	me->unequip(-1);
	me->unequip(10);

	delete bob;
	delete me;
}

void nullEquipTest()
{
	std::cout << "\n===== Null Equip Test =====\n";
	ICharacter* me = new Character("me");
	me->equip(NULL);
	delete me;
}

void copyAndAssignTest()
{
	std::cout << "\n===== Copy and Assignment Test =====\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Cure());

	Character me("me");
	me.equip(src->createMateria("cure"));

	Character copyMe(me);
	copyMe.use(0, me);

	Character assigned("assigned");
	assigned = me;
	assigned.use(0, me);

	delete src;
}

void unknownMateriaTest()
{
	std::cout << "\n===== Unknown Materia Test =====\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	AMateria* unknown = src->createMateria("fire");
	if (!unknown)
		std::cout << "Unknown materia creation correctly returned NULL\n";
	delete src;
}

void multipleCharactersTest()
{
	std::cout << "\n===== Multiple Characters Test =====\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* alice = new Character("alice");
	ICharacter* bob = new Character("bob");

	alice->equip(src->createMateria("ice"));
	alice->use(0, *bob);

	delete alice;
	delete bob;
	delete src;
}

int main()
{
	basicTest();
	overflowTest();
	unequipAndEquipTest();
	invalidIndexTest();
	nullEquipTest();
	copyAndAssignTest();
	unknownMateriaTest();
	multipleCharactersTest();

	return 0;
}
