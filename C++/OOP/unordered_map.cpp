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

	// �ߺ� ���ŷ� ���� ����
	idNames.emplace(1, "d");
	// idx�� �����ϸ� ���氡��
	idNames[1] = "d";
	cout << idNames[100]; // 100�� ����, [] bracket ����
	// multimap �ߺ� ����


}