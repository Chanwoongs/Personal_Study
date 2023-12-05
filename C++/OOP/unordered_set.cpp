#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<string> uSet;
	uSet.reserve(1000); // 미리 bucket size 결정
	uSet.max_load_factor(10); // bucket안의 원소 개수를 설정할 수 있다. rehashing 조절

	uSet.emplace("a");
	uSet.emplace("b");
	uSet.emplace("c");
	uSet.emplace("d");
	
	// 출력시 순서없이 출력
	uSet.find("a");
	uSet.erase("a");
	// 모두 O(1)

	// 각 Hash 값
	cout << "Hash 값 : " << hash<string>{}("a") << uSet.bucket("a") << endl;
	cout << "Hash 값 : " << hash<string>{}("b") << uSet.bucket("b") << endl;
	cout << "Hash 값 : " << hash<string>{}("c") << uSet.bucket("c") << endl;
	cout << "Hash 값 : " << hash<string>{}("d") << uSet.bucket("d") << endl;
	
	cout << "bucket count : " << uSet.bucket_count() << endl;
}