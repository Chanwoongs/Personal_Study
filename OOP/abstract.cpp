#include <iostream>

using namespace std;

class Animal // ������ �߻�ȭ
{
public:
	virtual void animalSound() = 0; // ���μ��� �߻�ȭ
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