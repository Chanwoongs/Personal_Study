#include <iostream>

using namespace std;

class Animal
{

};

class Lion : virtual public Animal
{
public:
	Lion()
	{
		cout << "lion cons\n";
	}
	virtual ~Lion()
	{
		cout << "lion des\n";
	}
	virtual void speak()
	{
		cout << "lion speak\n";
	}
private:
	double lionData;
};

class Tiger : virtual public Animal
{
public:
	Tiger()
	{
		cout << "tiger cons\n";
	}
	~Tiger()
	{
		cout << "tiger des\n";
	}
	virtual void speak()
	{
		cout << "tiger speak\n";
	}
private:
	double tigerData;
};

class Liger : public Lion, public Tiger // 순서에 따라 생성자 호출 순서 정해짐
{
public:
	Liger()
	{
		cout << "Liger cons\n";
	}
	~Liger()
	{
		cout << "Liger des\n";
	}
	virtual void speak()
	{
		cout << "Liger speak\n";
	}
private:
	double ligerData;
};


int main()
{
	cout << sizeof(Liger) << '\n'; // 40 bytes
	
	Lion* polyLion = new Liger();
	polyLion->speak();
	delete polyLion;
		
	// diamond
	Liger liger;
	liger.speak();
	// ani cons
	// li cons
	// ani cons
	// ti cons
	// liger cons
	// liger des
	// ..
}