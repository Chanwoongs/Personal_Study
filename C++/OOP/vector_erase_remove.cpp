#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> nums{ 0,1,0,1,0,1 };

	// erase , 지우고 앞으로 move
	nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
	nums.erase(remove_if(nums.begin(), nums.end(), [](int n)
	{
		if (n & 2 == 0)
			return true;
		else return false;
	}), nums.end());
}