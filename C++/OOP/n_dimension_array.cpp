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
	// cache line �������� loop�� ������ �� ������
	// -> ����, cache miss�� ���� �Ͼ��.
}