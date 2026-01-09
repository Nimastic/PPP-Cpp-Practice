An object is a region of the memory with a type that specifies what kind of information can be placed in it
named object = variable

C++ Type Hierarchy

C++ Types
├── Fundamental/Built-in Types (no namespace)
│   ├── int, char, bool, double, float, etc.
│   └── Part of the language itself
│
└── Library Types (need std::)
    ├── std::string (object/class)
    ├── std::vector (object/class)
    ├── std::cout, std::cin (objects)
    └── Defined in standard library headers

value after "=" is called an initialiser

by convention, reading of strings is terminated by whitespace

## C++ Operators by Type

| Operation | bool | char | int | double | string |
|-----------|------|------|-----|--------|--------|
| **Assignment** `=` | ✅ | ✅ | ✅ | ✅ | ✅ |
| **Addition** `+` | ❌ | ✅* | ✅ | ✅ | ✅** |
| **Subtraction** `-` | ❌ | ✅* | ✅ | ✅ | ❌ |
| **Multiplication** `*` | ❌ | ✅* | ✅ | ✅ | ❌ |
| **Division** `/` | ❌ | ✅* | ✅ | ✅ | ❌ |
| **Modulo** `%` | ❌ | ✅* | ✅ | ❌ | ❌ |
| **Comparison** `==` `!=` | ✅ | ✅ | ✅ | ✅ | ✅ |
| **Relational** `<` `>` `<=` `>=` | ❌ | ✅ | ✅ | ✅ | ✅*** |

\* `char` can use arithmetic because it's treated as a small integer (ASCII value)  
\*\* For `string`, `+` means **concatenation** (joining strings), not addition  
\*\*\* For `string`, comparison is **lexicographical** (dictionary order)

### Examples:

**int / double:**
int a = 10, b = 3;
a + b;     // 13
a - b;     // 7
a * b;     // 30
a / b;     // 3 (integer division!)
a % b;     // 1 (remainder)

double x = 10.0, y = 3.0;
x / y;     // 3.33333... (floating division)
x % y;     // ❌ ERROR! Modulo doesn't work with double**string:**
std::string s1 = "Hello";
std::string s2 = "World";
s1 + s2;        // "HelloWorld" (concatenation)
s1 + " " + s2;  // "Hello World"
s1 - s2;        // ❌ ERROR! Can't subtract strings
s1 * 2;         // ❌ ERROR! Can't multiply strings**char:**
char c = 'A';
c + 1;          // 'B' (ASCII: 65 + 1 = 66)
c + 32;         // 'a' (uppercase to lowercase)
'Z' - 'A';      // 25 (difference between letters)**bool:**
bool flag = true;
flag = false;   // ✅ Assignment works
flag + 1;       // ❌ Don't do this (though technically possible)
!flag;          // ✅ Logical NOT
flag && true;   // ✅ Logical AND
flag || false;  // ✅ Logical OR

string:
std::string s1 = "Hello";
std::string s2 = "World";
s1 + s2;        // "HelloWorld" (concatenation)
s1 + " " + s2;  // "Hello World"
s1 - s2;        // ❌ ERROR! Can't subtract strings
s1 * 2;         // ❌ ERROR! Can't multiply strings

char:
char c = 'A';
c + 1;          // 'B' (ASCII: 65 + 1 = 66)
c + 32;         // 'a' (uppercase to lowercase)
'Z' - 'A';      // 25 (difference between letters)

bool:
bool flag = true;
flag = false;   // ✅ Assignment works
flag + 1;       // ❌ Don't do this (though technically possible)
!flag;          // ✅ Logical NOT
flag && true;   // ✅ Logical AND
flag || false;  // ✅ Logical OR


**Key Takeaways:**
- **Modulo `%`** only works with integers (`int`, `char`), NOT `double`
- **String `+`** is concatenation, not math
- **char** behaves like a small integer for arithmetic
- **bool** is mainly for logic, not arithmetic

char c = 'x'
int i1 = c // makes this 120 as x = 120 in ACSII value
