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
	virtual void move() = 0; // 가지고 있다면 abstract class -> object 생성 불가, 추상적인 클래스
private:
	double height;
};

class Cat : public Animal
{
public:
	virtual void speak() override
	{
		cout << "meow\n";
	}
	// move를 무조건 구현해야함
	virtual void move() override
	{
		cout << "moved\n";
	}
private:
	double weight;
};

int main()
{
	// with virtual and override
	cout << "Animal size : " << sizeof(Animal) << '\n'; // 8 + 8 bytes, V-table 주소 추가
	cout << "Cat size : " << sizeof(Cat) << '\n'; // 16 + 8 bytes, V-table 주소 추가

	Animal* polyAnimal = new Cat();
	polyAnimal->speak();
	delete polyAnimal;
}