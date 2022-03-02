#include <string>
using std::string;

class Base64 {
	private:
		char* table;
		string msgPlainText;
		string fromStringToBinaryDigit() const;
	public:
		Base64();
		Base64(string& text);
		~Base64() = default;
		string encodeB64() const;
};