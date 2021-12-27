## Function Basics

### Basic function syntax

```cpp
<return-type> <function-name>(<formal-parameter-list>)    // function header
{
		<function body>
}
```

- **<formal-parameter-list>**, which is a list of comma-separated *variable declarations*, appears in the function definition.

```cpp
//function call

<function-name>(<actual-parameter-list>)
```

- **<actual-parameter-list>**, which is a list of comma-separated *objects* passed to the called function, appears in a *function call*. (actual parameters = arguments)

**Object**: something a function returns in C++. **Only one** object is returned in C++.

The returned object may be:

- a signal to tell the caller about the status of the function: does it run successfully, or does it fail? e.g. return 0;
- the result of some computation, e.g. factorial, sum, etc.
- a new object created by the function, e.g. a new window.

<return-type> can be any of the C++ built-in data types or user-defined types, **EXCEPT** the *array type*.

The **return statement** generally returns 2 things to the caller:

- program control: it stops running the called function, and the function caller takes back the control and continue its execution.
- an object: the object/value represented by the <expression> is returned to the caller.

A function that returns nothing back to the caller has a return type of **void**.

A function that does not take any arguments from the caller may

```cpp
// leave the <formal-parameter-list> emtpy.
int fcn_example() {...}
```

, or

```cpp
// put the <formal-parameter-list> as void.
void print_hkust(void) {cout << "hkust" << endl;}
```

## **Modular Programming**

Modular programming: Dividing a large program into modules, each of which is implemented by a function, and then solve each part in turn.

## Parameter Passing Methods

2 ways to pass arguments to a function:

1. **pass-by-value (PBV)**
- The value of an *actual parameter is copied into the formal parameters* of the function.
2. **pass-by-reference (PBR)**
- The value of an *actual parameter is **NOT** copied into the formal parameters* of the function.
- When an actual parameter is passed by reference, its corresponding formal parameter becomes its reference variable.
- e.g. on entering the swap function, the following codes are run:     
int& a = x;    int& b = y; 
→ The formal parameters a and b are declared as reference variables and are initialized or bound to their corresponding actual parameters x and y, respectively.
(Variable x and y is passed by reference to a and b. a and x, b and y share the same memory space.)

**Reference variable**

It is an alias of another variable. 
It must always be bound to an object. Therefore, it must be initialized when they are defined.
Once it is defined and bound with a variable, you cannot "re-bind" it to another object.

**Remarks**

All the local variables defined inside a function, including the formal parameters, are destroyed on return of the function call.

- These local variables are created every time the function is called.
- These local variables created on the current call are different from those created in the previous calls.
- However, if a formal parameter is a reference variable, only itself is destroyed when the function returns, the variable (actual parameter) bound to it still exists afterwards.

*Pass-by-reference* is more efficient when a large object has to be passed to a function as no copying takes place.
However, there is a risk that you may accidentally modify the object.

**const References as function arguments**

2 advantages of keeping a reference argument (that is passed to a function) unchanged by making it const:

1. If you accidently try to modify the argument in your function, the compiler will catch the error.

```cpp
// fine
void call_by_ref(int& x) { x += 10; }

// error!
void call_by_ref(const int& x) { x += 10; }
```

2. **const reference parameter가 필요한 function** → both const and non-const arguments can be passed.
    
    **non-const reference parameter가 필요한 function** → only non-const arguments can be passed.
    
    ![const reference.PNG](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b57062a6-0461-40c4-9540-85006efa6e8e/const_reference.png)
