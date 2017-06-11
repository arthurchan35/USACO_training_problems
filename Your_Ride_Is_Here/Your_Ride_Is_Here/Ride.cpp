/*
ID: arthurc2
PROG: ride
LANG: C++14
*/
#include <fstream>

using namespace std;


inline void readName(ifstream& ifs, char* name) {
	char curr;
	short cunter = 0;

	while (ifs >> curr) {
		if (curr == '\n') break;
		name[cunter++] = curr;
	}
}

inline unsigned int findRemainder(char* name, unsigned int divisor) {
	unsigned int remainder = 1;

	for (char* c = name; *c != 0; ++c)
		remainder *= ((*c) - 'A' + 1);//((*c) - 'A' + 1) * remainder) % 47; ?

	remainder %= divisor;
	
	return remainder;
}

int main() {
	char comet[7] = { 0 };
	char group[7] = { 0 };

	ofstream ofs("ride.out");
	ifstream ifs("ride.in");
	ifs.unsetf(ios_base::skipws);

	readName(ifs, comet);
	readName(ifs, group);

	unsigned int c = findRemainder(comet, 47);
	unsigned int g = findRemainder(group, 47);

	ofs << ((c == g) ? "GO" : "STAY") << endl;

	return 0;
}

