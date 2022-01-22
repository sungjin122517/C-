**Scope**: The region of codes in which an identifier declaration is active.

Programmers commonly talk about the following **2 kinds of scope**, though they are not official in C++'s standard:

- **global scope**: when an identifier is declared outside any function.
- **local scope**: when an identifier is declared inside a function.

Technically, there are at least 3 kinds of scope: **file scope**, **function scope**, and **block scope**.

### File scope

- Technical term for **global scope**.
- Variables with file scope are global variables and can be accessed by any functions in the same file or other files with proper external declarations.
- Unlike local variables, *global variables are initialized to 0* when they are defined without an explicit initializer.
- All function identifiers have file scope; thus, *all functions are global* in C++.
- Undisciplined use of global variables may lead to confusion and makes a program hard to debug.
    - try to avoid using global variables.
    - use only local variables, and pass them between functions.

### Function scope

- One kind of **local scope**.
- All variables/constants declared in the formal parameter list, or inside the function body have function scope.
- They are also called local variables/constants because they can only be accessed within the function and not by any other functions.
- They are **created** when the function is called, and are **destructed** when the function returns.

### Block scope

- One kind of **local scope**.
- Variables/constants in a block of codes enclosed within a pair of braces (body of for, while, do-while, if, else, switch, etc) have block scope.
- They are **created** when the function is called, and are **destructed** when the function returns.

### The notion of scope

2 variables/constants of the same name cannot be declared in the same scope even if they have different types.

However, the same identifier name may be re-used for variables/constants in different scopes.
The different scopes may not overlap with each other, or, one scope may be inside another scope.
