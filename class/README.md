### Part I. What is a C++ class?

Struct와의 차이점:

- Functions are not global.

**Class (abstract data type, ADT)**= data member + member functions + access control

**data members**: just like data members in a struct.

**member functions**: a set of functions that work only for the objects of the class, and can only be called by them.

**Access control** to each data member and member function:

- **public**: accessible to any functions (both member functions of the class or other functions)
- **private**: accessible **ONLY** to member functions, which enforces information hiding.
- **protected**

```jsx
// General structure of class

class student_record {
	private:

	public:
		// CONSTURCTOR member functions: create and initialize
		// DESTRUCTOR member functions: destroy
		// ACCESSOR member functions: const -> read-only. Best to be in cpp file.
		// MUTATOR member functions: write
}
```

### Constructors and destructors

A class may have more than 1 **constructor** (function overloading), but only 1 **destructor**.

- The **default constructor** just reserves an amount of memory big enough for an object of the class. No initialization will take place (except for those with default values in C++).
- The **default destructor** just releases the memory acquired by the object.

**data members**: *contents* of the objects of a class. Usually they are made **private**.

**member functions**: represent the *interface* to the objects of a class. Usually they are made **public**.

**4 types of member functions**:

- **constructor**: *create* class object.
- **destructor**: *destruct* class objects. Needed only when objects contain dynamic data members.
- **accessor**: const functions to allow *read* by user. Do not modify any data members.
- **mutator**: will *modify* some data members.

### Summary: classes and objects

Class represents a set of objects with the same structure and behaviour.

Objects are variables of a class type.

**instantiation**: The process of creating an object of a class.

Each object of a class has its **own** copies and values of its data members.

All objects of a class **share** a common set of member functions.

**Class members** are private by default, whereas **struct members** are public by default.

### Part III.

Class member functions:

1. Declared inside the class body → **inline** functions. The keyword inline is optional in this case.
2. Declared outside the class body → add the prefix consisting of the class name and the class scope operator **::**
