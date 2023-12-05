#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	//sort
	vector<int> nums{ 1,3,4,5,6,6,7 };
	sort(nums.begin(), nums.end(), callable object);
	stable_sort(); // �����̳� ���� ���� ������ �ٲ��� �ʰ� sort
	partial_sort(); // �����̳ʿ��� ���ϴ� ���������� ����
	nth_element(); // ������ ���� ���ʿ� ���� �͸�, �����ʿ� ū�͸� (���� X)

	//minmax
	min_element();
	max_element();
	minmax_element();

	//find
	auto it = find(nums.begin(), nums.end(), 2);
	int idx = distance(nums.begin(), it);
	//if sorted
	binary_search(); //logN

	//reduce, sum, product
	accumulate()
	reduce()
}