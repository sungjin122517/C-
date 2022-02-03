### lvalue & rvalue

**lvalue**: location of the memory storage (read-write).

**rvalue**: value in the storage (read-only).

**++x: pre-increment operator**

1. requires x to be passed-by-reference
2. modify x by incrementing it by 1
3. returns incremented x by reference
4. returned x == lvalue

**x++: post-increment operator**

1. requires x to be passed-by-reference
2. saves the current value of x in some temporary local variable
3. modify x by incrementing it by 1
4. returns the old value of x in the local variable by value
5. returned x == rvalue

```cpp
pre-increment (++++++x) -> return lvalue (return by reference) (address of x)
post-increment (x++++++) -> return rvalue (return by value)
```

예를 들어 x에 20이라는 숫자를 assign한다.
x=20은 int니깐 4 bytes. (20을 저장하려면 4개의 주소/memory space가 필요하다)
20의 주소를 불러오고 싶다 → 주소가 0 1 2 3 이렇게 네 개가 있을텐데
불러오고 싶다면 starting address인 0만 불러오면 된다.

제일 많이들 헷갈려 하는거: the saving address itself becomes the content of the pointer.

```cpp
// pre-increment
int& g(int& x) {
		x += 1;
		return x;
}

// post-increment
int f(int& x) {
		int temp = x;
		x += 1;
		return temp;
}
```

address → give access to memory space, therefore can read&write

/* File: pointer-pointer.cpp */

### **2021.11.08 월**

### Constant pointer

일반 pointer variable은 initialize할 필요 없지만
const pointer variable은 initialize 필요하다.

```cpp
//const Pointer
int x, y
int* const a = &x;

a = &y;  //error. Once initialized, cannot be changed to point something else
*a = 5;  //okay. Free to change the content in the address it points to.

여기선 pointer a 자체가 const이기 때문에 a를 바꿀순 없고,
대신 a가 가리키고 있는 object의 content 변경은 가능하다.
```

```cpp
//pointer to const object -> ACCESS CONTROL

int x=10, y=20;
const int* q;  //q is variable. 
               //Not necessary to initialize a pointer to const object when defined.

q = &x;  //possible
q = &y;  //possible-> free to change the pointer itself to point to different objects

y = *q;  //read only이기 때문에 possible
*q = y;  //impossible to change the content of the object through pointer
y	=	30	 //but possible by changing the object directly.

위와 반대로 여기선 pointer q가 가리키고 있는 object 자체가 const이기 때문에
pointer를 통해서 object content를 바꿀순 없고,
대신 object 내용을 direct하게 변경 가능. 그리고 포인터 자체 변경도 가능.
```

```cpp
//const pointer to const object
int x, y;
const int* const p = &y;

x = *p;
p = &x;  //impossible since value of p cannot be changed.
*p = x;  //impossible (indirect access)
y = x;  //possible (direct access)
```

### 2021.11.12 금

### Part III. Pointer to structure

포인터 앞에 별(*) 붙혀서 주소에 저장 되어있는 값을 불러오는걸
indirect access라고 한다.

Two ways to access struct members through a pointer:

1. Dereference the pointer and use the . operator.
    
    e.g. (*ap).x = 10;
    
2. Directly use the → operator
    
    e.g. ap→x = 10;
    

### Part IV. Dynamic memory/objects allocation and deallocation

**static** memory allocation: 

- memory of all (local and global) variables allocated by the compiler during compilation.
- When these variables- static objects, go out of their scope, their memory are released automatically back to the computer's memory space (RAM).

**dynamic** memory allocation: 

- memory of dynamic objects has to be allocated at runtime explicitly by you, using the operator *new*.
- memory of dynamic objects will persist even after the object goes out of scope, so has to be deallocated at runtime explicitly by you → using the operator *delete*. *delete* releases memory pointed to by a pointer variable back to the heap for recycle.

There is no other way to access the unnamed memory allocated by the operator new except through the pointers.

The pointer variables are static objects. Only the unnamed memories returned by the *new* operator are **dynamic objects**.

**Common bug**

1. **Dangling pointer:** delete를 통해서 memory는 release 했지만 pointer variable still holds the address of the previously allocated unnamed memory.
Runtime error usually occurs when you try to dereference a dangling pointer.
    
    그래서 가지고 있으면 좋은 습관: always initialize a pointer to nullptr when defining a pointer variable, and always check whether a pointer is a nullptr before using it.
    
2. **Memory leak**
- occurs when dynamically allocated memory that is no longer needed is not released.

### Part V. A dynamic data structure: Linked list

List: linear sequence of objects.

You may implement a list by an **array**.
**adv**: array works well with **loops** and **recursion.
disadv**: **size** of the array is determined in advance.

**Linked list**

**adv**: It is *dynamic*; it grows and shrinks to any size as you want at runtime.
**disadv**: *requires additional memory* for the linking pointers, and *takes more time* to manipulate its items.

**node**: each object in a linked list

typical C++ definition for a node in a linked list: struct

```cpp
struct ll_node {
	<type> data;  // contains useful information
	ll_node* next;  // the link to the next node
}
```

last node→ its next pointer is set to nullptr to tell that it is the end of the linked list.

pointer variable(head) required to point to the first node.
