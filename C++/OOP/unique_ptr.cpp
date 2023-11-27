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
		// unique ptr을 사용하면 복사가 불가하기 때문에 위 생성 할당 연산자를 안만들어도된다.
	}

private:
	Animal* mAnimal;
	unique_ptr<Animal> mAnimal; 
};

void foo(Cat* ptr)
{
	Cat* fooPtr = ptr;
	delete fooPtr; // 실수로 삭제 할수 도 있다.
}

int main()
{
	unique_ptr<Cat> catPtr = make_unique<Cat>(0);
	unique_ptr<Cat> catPtr1 = catPtr; // compile error! 2개의 포인터로 가리킬 수 없다
	unique_ptr<Cat> catPtr1 = move(catPtr); // 소유권 이전 / 빌드 가능

	Cat* catPtr = new Cat(0);
	Cat* catPtr1 = catPtr;
	foo(catPtr);

	delete catPtr;

	return 0;
}