#include <iostream>
#include <array>
#include <vector>

using namespace std;


int main()
{
	// 3 x 3
	// 9
	array<array<int, 3>, 3> fixedMatrix;
	vector<vector<int>> dynamicMatrix(3, vector<int>(3));

	fixedMatrix[1][1] = 5;
	dynamicMatrix[0][2] = 10;

	// loop
	array<array<int, 10>, 10> mat;
	// cache line 방향으로 loop를 돌리면 더 빠르다
	// -> 방향, cache miss가 적게 일어난다.
}