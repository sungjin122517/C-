## **C++ Basics**

```cpp
int main () {...}
```

```cpp
int main (int argc, char** argv) {...}
```

#include will include information of a library (a collection of sub-programs).
e.g. #include <iostream> gets the information of the standard C++ library called iostream that deals with input/output (cin, cout)
*cerr: an object to print error message

The information of a user-defined C++ library can also be defined.
e.g. #include "???.h"

**expression of header files**:

"..." for user defined library

<...> for standard C++ library

**special characters**

'\t' =  tab, '\n' = new line, '\b' = backspace, '\0' = null character

Computer uses binary numbers (base 2) to represent data.
In the binary system,
- A digit has only 2 possibilities, {0, 1}
- e.g. $101 = 1*2^2+0*2^1+1*2^0$
- A binary digit is aka bit.
- 8 bits = 1 byte (smallest amount of data that a computer can "bite" at once.
- size of char datum: 1 byte

**pre-increment, ++x** → add 1 to x, and use the result for further operation.
**post-increment, x++** → use the current value of x for some operation, and then add 1 to x.

**shorthand notation**: '='앞에 연산부호 붙이기
