#include <iostream>
#include <array>
#include <vector>

using namespace std;

void fnArray()
{
	array<int, 100> nums;
}

void fnVector()
{
	vector<int> nums(100);
}

int main()
{
	fnArray();
	fnVector();


}