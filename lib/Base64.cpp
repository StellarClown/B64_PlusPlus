#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
#include "Base64.h"

using std::stringstream;
using std::reverse;
using std::string;


/*
	CONSTRUCTORS
*/
Base64::Base64() : msgPlainText("") {
	;
}

Base64::Base64(const string& text) : msgPlainText(text) {
	;
}

Base64::Base64(const char* text) : msgPlainText(text) {
	;
}


/*
	LOGIC
*/
string Base64::fromStringToBinaryDigit() const {
	string finalSeqBit;

	//I convert the whole string to a sequence of bits
	for (uint8_t x : this->msgPlainText) {
		uint8_t maskToApply = 1;
		stringstream toBin;

		//I extract the bits of the single character
		for (uint8_t i = 0; i < 8; i++) {
			if (x & maskToApply)
				toBin << "1";
			else
				toBin << "0";
			maskToApply <<= 1;
		}

		string toAppend = toBin.str();
		reverse(toAppend.begin(), toAppend.end());

		finalSeqBit += toAppend;
	}

	return finalSeqBit;
}

string Base64::encodeText() const {
	string toRet = "";
	
	//I divide the sequence of bits into groups of 6 and extract the character from the table
	string bitText = fromStringToBinaryDigit();
	int8_t binSel = 5;
	uint8_t indexTable = 0;
	for (char bin : bitText) {
		if (binSel < 0) {
			toRet += table[indexTable];
			binSel = 5;
			indexTable = 0;
		}
		if (bin == '1')
			indexTable += pow(2, binSel);
		binSel--;
	}
	toRet += table[indexTable];

	//I add a padding of '=' from 0 to 2 until the string is a multiple of 4
	while (toRet.length() % 4)
		toRet += "=";

	return toRet;
}

string Base64::encodeB64() const {
	if (!this->msgPlainText.length())
		return "";

	return encodeText();
}


/*
	OPERATORS
*/
void Base64::operator= (const string& text) {
	msgPlainText = text;
}

void Base64::operator= (const char* text) {
	msgPlainText = text;
}
