#include <cmath>
#include <string>
#include "Base64.h"

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
string Base64::encodeText() const {
	string encodedString = "";

	uint8_t indexNewChar = 0;
	int8_t binSelection = 5;

	//I divide the sequence of bits into groups of 6 and extract the character from the table
	for (const uint8_t character : this->msgPlainText) {
		for (uint8_t i = 0, bitSelected = 0x80; i < 8; bitSelected >>= 1, i++) {
			if (binSelection < 0) {
				encodedString += this->table[indexNewChar];
				binSelection = 5;
				indexNewChar = 0;
			}

			if (character & bitSelected)
				indexNewChar += static_cast<uint8_t>(pow(2, binSelection));

			binSelection--;
		}
	}
	encodedString += this->table[indexNewChar];

	//I add a padding of '=' from 0 to 2 until the string is a multiple of 4
	while (encodedString.length() % 4) 
		encodedString += "=";

	return encodedString;
}

string Base64::decodeText() const {
	string rmPadding = this->msgPlainText;
	rmPadding.erase(remove(rmPadding.begin(), rmPadding.end(), '='), rmPadding.end());

	string decodedString = "";

	//TODO decoding algorithm

	return decodedString;
}









/*
	PUBLIC INTERFACE
*/
string Base64::encodeB64() const {
	if (!this->msgPlainText.length())
		return "";

	return encodeText();
}

string Base64::decodeB64() const {
	if (!this->msgPlainText.length())
		return "";

	return decodeText();
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
