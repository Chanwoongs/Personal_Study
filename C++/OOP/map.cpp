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


	numPairs.emplace(1, 1005); // 중복 제거
	numPairs[1] = 1004; // 값 변경
	cout << numPairs[6] << '\n'; // 참조하는 순간 Default 값으로 초기화

}