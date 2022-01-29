## Part I. Separate Compilation

Good reasons for putting each function in a **separate .cpp file** of its own:

- can easily reuse a function in another program.
- In a big project, programmers work in a team. Each programmer writes only some functions.
- If a function needs to be changed, only one file needs to be modified.

**How to compile the separate files into one single executable program?**

### Solution 1. Separate compilation

In order that each file can be separately compiled on its own, each file must know the existence of every variable, constant, function that it uses.

All global constants, variables, functions that are used in a file "A" but are defined in another file "B" must be declared in file "A" before they are used in the file.

- global constants: repeat their definitions
- external variables: add the keyword **extern**
- external functions: add their function prototypes. The keyword extern is optional since all C++ functions are global anyway.

"**extern**" in front of a variable/function → the variable/function is **global** and is *defined in another file*.

Usually put all external declarations at the top of a file.   

**Procedure**

```cpp
#1

**Bad example**
g++ -o odd-even main.cpp even.cpp odd.cpp   
// this will again compile all files even if you may only change one of the file.

**Better to compile them separately**
g++ -c main.cpp    // produce an object file "main.o" for the source file "main.cpp"
g++ -c even.cpp    // same
g++ -c odd.cpp     // same
g++ -o odd-even main.o even.o odd.o
/* invokes the linker to link/merge the separate object files into 
one single executable program "odd-even". */
```

If you later modify **only** "main.cpp", you just need to re-compile "main.cpp" and re-link all object .o files.

```cpp
g++ -c main.cpp
g++ -o odd-even main.o even.o odd.o
```

terminal에 pwd 입력하면: 내가 지금 어디있는지 알려줌.

cd separate1 → separate1 이라는 폴더로 가라
하고 pwd 다시 치면 separate1이라는 폴더로 옮겨간 걸 볼 수 있다

ls → list out all the files

rm 'hello'→ remove the file named 'hello'.

**순서:**

1. pwd
2. ls

rm *.o 의미: .o로 끝나는 파일 다 remove 해라

Makefile 제대로 갖춰져 있으면 make 하나만 쳐버리면 object file들이 자동으로 만들어짐(수동으로 했던게 다 됨)   

### Solution 2: header files

In solution 1, you see that many global variable or function *declarations* are repeated in “odd.cpp” and “even.cpp”. That is undesirable because:

- we do not want to **repeat** writing the same *declarations* in multiple files.
- should a *declaration* require updating, one has to go through all files that have the declaration and make the change.
- most importantly, maintaining **duplicate information** in multiple files is *error-prone*.

The solution is to use **.h header** files which contains:

- **definitions** of global variables and constants.
- **declarations** of global variables and functions.

Header files are inserted to a file by the preprocessor directive ***#include***.
