#include <map>
#include <iostream>
using namespace std;

int main()
{
	map<int, int> numPairs;

	numPairs.emplace(1, 101);
	numPairs.emplace(2, 102);
	numPairs.emplace(3, 103);
	numPairs.emplace(4, 104);
	numPairs.emplace(5, 105);


	numPairs.emplace(1, 1005); // �ߺ� ����
	numPairs[1] = 1004; // �� ����
	cout << numPairs[6] << '\n'; // �����ϴ� ���� Default ������ �ʱ�ȭ

}