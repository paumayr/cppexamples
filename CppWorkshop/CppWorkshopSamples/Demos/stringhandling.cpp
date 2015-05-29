#include "stdafx.h"
#include "CppUnitTest.h"
#include <locale>
#include <codecvt>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(StringHandling)
{
	const string quickBrownFox = "The quick brown fox jumps over the lazy dog";

	TEST_METHOD(Comparison)
	{
		string x = "my string";
		string y = "my other string";
		string x2 = "my string";
		Assert::IsFalse(x == y);
		Assert::IsTrue(x == x2);
	}

	TEST_METHOD(FindingCharacters)
	{
		auto b = quickBrownFox.find_first_of('f');
		Assert::IsTrue(b == 16);

		// finds the c (first of the 3 letters in 'quick')
		Assert::IsTrue(quickBrownFox.find_first_of("abc") == 7);
	}

	TEST_METHOD(Substring)
	{
		// offset and length
		Assert::IsTrue(quickBrownFox.substr(16, 3) == "fox");

		// offset only -> all the way to end
		Assert::IsTrue(quickBrownFox.substr(16) == "fox jumps over the lazy dog");
	}

	TEST_METHOD(FindSubstring)
	{
		Assert::IsTrue(quickBrownFox.find("fox") == 16);

		// not found
		Assert::IsTrue(quickBrownFox.find("hello") == string::npos);

		// find from reverse
		string abc = "abcabc";
		Assert::IsTrue(abc.find("abc") == 0);
		Assert::IsTrue(abc.rfind("abc") == 3);
	}

	TEST_METHOD(WideCharacterStrings)
	{
		wstring wideFox = L"The quick brown fox jumps over the lazy dog";
		
		// no conversion.... will work for US ASCII
		string slimFox(wideFox.begin(), wideFox.end());
		Assert::IsTrue(slimFox == quickBrownFox);

		wstring againWideFox(slimFox.begin(), slimFox.end());
	}

	TEST_METHOD(ConvertUTF8UTF16)
	{
		wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		wstring wide = converter.from_bytes(quickBrownFox);
		string narrow = converter.to_bytes(wide);

		Assert::IsTrue(narrow == quickBrownFox);
	}

	TEST_METHOD(StringLiterals)
	{
		char * builtIn = "ASCIII"; // narrow, multibyte
		wchar_t * builtInWide = L"WideCharacters"; // wide string UCS 16


		// from c++11, not yet supported in VS 2013
		/*char* utf8 = u8"Utf8-string Ʊ";
		char16_t* utf16 = u"Utf8-string Ʊ";
		char32_t* utf32 = U"Utf8-string Ʊ";*/


		// implicit conversion to string

		// Raw string literals, for multi-line
		string sql = R"(select *
from table
where x = y
)";
		string expected = "select *\nfrom table\nwhere x = y\n";
		Assert::AreEqual(sql, expected);
	}
};