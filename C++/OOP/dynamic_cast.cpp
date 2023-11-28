#include <iostream>
#include <array>
using namespace std;

class Animal
{
public:
	virtual void speak()
	{
		cout << "ani\n";
	}
};

class Cat : public Animal
{
public:
	virtual void speak() override
	{
		cout << "meow\n";
	}
	void knead()
	{
		cout << "kkuk\n";
	}
};

class Dog : public Animal
{
public:
	virtual void speak() override
	{
		cout << "bark\n";
	}
	void wagTail()
	{
		cout << "wag\n";
	}
};

int main()
{
	Cat* catPtr = new Cat();

	// upcast
	Animal* animalPtr = static_cast<Animal *>(catPtr);
	animalPtr->speak();
	animalPtr->knead(); // ºÒ°¡
	delete catPtr;

	// downcast
	// very dangerous
	Animal* animalPtr1 = new Cat();
	Cat* catPtr1 = staic_cast<Cat*>(animalPtr1);
	animalPtr1->speak();
	animalPtr1->knead();

	Animal* animalPtr1 = new Cat();
	Cat* catPtr1 = dynamic_cast<Cat*>(animalPtr1);
	if (catPtr1 == nullptr)
	{
		cout << "not cat\n";
		return 0;
	}
	animalPtr1->speak();
	animalPtr1->knead();

	cout << typeid(Cat).name() << endl; // type_info


}