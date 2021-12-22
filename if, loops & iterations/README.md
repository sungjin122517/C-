### if-else statement

```cpp
if (<boolean expression>)
{
	<statements>
}
else if (<bool-exp>)
{
	<statements>
}
else
	<statement>
```

### logical operators

3 logical operators in C++:

- `!` : logical NOT
- `||` : logical OR
- `&&` : logical AND

### boolean values

- true: internally represented by 1, and any non-zero numbers.
- false: internally represented by 0.

![Precedence and Associativity of Boolean Operators (in decreasing order of precedence)](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b26b303e-d78d-4e1b-841e-dede5c29ca42/precedence_and_associativity_2.png)

```cpp
// if-else expression

(<bool-exp>) ? <then-exp> : <else-exp>;
```

```cpp
// Example: get the larger of two numbers
larger = (x > y) ? x : y;

// Example: get the letter grade from the percentile
grade = (percentile >= 85) ? 'A'
				: ((percentile >= 60) ? 'B'
					 : ((percentile >= 15) ? 'C'
							: ((percentile >= 5) ? 'D' : 'F'
								)
						 )
					);
```

### Loops and Iterations

```cpp
while (<bool-exp>)
{
	<statements>
}
```

- (Which loop to use?) Used when you want to repeat an action but do not know exactly how many times it will be executed.

```cpp
do
{
	<statements>
}
while (<bool-exp>);
```

- <statements> in do-while loop will be executed at least once, whereas <statements> in while loop may not be executed at all.

```cpp
for (<for-initialization> ; <bool-exp> ; <post-processing>)
	{
		<statements>
	}
```

- main idea of for statement: to control the number of iterations, usually by a counter variable.
- the <post-processing> part is executed after <statements>.
- (**Which loop to use?**) Used when you know how to specify the required number of iterations. **Also** when the counter variable is needed for computation inside the loop.
- *remarks: <for-initialization>에서 쓰이는 variable은 for loop을 탈출하면 사라진다. 그러므로 그 variable은 다시 사용하지 못 한다.

### Nested Loops

- A `break` causes the innermost enclosing loop to exit immediately.
- A `continue` causes the next iteration of the enclosing loop to begin.

![break and continue.PNG](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/32636e00-6036-4d0e-b272-f4b916cf16de/break_and_continue.png)
