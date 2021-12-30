## Part 1. 1-Dimensional Array

`Array`: a collection of homogeneous objects (objects of the same type).
*Array elements cannot be reference variables*.

```cpp
<data-type> <array-name> [<size>];    // <size>=**positive constant**
```

contiguous: 인접/근접한   
Successive elements are stored in contiguous memory.  
Each array element is treated like regular variable. You may:

- assign a value to it.
- assign its value to another variable.
- pass it by value or reference to a function.

C++ compiler does not automatically check that an array index is out of bound, neither at compile-time nor run-time. For example,

```cpp
int x[10];
x[-2] = 5; x[100] = 9;

When the codes are run,
x[-2] = 5 will put the value 5 to the memory space which is 2*4 bytes
before the array x.
x[100] = 9 will put the value 9 to the memory space which is 90*4 bytes
beyond the array x.
```

This is a common cause of the *run-time error* called `segmentation fault`- your program trespasses into memory locations that may not belong to it.

trespass: 무단 침입하다

### Array initialization

- If there are fewer values than the array size, the unspecified values will be zeros.
- It is a *compilation error* if there are more values than the array size.
- If the array size in the array initialization is left out, the compiler will count the number of initializing values and uses that as the array size.
- Once defined, you CANNOT assign values to an array using the initialization syntax.
- You can't declare an array of references.

```cpp
// Compilation error!
double x = 1.5, y = 2.5, z = 3.5;
double& s[] = {x, y, z}
```

### Pass a 1D array to a function

**Arrays as function arguments**

A function that operates on an array needs at least 2 input arguments:

- array identifier (just by its variable name)
- array size (of type int)

An array variable is always passed by value. However, its elements are effectively passed by reference.

*It would be a good programming practice to make an array 'read only' by making the array argument **const**.

In the example code "random-element.cpp" (p.20),→

```cpp
int element_rbv() → // pick up random element and **return its value.**
int& element_rbr() → // pick up random element and **return access to its memory space**.
```

### Constant array

- It must be initialized when it is defined.
- Once defined, its elements cannot be modified.

One main use is in the *definition of the formal parameters of a function*:
Array constant is declared using **const** to disallow modification of the elements of an array passed to a function.   
Inside the function, the array is read-only. However, the original array in the caller is still writable.

## Part II. Multi-dimensional Array

**Initialization of 2D array: 2 ways**

- row by row
- like a 1D array, since the array cells(elements) are actually stored **linearly** in the memory (same for every multi-dimensional array).

```cpp
//row by row
int point[5][2] = {
	{1, 1}
	{2, 4}
	{3, 9}
	{4, 16}
	{5, 25}
};

//like 1D array
int point[5][2] = { 1,1, 2,4, 3,9, 4,16, 5,25 };
```

**Remarks**

- memory address of A[i][j] = start + ( i rows * N ) * sizeof(int), where N for total number of columns in A[M][N].
- In C++, the elements of a multi-dimensional array are stored in **row-major order** (row by row).
In row-major order, the last dimension index runs fastest, while the first dimension index runs slowest.
- All dimensions other than the first dimension must be specified in its declaration in the function header.

## Part III. C String: Special 1D Character Array

Representing a character string (C string) by a 1D character array: adding the null character **'\0'** after the last character of the string.   
For a string of length N, '\0' becomes the (N+1)th element of its char array.

Another notation using the double quotes:   
"hkust" = 'h' 'k' 'u' 's' 't' '\0'

### Reading C strings with cin

*cin* will skip all white spaces before reading data of the required type until it sees the next white space.
Thus, cin >> is not good at reading multiple words or even a paragraph including possibly the newline. Instead, use:

```cpp
cin.getline(char s[], int max-num-char, char terminator);
```

*cin.getline( )* will stop when either (max-num-char - 1) characters are read OR terminating character *terminator* is seen. The terminating character is removed from the input stream but is not read into the string.

The C-string terminating null character is automatically inserted at the end of the read string.
