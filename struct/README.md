### Part I. C++ Structure

struct: user-defined data type

**structure**: a collection of heterogeneous objects (여러 다른 종류들로 이루어진)

**member**: each object in a struct. The data types of various members of a struct can be the same or different. (can be basic data type, user-defined data type, or pointer to the new struct currently being defined).

```cpp
struct Point {    // Point라는 struct안에 x와 y라는 member를 형성
	double x;
	double y;
} 

Point a, b    // a, b는 point라는 struct의 종류. They contain garbage.

// initialize a Point struct by memberwise assignments
a.x = 24.5
a.y = 123.0
```

```cpp
struct Example {
	int x;
	float y[5];
}

// struct-struct assignment by memberwise copy between two structs
Example a, b;
b = a;
```

```cpp
// initialization of a struct variable when it is defined
Point a = {24.5, 123.0}

// if not initialized during its definition, later its members
// can only be modified using:

b.x = 24.5;
b.y = 123.0;    // separate memberwise assignments (if no similar object to copy from)

, or
b = a;    // struct-struct assignment
```
