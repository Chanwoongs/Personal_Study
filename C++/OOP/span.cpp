#include <array>
#include <span>
#include <vector>
#include <iostream>

using namespace std;

// 둘다 만들어야함
void printVec();
void printArr();

void printSpan(span<int> nums)
{
	for (auto num : nums)
	{
		cout << num;
	}
}

int main()
{
	vector<int> vecNum{ 1,2,3 };
	array<int, 4> arrNum{ 4,5,6,7 };
	int cNums[6] = { 1,2,3,4,5,6 };

	// 시작점과 사이즈만 알고 있다면 하나의 인터페이스로 대응할 수 있다.

	span<int> sp{ vecNums };
	span<int> sp{ arrNum };
	printSpan(sp);

	// 원본이 바뀌면 잘못된 곳에 Access 할 수 있다.
	// 메모리 공간이 바뀌어서
}