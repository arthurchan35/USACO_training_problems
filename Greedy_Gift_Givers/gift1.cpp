/*
ID: arthurc2
PROG: gift1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

	ifstream ifs("gift1.in", ifstream::in);

	int np = 0;
	ifs >> np;
	vector<string> names;
	unordered_map<string, int> name_index;
	vector<int> money(np, 0);

	names.reserve(np);
	name_index.reserve(np);

	for (int i = 0; i < np; ++i) {
		string name;
		ifs >> name;
		names.push_back(name);
		name_index[name] = i;
	}

	string self_name;
	while (ifs >> self_name) {

		int money_to_give = 0;
		ifs >> money_to_give;

		int no_of_friends = 0;
		ifs >> no_of_friends;

		int money_to_friend = 0;
		int money_to_self = 0;

		if (no_of_friends == 0)
			money_to_self = money_to_give;
		else {
			money_to_friend = money_to_give / no_of_friends;
			money_to_self = money_to_give % no_of_friends;
		}

		if (money_to_friend > 0) {
			for (int i = 0; i < no_of_friends; ++i) {
				string friend_name;
				ifs >> friend_name;
				int friend_index = name_index[friend_name];
				money[friend_index] += money_to_friend;
			}
		}

		int self_index = name_index[self_name];
		money[self_index] += (money_to_self - money_to_give);
	}

	ofstream ofs("gift1.out", ofstream::out);
	for (int i = 0; i < np; ++i) {
		ofs << names[i] << ' ' << money[i] << endl;
	}

	return 0;
}