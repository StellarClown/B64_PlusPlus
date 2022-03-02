#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
#include "Base64.h"

using std::stringstream;
using std::reverse;
using std::string;

Base64::Base64() : table(nullptr), msgPlainText("") {
	;
}

Base64::Base64(string& text) : table{ new char[65] }, msgPlainText(text) {
	table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
}

string Base64::fromStringToBinaryDigit() const {
	string finalSeqBit;

	//Convert the string in a sequence of binary digit
	for (uint8_t x : this->msgPlainText) {
		uint8_t mask = 1;
		stringstream toBin;

		for (uint8_t i = 0; i < 8; i++) {
			if (x & mask)
				toBin << "1";
			else
				toBin << "0";
			mask <<= 1;
		}

		string toAppend = toBin.str();
		reverse(toAppend.begin(), toAppend.end());
		finalSeqBit += toAppend;
	}

	return finalSeqBit;
}

string Base64::encodeB64() const {
	string encoded = "";

	if (!table || this->msgPlainText == "")
		return encoded;

	string seqOfText = fromStringToBinaryDigit();
	int16_t binSel = 5;
	uint16_t indexTable = 0;
	for (char& bin : seqOfText) {
		if (binSel < 0) {
			encoded += table[indexTable];
			binSel = 5;
			indexTable = 0;
		}
		if (bin == '1')
			indexTable += pow(2, binSel);
		binSel--;
	}
	encoded += table[indexTable];

	while (encoded.length() % 4)
		encoded += "=";

	return encoded;
}