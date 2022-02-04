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

### 2021.11.15 월

### Linked list

**Create linked list**

1. create new node and add to head or tail.

```cpp
//adding to the head
new_node->next = head;
head = new_node;
```

```cpp
//adding to the tail
1. create new_node
2. check whether p is pointing to the last node
	if p->next == nullptr
3. p->next = new_node;
```

**Insert a new node**

```cpp
1. create new_node
2. spot insertion point using working pointer p
3. point new node to p->next (new_node->next = p->next)
4. p→next = new_node
```

**Delete a node**

```cpp
1. search for specific node to be deleted
2. p = node to be deleted
3. prev->next = p→next;
4. delete p;
5. p = nullptr;
```

### 2021.11.19 금

**Delete all nodes in the linked list**

```cpp
while (head != nullptr) {
		p = head;
		head = head->next;
		delete p;
}
```

variable에 각 array element 주소를 저장해서 각 element를 변형할 수 있다.   

--------------------------
### self study: 배열, 문자열, 포인터와 레퍼런스 (소년코딩 참조)

### Passing arrays to functions

만약 배열이 크면 배열을 복사하는 것은 매우 비싼 작업일 수 있으므로 C++은 배열이 함수로 전달될 때 배열을 복사하지 않고 실제 배열을 전달한다. 이는 배열 요소의 값을 직접 변경할 수 있는 부작용이 있다.
그럴땐, 배열을 const로 만들면 배열 요소를 수정하지 못 한다.

### C-style string

C-style string: string that ends with null terminator '\0'.

C 스타일 문자열을 출력할 때 std::cout은 null terminator를 만날 때까지 문자를 출력한다.

***cin.getline(name, num)*** → 최대 num자를 name으로 읽을 수 있다. **이러한 방법으로 오버플로를 하지 않도록 보장한다**.

**<cstring> 함수들**:

- *strcpy(dest, source)* → copy string array 'source' into another string array 'dest'.
- *strlen(name)* → return length of string array.
- *strcat()* → 한 문자열을 다른 문자열에 추가한다.
- *strcmp()* → 두 문자열을 비교한다 (같은 경우 0 반환).
- *strncmp()* → 두 문자열을 지정된 문자 수만큼 비교한다 (같은 경우 0 반환).

**C-style string**을 사용해야 하는 특별한 이유가 없다면 **std::string**을 사용하는 것이 좋다. **std::string**은 더 쉽고 안전하며 유연하다.

### Introduction to pointer

