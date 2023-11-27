#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

class Cat : public Animal
{
public:
	Cat(int age) : mAge{ age }
	{
		cout << "constructor" << '\n';
	}
	~Cat()
	{
		cout << " destructor" << '\n';
	}
private:
	int mAge;
};

class Dog : public Animal
{};

class Zoo
{
	Zoo(int n)
	{
		if (n == 1)
		{
			mAnimal = new Cat();
			mAnimal = make_unique<Cat>();

		}
		else
		{
			mAnimal = new Dog();
			mAnimal = make_unique<Dog>();
		}
		// rule of three ~, copy, move
		// unique ptr�� ����ϸ� ���簡 �Ұ��ϱ� ������ �� ���� �Ҵ� �����ڸ� �ȸ����ȴ�.
	}

private:
	Animal* mAnimal;
	unique_ptr<Animal> mAnimal; 
};

void foo(Cat* ptr)
{
	Cat* fooPtr = ptr;
	delete fooPtr; // �Ǽ��� ���� �Ҽ� �� �ִ�.
}

int main()
{
	unique_ptr<Cat> catPtr = make_unique<Cat>(0);
	unique_ptr<Cat> catPtr1 = catPtr; // compile error! 2���� �����ͷ� ����ų �� ����
	unique_ptr<Cat> catPtr1 = move(catPtr); // ������ ���� / ���� ����

	Cat* catPtr = new Cat(0);
	Cat* catPtr1 = catPtr;
	foo(catPtr);

	delete catPtr;

	return 0;
}