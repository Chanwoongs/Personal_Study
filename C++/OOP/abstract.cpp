#include <iostream>

using namespace std;

// �߻�ȭ 
// ������ ������, ����, �ý��� �����κ��� �ٽɸ��� ������ �� �ڼ��ϰ� ����� ��
// ���λ���, ���� ���� ���߰� �������̽� ���� ����� �� -> ���⵵�� �����.

class Animal // ������ �߻�ȭ : ��� �����͵��� �������� ������ �������� ����
{
public:
	virtual void animalSound() = 0; // ���μ��� �߻�ȭ : ���� ���μ����� �����. 
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