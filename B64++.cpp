#include <iostream>
#include <string>
#include "Base64.h"

using namespace std;

int main(int argc, char* argv[]) {
	string commandList = argv[2];
	if ((argc != 3) || ((commandList != "-e") && (commandList != "-d"))) {
		cout << "[*] USAGE: " << argv[0] << " YOUR_MESSAGE -e/-d" << endl;
		return 0;
	}

	char command = argv[2][1];
	Base64 b64data = argv[1];
	switch (command) {
		case 'e':
			cout << "Encoded: " << b64data.encodeB64() << endl;
			break;
		case 'd':
			cout << "Decoded: " << b64data.decodeB64() << endl;
			break;
		default:
			break;
	}

	return 0;
}
