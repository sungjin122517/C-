## Part I. Function Declaration and Function Definition

### Function prototype

prototype: 원형
immaterial: 중요하지 않은; 무형의, 실체가 없는

A **function prototype** consists of:

- function name
- return data type
- the number of formal parameters
- the data type of the formal parameters

The identifier names of the formal parameters are not part of the signature as the names are **immaterial**.

Technically, a function prototype is also called the **application programming interface (API)**.

### Function declaration vs. definition

1. A function is **declared** by writing down its interface- its function prototype, whereas a function is **defined** by writing down its function header + its function body.
2. A function **declaration** just informs the compiler about the function's interface without generating any _machine codes_, whereas a function **definition** will ask the compiler to generate machine codes according to the C++ codes in its function body.
3. A function may be **declared** many times, whereas a function can be **defined** only once. 
4. When a function is defined, it is also declared. But, simply declaring a function does not define the function.

- In C++, _all functions must be declared_ before they can be used, so that the complier can:
    - make sure the exact number of arguments are passed.
    - do type checking on the arguments passed to the function.
- That is, if function A wants to call function B, function B must be:
    - declared/defined before, or
    - declared inside function A before calling function B.
- However, _a function need not be defined_ before it can be used, although it must be defined eventually somewhere in the whole program in order that the program can be compiled to an executable.

선생님의 조언: 웬만하면 declare function globally 해라.
왜 declare globally라고 하냐? function들이 main function 밖에 있기 때문.

간단히 설명하면,
definition: every single detail related to the function. Can only define function once.
declaration: just interface. Can declare function many times.
****

## Part II. Function Overloading

In C++, all functions are global → all functions can 'see' each other.

A function's **signature**: list of formal parameters _without their identifier names_.

- Two functions having the _same name_ AND _same signature_, BUT _different return type_ → INVALID
- Two functions having the _same name_ BUT _different signature (different types of input parameters)_ → VALID due to **function overloading**

```cpp
Invalid function overloading

// identifier names of formal parameters are immaterial
int max(int x, int y) { return (x > y) ? x : y; }
int max(int a, int b) { return (a > b) ? a : b; }

// return type is not part of the signature
void swap(int& a, int& b) { int temp = a; a = b; b = temp; }
int swap(int& a, int& b) { int temp = a; a = b; b = temp; return a; }
```

### Function resolution

**Function resolution**: determination of exactly which overloaded function among those with the same name should be called.

Function resolution is done by comparing the types of:

- actual parameters passed in a function call, and
- formal parameters in the function definition.

and find the best match in the **following order**:

1. exact match
2. match after some type promotion
    1. char/bool/short → int
    2. float → double
3. match after some standard type conversion between:
    1. integral types
    2. floating types
    3. integral and floating types
4. match after some user-defined type conversion

refer to the example file "fcn-resolution"

### Default function argument

Function can have certain default behaviour, but it can still be changed.

- C++ allows the user to call a function with fewer arguments if all he wants is its default behaviour, and with more arguments if he wants some particular behaviour of the function.
- A function may have more than 1 default argument, but all default arguments must be specified at the end of the formal parameter list.

```cpp
// The following 2 prototypes are equivalent
void func(int x, float& y, char gender = 'M', bool alive = true);
void func(int, float&, char = 'M', bool = true);
```

- The default argument(s) may be specified in a function declaration or function definition, but not both (usually put on the function declaration).
