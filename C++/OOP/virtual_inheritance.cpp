#include <iostream>

using namespace std;

class Animal
{
	virtual void speak();
	virtual ~Animal() = default;
private:
	double data;
};

class Lion : virtual public Animal
{
public:
	virtual void speak();
private:
	double lionData;
};

int main()
{
	// without virtual inheritance
	cout << sizeof(Lion) << endl; // 24 bytes;
	// with virtual inheritance
	cout << sizeof(Lion) << endl; // 32 bytes;

	Animal* polyAnimal = new Lion();
	polyAnimal->speak();
	delete polyAnimal;
}