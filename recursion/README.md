In programming, recursion means that a function calls itself.

**Advantages of recursion:**

- easier to write
- easier to read (understand)
- shorter (in codes) → greater productivitiy

**Disadvantages of recursion**:

It usually requires more memory and more computational time. Why?

Whenever a function is called, the computer:

- has to memorize its current state, and passes control from the caller to the callee.
- sets up a new data structure called **activation record** which contains information such as
    - where the caller stops
    - what actual parameters are passed to the callee
    - new local variables created by the callee function
    - the return value of the function at the end
- removes the **activation record** of the callee when it finishes.
- passes control back to the caller.

For the code 'factorial-main-debug',

If you enter n = 20, you will get get a negative number. Why?
This is because the factorial value for the integer 20 is too large to be stored in 32-bit. Therefore, from factorial(17), you will get a negative value.

대체 방안 → change data type of 'result' and 'fac_n' from **int to long long**.
