#include <list>
#include <forward_list>
using namespace std;

int main()
{
	list<int> nums{ 1,2,3,4,5 };

	nums.emplace_back(6);
	nums.emplace_front(0);

	auto it = find(nums.begin(), nums.end(), 3);
	if (it != nums.end())
	{
		nums.emplace(it, 100);
	}

	forward_list<int> nums2{ 1,2,3,4,5 };
	nums2.emplace_front(0);
}