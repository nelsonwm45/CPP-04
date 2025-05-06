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
	AMateria* extra = NULL;

	for (int i = 0; i < 5; ++i)
	{
		AMateria* m = NULL;
		if (i % 2 == 0)
			m = src->createMateria("ice");
		else
			m = src->createMateria("cure");

		if (i < 4)
			me->equip(m);
		else
			extra = m;
	}

	delete extra;
	delete me;
	delete src;
}

void unequipAndEquipTest()
{
	std::cout << "\n===== Unequip and Equip Test =====\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");

	// First equip
	AMateria* m1 = src->createMateria("ice");
	me->equip(m1);

	// Unequip (this just sets slot to NULL)
	me->unequip(0);

	// Second equip
	AMateria* m2 = src->createMateria("ice");
	me->equip(m2);

	// Clean up:
	// Since m1 was unequipped and we lost its address, this is a memory leak
	// The only way to fix this without changing unequip() is to delete m1 before unequipping
	// So better approach would be:

	delete me;  // This will delete the equipped m2
	delete m1;  // Explicitly delete the unequipped one

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

	// Create the MateriaSource and learn an Ice Materia
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice()); // Learn a new Ice materia

	// Create two characters
	ICharacter* alice = new Character("alice");
	ICharacter* bob = new Character("bob");

	// Equip Alice with the Ice Materia (remember to clone it to transfer ownership)
	AMateria* iceMateria = src->createMateria("ice");  // Create a clone of the "Ice" Materia
	alice->equip(iceMateria);  // Equip Alice with the cloned Materia

	// Alice uses the equipped Materia on Bob
	alice->use(0, *bob);

	// Clean up the MateriaSource object (this will not delete Materia, as it's now owned by Alice)
	delete src;

	// Delete Alice and Bob (their destructors will clean up the Materia in their inventories)
	delete alice;
	delete bob;
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
