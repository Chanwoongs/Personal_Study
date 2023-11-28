#include <iostream>
#include <array>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "animal constructor\n";
	}
	virtual ~Animal()
	{
		cout << "animal destructor\n";
	}
	virtual void speak()
	{
		cout << "ani\n";
	}
};

class Cat : public Animal
{
public:
	Cat()
	{
		cout << "Cat constructor\n";
	}
	~Cat()
	{
		cout << "Cat destructor\n";
	}
	virtual void speak() override
	{
		cout << "meow\n";
	}
};

class Dog : public Animal
{
public:
	virtual void speak() override
	{
		cout << "bark\n";
	}
};

int main()
{
	Cat* catPtr = new Cat();
	delete catPtr;
	// ani con
	// cat con
	// cat des
	// ani des

	Animal* polyCat = new Cat();
	delete polyCat;
	// without virtual -> no cat des
	// ani con
	// cat con
	// ani des

	// dynamic, runtime polymorphism
	int i;
	Animal* polyAnimal;
	if (i == 1)
	{
		polyAnimal = new Cat();
	}
	else
	{
		polyAnimal = new Animal();
	}
	polyAnimal->speak();
	delete polyAnimal;

	// 배열에 고양이 강아지를 dynamic하게 넣기
	array<Animal*, 5> animals;
	for (auto& ani : animals)
	{
		int i;
		Animal* polyAnimal;
		if (i == 1)
		{
			polyAnimal = new Cat();
		}
		else
		{
			polyAnimal = new Dog();
		}
	}
	for (auto& ani : animals)
	{
		ani->speak();
		delete ani;
	}
}