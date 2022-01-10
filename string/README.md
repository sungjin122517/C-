**C strings** consist of a sequence of characters terminated by the ‘\0’ character, and are stored as *char* arrays.

C string is not a basic data type so its operations are provided by a set of functions defined in the ***cstring** library*.

```cpp
**CONSTRUCTORS**

Default constructor: to create an empty string.
	string s;    // s is ""

To create a string from n copies of a character.
	string rating(3, 'A');    // rating is "AAA"

To create a string object from a C string.
	string s1("hello");
	string s2 = "hello";    // both are "hello"

To create from a substring of a C string.
	string s("hello", 4);    // s is "hell"

**ASSIGNMENT AND CONCATENATION**

To assign one string object to another string object.
	string s1("thank"), s2;    // s1 is "thank", s2 is ""
	s2 = s1;     // s2 is "thank" too

To assign a C string to a string object.
	string s; s = "good"

To assign a character to a string object.
	string s; s = 'A';   // s is "A"

To concatenate 2 string objects.
	string s1("thank"), s2 = "you";
	string s3;
	s3 = s1 + " " + s2;    // s3 is "thank you"
	s1 += s2;    // s1 is "thankyou"

**BASIC I/O**

To read one word into a string object.
	string s;
	cin >> s;    // skip leading whitespaces

To output a string object to the console
	string s = "hkust";
	cout << s;    // output "hkust" to the screen

To get one line of text until a newline or other delimiter character.
	string s;
	getline(cin, s);    // read until a newline character
	getline(cin, s, 'X');    // read until an 'X' which is not read in
                           // but DISCARDED. Next input starts after 'X'

**ACCESSING INDIVIDUAL CHARACTERS**

To get the number of characters in a string object,
	string s = "hkust";
	cout << s.length();    // output is 5

Two ways to get the jth character of a string object:
1. use the subscript operator [] like the C strings
	 0 <= j <= length()-1 (don't have to worry about the terminating NULL character,
				which will be handled by the class.)
	 if the index j > length()-1, the behaviour is undefined.
2. member function at()
	string s = "hkust";
	cout << s.at(1);    // output is 'k'
	s.at(9) = 'a';    // runtime error

**STRING COMPARISONS**

compare() function: s1.compare(s2)

returns 0 if the strings are the same.
returns a positive number if s1 is lexicographically greater than s2.
returns a negative number if s1 is lexicographically smaller than s2.

**SUBSTRINGS**

To get a copy of the substring of s starting at the index j,
consisting of N characters.
	****s.substr(j, N);

**FIND AND COMPARE**

To search for the first occurrence of a substring s2, starting from the
jth character of current string object s.
	s.find(s2, j);
	s.rfind(s2, j);    // similar to find() but search backwards

To replace the substring of s that consists of N characters and starts at the
jth character by s2.
	s.replace(j, N, s2);

```
