#include <iostream>

using namespace std;

class Animal
{
	Animal& operator=(Animal other) = delete;
	virtual void speak()
	{
		cout << "ani\n";
	}
	virtual ~Animal() = default;
protected:
	Animal(const Animal& other) = default;
private:
	double data = 0.0f;
};

bool operator==(const Animal& lhs, const Animal& rhs)
{
	return lhs.data == rhs.data;
}

class Cat : public Animal
{
public:
	Cat(double d) : catData{ d } {}
	virtual void speak() override
	{
		cout << "cat\n";
	}
private:
	double catData;
};

bool operator==(const Cat& lhs, const Cat& rhs)
{
	return lhs.data == rhs.data;
}

void f(Aniaml animal) // reference 로 받아야한다.
{

}

int main()
{
	Cat kitty{ 1.0 };
	kitty.speak();

	Animal& animalRef = kitty;
	animalRef.speak(); // meow

	Animal animalObj = kitty;
	animalObj.speak(); // animal
	return 0;
}