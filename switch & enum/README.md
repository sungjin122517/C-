### switch Statement

It is a variant of the if-else if statement, that allows multiple choices based on the value of an integral expression.

![switch Statement.PNG](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/218bf1c4-e48b-454e-8345-936913776913/switch_Statement.png)

```cpp
switch (integral expression)
{
		case constant-1:
				statement-sequence-1;
				break;
		case constant-2:
				statement-sequence-2;
				break;
		...
		case constant-N:
				statement-sequence-N;
				break;
		default:    // optional
				statement-sequence-(N+1);
}
```

Difference between a `switch` statement and a `if-else if` statement:

- switch statement can only test for *equality* of the value of one quantity, whereas each expression of the if-else if statement may test the *truth value* of different quantities or concepts.

### New data types with enum

One way to define a **new data type** is to use the keyword `enum`.

```cpp
enum datatype {identifier1 [=value1], identifier2 [=value2], ...};
```

```cpp
enum weekday { MON, TUE, WED, THU, FRI, SAT, SUN};    // 0, 1, 2, 3, 4, 5, 6
enum primary_color { RED = 1, GREEN, BLUE };    // 1, 2, 3
enum bloodtype { A, B, AB = 10, O };    // 0, 1, 10, 11
```

- An `enumeration` is a **data type** that can hold a finite set of symbolic objects.
- The symbolic names of these objects follow the same rule as identifier names. They make your program easier to read and understand.
- Internally, these objects are represented as integers. By default, the first object is given the value zero, then each subsequent object is assigned a value one greater than the previous object's value.
- The integral values of the enumerated objects may be assigned other integral values by the programmer.
- Thus, the objects of an enum type act like named integer constants.
