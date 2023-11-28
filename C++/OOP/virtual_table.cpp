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
	virtual void move() = 0; // ������ �ִٸ� abstract class -> object ���� �Ұ�, �߻����� Ŭ����
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
	// move�� ������ �����ؾ���
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
	cout << "Animal size : " << sizeof(Animal) << '\n'; // 8 + 8 bytes, V-table �ּ� �߰�
	cout << "Cat size : " << sizeof(Cat) << '\n'; // 16 + 8 bytes, V-table �ּ� �߰�

	Animal* polyAnimal = new Cat();
	polyAnimal->speak();
	delete polyAnimal;
}