#include <iostream>

using namespace std;

class Animal // 데이터 추상화
{
public:
	virtual void animalSound() = 0; // 프로세스 추상화
	virtual void sleep() = 0;
private:

};

class Pig : Animal
{
public:
	virtual void animalSound() override
	{
		cout << "Oink" << endl;
	}
	virtual void sleep() override
	{
		cout << "zzz" << endl;
	}
};

int main()
{

}