#include <array>
#include <span>
#include <vector>
#include <iostream>

using namespace std;

// �Ѵ� ��������
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

	// �������� ����� �˰� �ִٸ� �ϳ��� �������̽��� ������ �� �ִ�.

	span<int> sp{ vecNums };
	span<int> sp{ arrNum };
	printSpan(sp);

	// ������ �ٲ�� �߸��� ���� Access �� �� �ִ�.
	// �޸� ������ �ٲ�
}