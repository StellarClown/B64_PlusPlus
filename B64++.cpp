#include <iostream>
#include "Base64.h"

using namespace std;

int main(int argc, char* argv[]) {
	string testA = "YOUR STRING HERE";
	Base64 prova = {testA};

	cout << prova.encodeB64() << endl;

	return 0;
}