#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	unordered_map<int, string> idNames;

	idNames.emplace(1, "a");
	idNames.emplace(2, "b");
	idNames.emplace(3, "c");

	// 중복 제거로 들어가지 않음
	idNames.emplace(1, "d");
	// idx로 접근하면 변경가능
	idNames[1] = "d";
	cout << idNames[100]; // 100이 생김, [] bracket 주의
	// multimap 중복 가능


}