Pointer variable can only point to a variable of the same type.
Pointer variable cannot point to a constant (constant doesn't have memory address).
포인터에 리터럴 메모리 주소를 직접 할당할 수도 없다.

포인터의 크기는 항상 같다. 이는 포인터가 메모리 주소일 뿐이며 주어진 시스템에서 메모리 주소에 접근하는 데 필요한 비트 수는 항상 일정하기 때문이다.

garbage pointer/null pointer를 역참조하면 응용 프로그램이 중단될 수 있다.

 

**What good are pointers?**

- 배열은 포인터를 사용하여 구현된다. 포인터는 배열을 반복할 때 사용할 수 있다 (배열 인덱스 대신 사용 가능).
- C++에서 동적으로 메모리를 할당할 수 있는 유일한 방법 (dynamic array allocation).
- 데이터를 복사하지 않고도 많은 양의 데이터를 함수에 전달할 수 있다.
- 함수를 매개 변수로 다른 함수에 전달하는 데 사용할 수 있다.
- 하나의 struct/class 포인터를 다른 struct/class에 두어 체인을 형성하는 데 사용할 수 있다. 이는 linked list 및 binary tree와 같은 고급 자료구조에서 유용하다.

### Pointer and array

배열 변수는 마치 포인터인 것처럼 배열의 첫 번쨰 요소의 주소를 가지고 있다.

**함수로 전달될 때 배열이 포인터로 변환되므로** 함수에서 배열을 변경하면 실제 배열을 변경하는 것과 같다.

### Pointer arithmetic and array indexing

ptr+1: ptr 뒤 메모리 주소를 반환하지 않고 ptr이 가리키는 객체의 다음 메모리 주소를 반환한다.
e.g. ptr이 정수를 가리키면, ptr+3은 ptr 이후에 3개의 정수 (12바이트)를 의미.

### Dynamic memory allocation with new and delete

동적: 움직이는 성격의

**static (정적) memory allocation**: 이러한 타입의 변수에 대한 메모리는 프로그램이 실행될 때 한 번 할당되며, 프로그램 수명 내내 지속한다.

**동적 메모리 할당**: 프로그램 실행 중에 필요한 메모리를 운영체제에 요청하는 방법. 이 메모리는 프로그램의 제한된 **stack memory**에서 할당되는 것이 아니라 **heap**이라는 운영체제에서 관리하는 훨씬 더 큰 메모리 풀에서 할당된다.

```cpp
int *ptr = new int;  //dynamically allocate an integer and assign the
                     //address to ptr so we can access it later.
*ptr = 7;  //assign value of 7 to allocated memory

delete ptr;  //return the memory pointed to by ptr to the operating system.
ptr = nullptr;  //set ptr to be a null pointer
```

dangling pointer나 null pointer를 역참조하지 않도록 주의해라.

**dangling pointer**: 할당이 해제된 메모리를 가리키는 포인터. 댕글링 포인터를 역참조하거나 삭제하면 정의되지 않은 동작이 발생한다.

방지하기 위해선, 여러 포인터가 같은 동적 메모리를 가리키는 것을 피하고 포인터를 삭제할 때 nullptr로 설정해라.

**memory leak**는 언제 생기나?

- 동적으로 할당된 메모리의 주소를 보유한 포인터에 다른 값이 할당될 때. 이 문제는 포인터를 재할당하기 전에 delete하여 해결 가능.
- 이중 할당.

### Dynamically allocating arrays

```jsx
int* array = new int[length];

delete[] array;

int fixedArr[] {1, 2, 3};  //okay
int* dyArr1 = new int[] {1, 2, 3};  //not okay
int* dyArr2 = new int[3] {1, 2, 3};  //okay
```

동적 배열은 명시적으로 길이를 선정해 선언해야 한다.

### Reference variable, 참조형 변수

reference (참조형)은 C++에서 지원하는 세 번째 변수 타입이다.

세 가지 종류:

1. non-const 값 참조형
2. const 값 참조형
3. r-value 참조형

참조형은 참조하는 값과 동일하게 작동한다. 이런 의미에서 참조형은 참조되는 객체의 별칭으로 사용된다. And they share the same memory space.

초기화된 후에는 다른 변수를 참조하도록 변경할 수 없다.

함수에 포인터 인수 전달하면 함수 안에서 포인터를 역참조하여 인수의 값을 직접 수정할 수 있었다. 이런 점에서 참조형은 유사하게 작동한다. 참조형 매개 변수는 인수의 별칭으로 사용되므로 참조 매개 변수를 사용하는 함수는 전달된 인수를 수정할 수 있다.

### Reference and const

const reference는 non-const, const, 및 r-value로 초기화할 수 있다.

```jsx
int value = 5;
const int& ref = value;  //create const reference to variable value

value = 6;  //okay
ref = 7;  //illegal
```

상수를 가리키는 포인터처럼 const 값에 대한 참조는 const가 아닌 값을 참조할 수 있다. 이때 참조 접근을 하면 const가 아니어도 const로 간주한다.   
	
### l-values and r-values

l-value: 메모리 주소를 가진 객체

r-value: 메모리 주소가 없고, 표현식 범위에만 있는 임시 값 (literal constant 같은)

```cpp
초기화된 후에는 다른 변수를 참조하도록 변경할 수 없다

int value1 = 5;
int value2 = 6;

int& ref = value1;
ref = value2;    // assigns 6 to value1- does NOT change the reference!
```

참조형 매개 변수는 인수의 별칭으로 사용되므로 참조 매개 변수를 사용하는 함수는 전달된 인수를 수정할 수 있다.

참조형의 또 다른 장점: 중첩된 데이터에 쉽게 접근할 수 있게 한다. (references as shortcuts)

```cpp
// const 참조는 non-const 값, const 값 및 r-value로 초기화할 수 있다

int x = 5;
const int& ref1 = x;

const int y = 7;
const int& ref2 = y;

const int& ref3 = 6;

------------------------------
int value = 5;
const int& ref = value;    // create const reference to variable value

value = 6;    // okay since value is non-const
ref = 7;    // not okay since ref is const
```
