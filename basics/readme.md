## **C++ Basics I**

```cpp
//simple form of the main function

int main () {...}
```

```cpp
//general form of the main function

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
- A binary digit is aka bit.
- 8 bits = 1 byte (smallest amount of data that a computer can "bite" at once.)

**pre-increment, ++x** → add 1 to x, and use the result for further operation.  
**post-increment, x++** → use the current value of x for some operation, and then add 1 to x.

**shorthand notation**: '='앞에 연산부호 붙이기

## **C++ Basics I**
  
## Part I. More Basic Data Types in C++

![basic data types.PNG](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/26729aba-0ac8-4ca8-9810-d8c89ade5459/basic_data_types.png)

- A 32/64 bit machine uses CPUs of which the data bus (다른 컴퓨터 시스템 간을 흐르는 데이터 회로) width and memory address width are 32/64 bits.

### Integers

- Type names: short (int), int, long (int), long long (int).
- Each integral data type has 2 versions:
    - signed version (both +ve and -ve integers)
    - unsigned version (only +ve integers)
    - unsigned int can represent 2 times more +ve integers than signed int.

### Floating-point data types

- `Floating-point numbers` are used to represent real numbers and very large integers (which cannot be held in 'long long').
- Type names:
    - float for single-precision numbers
    - double for double-precision numbers
- In scientific notation, a number has 2 components. e.g. 5.16E-02
    - mantissa: 5.16 (more mantissa bits → higher precision)
    - exponent: -2 (more exponent bits → larger real number)
- Binary representation of mantissa: e,g,
    
    $1.011_2 = 1\times 2^0 + 0\times 2^(-1) + 1\times 2^(-2) + 1\times 2^(-3)$
    
- Binary representation of exponent: signed integer.

```cpp
cout.precision(10);    // set output precision to 10 sig. figures
cout << boolalpha;     // print boolean outputs as true or false
cout << noboolalpha;   // print boolean outputs as 1 or 0.
```

### Underflow and overflow in integral data types

- Overflow: occurs when a data type is used to represent a number larger than what it can hold. e.g.
    - if you use a short int to store HK's population.
    - when a short int has its max value of 32767, and you want to add 1 to it.
- Underflow: occurs when a data type is used to represent a number smaller than what it can hold. e.g.
    - use an unsigned int to store a -ve number.

### Underflow and overflow in floating-point data types

- Overflow: when the +ve exponent becomes too large to fit it the exponent field of the floating-point number.
- Underflow: when the -ve exponent becomes too large to fit in the exponent field of the floating-point number.
- To prevent these from happening, use double if memory space allows.
- In fact, all floating literals (e.g. 1.23) is treated as double unless explicitly specified by a suffix (e.g. 1.23f).

## Part II. Type Checking and Type Conversion

### Operand coercion

`Coercion 강제/강압` is the automatic conversion of the data type of operands during an operation. 

- e.g. 3 + 2.5 (int + double) → 3.0 + 2.5 (double + double), automatically changed by the C++ compiler.
- Thus, the integer 3 is coerced to the double 3.0.

```cpp
char small_y, big_y;
cin >> small_y;                 // character in small case
big_y = small_y + 'A' - 'a';    // character in big case
```

Here big_y, small_y, 'A', and 'a' are coerced by promoting it to int before addition. The result is converted back to char.

### Priority rules for the usual arithmetic conversions for binary operations

- If either operand is of type long double / double / float , convert the other operand also to the corresponding type (long double / double / float).
- Otherwise, the integral promotions shall be performed on both operands.

### Automatic type conversion

- A `narrowing conversion` changes a value to a data type that might not be able to hold some of the possible values.
- A `widening conversion` changes a value to a data type that can accommodate any possible value of the original data.
- C++ uses `truncation 끝을 잘라냄, 절두` rather than rounding in converting a float | double to short | int | long.

### Manual type conversion (casting)

```cpp
static_cast<data-type> (value)    // static_cast for manual type casting

e.g.
int k = 5, n = 2;
float x = static_cast<double>(n) / k;
float y = n / static_cast<double>(k);
float z = static_cast<double>(n) / static_cast<double>(k);
```

## Part III. Constants

### Literal constants

- Constants represent fixed values, or permanent values that cannot be modified (in a program).
- Examples of `literal constants`: char, string, int, double.

### Symbolic constants

- A named constant with an identifier name which is written in capital letters by convention.
- It must be defined and/or declared before it can be used. Once defined, it cannot be changed.

```cpp
const <data_type> <identifier> = <value>;    // constant definition

e.g.
const char BACKSPACE = '\b';
const float US2HK = 7.80;
const float HK2RMB = 0.86;
const float US2RMB = US2HK * HK2RMB;
```

Compared with literal constants, `symbolic constants` are preferred because they are:

- more readable. A literal constant does not carry a meaning.
e.g. the number 320 cannot tell you that it is the enrollment  quota of COMP2011 in 2015.
const int COMP2011_QUOTA = 320;
- more maintainable. In case we want to increase the quota to 400, we only need to make the change in one place: the initial value in the definition of the constant COMP2011_QUOTA.
const int COMP2011_QUOTA = 400;
- type-checked during compilation.

Remark: Unlike variable definitions, memory is not allocated for constant definitions with only few exceptions.
