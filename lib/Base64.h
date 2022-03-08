#include <string>
using std::string;

class Base64 {
	private:
		const char table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
		string msgPlainText;

		string encodeText() const;
		string decodeText() const;

	public:
		Base64();
		Base64(const string& text);
		Base64(const char* text);
		~Base64() = default;

		string encodeB64() const;
		string decodeB64() const;

		/* OPERATOR OVERLOADING */
		void operator= (const string&);
		void operator= (const char*);
};
