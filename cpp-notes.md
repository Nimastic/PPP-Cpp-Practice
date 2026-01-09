# C++ Learning Notes

A consolidated guide of C++ concepts learned while studying PPP (Programming: Principles and Practice Using C++).

---

## Table of Contents
1. [Compilation Process](#compilation-process)
2. [The main() Function](#the-main-function)
3. [Compiler vs Language Standard](#compiler-vs-language-standard)
4. [Type System](#type-system)
5. [Namespaces](#namespaces)
6. [Strings: Mutable vs Immutable](#strings-mutable-vs-immutable)
7. [Memory Management](#memory-management)
8. [C++ vs Java Comparison](#c-vs-java-comparison)

---

## Compilation Process

### Basic Compilation
```bash
c++ -o my_program my_file.cpp        # Single file
c++ -o my_program file1.cpp file2.cpp # Multiple files
```

### Two-Phase Process
1. **Compilation**: Each `.cpp` file → object file (`.o`)
2. **Linking**: Object files combined → executable

```
my_file1.cpp → [compile] → my_file1.o (contains function implementations)
my_file2.cpp → [compile] → my_file2.o (contains main())
                    ↓
            [link both together]
                    ↓
               my_program (executable)
```

### c++ vs g++
- On most systems, `c++` and `g++` are the same
- On macOS, both typically point to **Clang** (Apple's compiler)
- Check with: `c++ --version`

### Default Output
- Without `-o` flag, compiler creates `a.out` (not your source file name!)
- Always use `-o <name>` to explicitly name your executable

---

## The main() Function

Every C++ program **must** have exactly one `main()` function - it's the entry point.

```cpp
int main() {
    // Your code here
    return 0;  // 0 = success, non-zero = error
}
```

### Return Value (Exit Code)
- `return 0` sends an exit code to the OS, it does **NOT print** anything
- Check exit code in terminal: `echo $?`
- Used for scripting and automation

```bash
./my_program
echo $?    # Prints: 0 (if successful)
```

---

## Compiler vs Language Standard

**These are two separate things!**

### Compiler Versions (the software)
- Clang 15.0.0, 16.0.0, 17.0.0...
- GCC 12, 13, 14...

### C++ Language Standards (the language)
| Standard | Year | Notes |
|----------|------|-------|
| C++98 | 1998 | Original |
| C++03 | 2003 | Bug fixes |
| C++11 | 2011 | Major update! |
| C++14 | 2014 | |
| C++17 | 2017 | |
| C++20 | 2020 | |
| C++23 | 2023 | |

**Note**: There is no C++15! Standards are released every 3 years since C++11.

### Specifying a Standard
```bash
c++ -std=c++17 -o my_program my_file.cpp   # Use C++17
c++ -std=c++20 -o my_program my_file.cpp   # Use C++20
```

---

## Type System

### Fundamental (Built-in) Types
Part of the core C++ language - no namespace or header needed:

```cpp
int age = 25;           // Integer
double price = 9.99;    // Floating point
char letter = 'A';      // Single character
bool is_valid = true;   // Boolean
```

### Library Types
Defined in the C++ Standard Library - need `std::` prefix:

```cpp
std::string name = "Bob";       // String class
std::vector<int> numbers;       // Dynamic array
std::cout << "Hello";           // Output stream
std::cin >> input;              // Input stream
```

### Type Hierarchy
```
C++ Types
├── Fundamental/Built-in Types (no namespace)
│   ├── int, char, bool, double, float, etc.
│   └── Part of the language itself
│
└── Library Types (need std::)
    ├── std::string (class)
    ├── std::vector (class)
    ├── std::cout, std::cin (objects)
    └── Defined in standard library headers
```

---

## Namespaces

### Using std:: Prefix
```cpp
#include <iostream>
#include <string>

int main() {
    std::string name = "Bob";
    std::cout << "Hello, " << name << std::endl;
    return 0;
}
```

### Using Declarations
```cpp
using std::string;
using std::cout;

string name = "Bob";    // Now works without std::
cout << name;
```

### Using Directive (use sparingly)
```cpp
using namespace std;    // Brings ALL of std into scope

string name = "Bob";    // Works
cout << name;           // Works
```

**Best practice**: Use `std::` prefix or specific `using` declarations to avoid name conflicts.

---

## Strings: Mutable vs Immutable

### C++ Strings are MUTABLE
You can modify the string object directly in place:

```cpp
std::string name = "Bob";
name += "by";              // Modifies SAME object → "Bobby"
name[0] = 'R';             // Direct modification → "Robby"
```

**Memory**:
```
Before: [Object: "Bob"]
After:  [Object: "Robby"]  ← Same object, modified in place
```

### Java Strings are IMMUTABLE (for comparison)
Every "modification" creates a NEW object:

```java
String name = "Bob";
name = name + "by";        // Creates NEW object "Bobby"
                           // Old "Bob" is orphaned
```

### Why This Matters

**C++ - Efficient for modifications:**
```cpp
std::string result = "";
for (int i = 0; i < 10000; i++) {
    result += std::to_string(i);  // Same object grows
}
// Only 1 object modified 10,000 times!
```

---

## Memory Management

### Stack vs Heap

**Stack allocation** (automatic, preferred):
```cpp
void example() {
    std::string text = "Hello";  // Created on stack
    int number = 42;             // Created on stack
    
    // When function ends, memory is automatically freed
}
```

**Heap allocation** (manual, use when needed):
```cpp
void example() {
    std::string* ptr = new std::string("Hello");  // On heap
    // ... use ptr ...
    delete ptr;  // MUST manually free!
}
```

### No Garbage Collection
Unlike Java, C++ has **no automatic garbage collection**:

| Allocation | Cleanup |
|------------|---------|
| Stack (local variables) | Automatic when scope ends |
| Heap (`new`) | Manual with `delete` |

### Memory Leaks
**Memory leak** = memory allocated but never freed (and no way to access it):

```cpp
// ❌ MEMORY LEAK!
void leak() {
    std::string* ptr = new std::string("Hello");
    // Function ends without delete
    // Memory is LOST FOREVER
}

// ✅ No leak
void noLeak() {
    std::string text = "Hello";  // Stack - auto cleanup
}
```

### Best Practices
1. **Prefer stack allocation** when possible
2. **Use smart pointers** for heap allocation:
   - `std::unique_ptr` - single ownership
   - `std::shared_ptr` - shared ownership
3. **RAII principle** - tie resource lifetime to object lifetime

---

## C++ vs Java Comparison

| Feature | Java | C++ |
|---------|------|-----|
| String type | Built-in `String` class | Library `std::string` |
| String mutability | Immutable | Mutable |
| Universal base class | `Object` | None |
| Wrapper classes | Yes (`Integer`, etc.) | Not needed |
| Primitives in generics | No (need wrappers) | Yes (templates) |
| Organization | Packages | Namespaces |
| Memory management | Garbage collected | Manual / RAII |
| Compilation | Bytecode (JVM) | Native executable |

### String Modification Comparison

**Java** (creates new objects):
```java
String text = "Hello";
text = text.toUpperCase();  // New object created
                            // Old "Hello" orphaned → GC cleans up
```

**C++** (modifies in place):
```cpp
std::string text = "Hello";
std::transform(text.begin(), text.end(), text.begin(), ::toupper);
// Same object modified → "HELLO"
```

---

## Range Checking

### Two Ways to Access Elements

| Method | Range Checking | What Happens on Error |
|--------|----------------|----------------------|
| `vec[i]` | ❌ No | Undefined behavior |
| `vec.at(i)` | ✅ Yes | Throws `out_of_range` |

```cpp
std::vector<int> numbers = {10, 20, 30};

numbers[100];      // ❌ Dangerous! Undefined behavior
numbers.at(100);   // ✅ Safe! Throws exception
```

### Using .at() for Safety
```cpp
try {
    cout << numbers.at(100);
} catch (out_of_range& e) {
    cout << "Error: Index out of range!";
}
```

**Best practice**: Use `.at()` when learning or when safety is critical.

---

## Quick Reference: Output Syntax

### Separate Statements
```cpp
std::cout << "Line 1\n";
std::cout << "Line 2\n";
std::cout << "Line 3\n";
```

### Chained Statements (equivalent)
```cpp
std::cout << "Line 1\n"
          << "Line 2\n"
          << "Line 3\n";
```

Both produce identical output. Chaining is common in C++.

---

*Notes compiled while learning from PPP 3rd Edition*

