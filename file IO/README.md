In general, C++ allows you to _input/output data to/from files and devices_ (e.g. printer, hard disk, USB) using an abstraction called **stream**.

**stream**: a sequence of characters.

The data transferred between a C++ program and a file/device are modelled as a stream of characters, regardless of the data type (basic types; user-defined types). A device can also be treated like a file.

### Stream I/O operations

To perform I/O, create a **stream object** (from various stream classes) for each file.

These **stream objects** all support the 2 basic input/output operators: >>, <<

- >> and << _convert input/output data_ of the required type _from/to a sequence of characters_.
- The input operator >> _always skip whitespaces_ (spaces, tabs, newlines, formfeeds, carriage returns) before reading the next datum.

### Common stream member functions

Stream objects of various stream classes support the following **class member functions**:

- _open(const char* filename)_: create a stream and associate it with a file with the given filename.
- _close( )_: close a stream created by open( ).
- _eof( )_: check if the end of a file is reached.
- _get(char& c)_: get the next character into the variable c from an input stream.
- _getline(char* s, int max-num-char, char terminator='\n')_: get a stream of characters and put it into the char array pointed by the variable s. getline( ) stops when either:
    - (max-num-char - 1) characters are read, or
    - the stopping character terminator ('\n' by default) is seen.
    
    Notice that the stopping character is not read into the array, and the null character is automatically inserted at the end of s.
    
- _put(char c)_: put the character represented by the variable c onto an output stream.

### Interactive stream: iostream

<mark>**"iostream" = "istream" + "ostream"**</mark>   

_istream cin_: standard (or console) input, by default = keyboard

_ostream cout_: standard (or console) output, by default = screen

_ostream cerr_: standard (or console) error output, by default = screen.

### File stream: fstream

The header file "**fstream**" contains the definitions of 2 classes:

- "**ifstream**" : input file stream
- "**ofstream**" : output file stream

The **input file** must exist before you create an input file stream for it.

If the **output file** doesn't exist when you create its output file stream, it will be created for you. If it already exists, its content will be erased, and overwritten by the new output data.

Create an **input file stream** from a file called "input.txt" and an **output file stream** associated with a file called "output.txt".

```cpp
Two ways of opening a file stream:

#include <fstream>
// [1] Use a special form of ifstream/ofstream constructor
ifstream ifs("input.txt");
ofstream ofs("output.txt");

// [2] Use the default form of istream/ofstream constructor,
//     and then their open() member function
ifstream ifs; ifs.open("input.txt");
ofstream ofs; ofs.open("output.txt");
```

```cpp
Close a file stream by:

ifs.close();
ofs.close();
```
