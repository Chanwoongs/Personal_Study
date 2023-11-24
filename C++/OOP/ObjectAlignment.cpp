#include <iostream>
using namespace std;
class alignas(32) Cat // false sharing 방지를 위해 memory padding 추가
{
public:
	void speak();
private:
	double d; // 8
	int mAge; // 4 
	int a; // 4
	// 16 bytes

	int a; // 4
	double d; // 8 
	int mAge; // 4 
	// 24 bytes

	char c1; // 1
	int i4a; // 4
	int i4b; // 4
	double d8; // 8
	// 24 bytes
};

Cat StaticCat;

int main()
{
	cout << sizeof(Cat) << '\n'; // 4 bytes, mAge(int)
	Cat stackcat;

	Cat cats[100];

	Cat* heapCatPtr = new Cat;
	delete heapCatPtr;

	return 0;
}