#include <iostream>

using namespace std;

// 추상화 
// 복잡한 데이터, 구조, 시스템 등으로부터 핵심만을 가려내 덜 자세하게 만드는 것
// 세부사항, 절차 등을 감추고 인터페이스 등을 만드는 것 -> 복잡도를 낮춘다.

class Animal // 데이터 추상화 : 어떠한 데이터들의 공통점을 모으고 차이점은 버림
{
public:
	virtual void animalSound() = 0; // 프로세스 추상화 : 내부 프로세스를 숨긴다. 
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