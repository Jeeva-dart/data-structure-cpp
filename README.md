# Basics C++ Workspace — Detailed README

This workspace contains small C++ data structure implementations and utilities for learning and experimentation. The README documents each implemented data structure, its public methods, short usage examples, build/run/debug instructions, and troubleshooting notes.

## Table of contents

- Project overview
- Requirements
- Build & run
- Data structures (API + examples)
  - `SimpleArray<T>` (resizable array)
  - `SinglyLinkedList`
  - `DoublyLinkedList`
  - `CircularLinkedList`
  - `DoublyCircularLinked`
  - `InsertionSort`
  - `RandomLinkedListGenerator`
- Debugging in VS Code
- Common issues & fixes
- Next steps and suggestions


## Project overview

- Language: C++ (configured to C++23 in this workspace)
- Compiler: g++ (13.x recommended)
- Goal: educational examples and small implementations to read and extend


## Requirements

- g++ (13.x recommended)
- make (optional)
- Visual Studio Code (optional) with C/C++ extensions

Check compiler:

```bash
g++ --version
```

To check the C++ standard in use at runtime, compile and run a small program that prints `__cplusplus`.


## Build & run

### VS Code tasks
- Run: Command Palette (Ctrl+Shift+P) → `Tasks: Run Task` → `Build All` (compiles all `.cpp`) or `C++ Multi-file Compile & Run`.

### Make (if provided)

```bash
make
./build/Debug/outDebug
make clean
```

### Direct g++ (single-line)

```bash
mkdir -p build/Debug
g++ -Wall -Wextra -std=c++23 *.cpp -o ./build/Debug/outDebug
./build/Debug/outDebug
```


## Data structures — API and examples

Below are the main data structures implemented in this workspace. Each section lists the core public methods and a short usage example.

---

### SimpleArray<T> (`simple_array.hpp`)

Description: Small resizable array (educational). Implementation is header-only (templates require this).

Public methods:
- `SimpleArray()` — constructor
- `~SimpleArray()` — destructor
- `void push(const T& value)` — append
- `T pop()` — remove and return last element (throws if empty)
- `size_t length() const` — number of elements
- `T& operator[](size_t index)` — indexing (throws if out of range)
- `T* operator*()` — pointer to internal buffer
- `friend ostream& operator<<(ostream&, const SimpleArray<T>&)` — prints elements

Example:

```cpp
#include "simple_array.hpp"
#include <iostream>
using namespace std;

int main() {
    SimpleArray<int> a;
    a.push(10);
    a.push(20);
    cout << "length=" << a.length() << '\n';
    cout << a << '\n';
    int last = a.pop();
    cout << "popped=" << last << '\n';
}
```

Notes:
- `operator<<` is defined inline in the header to avoid linker/template issues.
- For production code, prefer `std::vector<T>`; this is for learning.

---

### SinglyLinkedList (`singly_linked_list.hpp`)

Description: Singly linked list storing `variant<int, float, string>` as node data.

Public methods:
- `void insert(VariantData data)` — append to tail
- `void insertAtHead(VariantData value)` — insert at head
- `void pop()` — remove head
- `short search(VariantData value)` — return index or -1
- `void print() const` — print all elements
- `bool deleteAt(short pos)` — delete at position

Example:

```cpp
#include "singly_linked_list.hpp"
int main() {
    SinglyLinkedList list;
    list.insert(10);
    list.insert(3.14f);
    list.insert(std::string("hello"));
    list.print();
    list.pop();
    list.print();
}
```

---

### DoublyLinkedList (`doubly_linked_list.hpp`)

Description: Doubly linked list implementing `LinkedListBase` interface.

Public methods:
- `void insert(const VariantData& input)` — append
- `VariantData pop()` — pop tail and return value
- `void shift()` — remove head
- `DNode* searchIndex(unsigned short index) const` — get node by index
- `bool remove(const VariantData& value)` — remove first matching node
- `void reverse()` — reverse list in-place

Example:

```cpp
#include "doubly_linked_list.hpp"
int main() {
    DoublyLinkedList dll;
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.printList();
    auto v = dll.pop();
}
```

---

### CircularLinkedList (`circular_linked_list.hpp`)

Description: Circular singly linked list. `tail->next == head`.

Public methods:
- `void insert(const VariantData& input)` — insert at tail; if `capacity` set, acts as ring buffer and evicts oldest when full
- `void pop()` — remove last element
- `void printList() const` — iterate and print

Example:

```cpp
#include "circular_linked_list.hpp"
int main() {
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.printList();
}
```

---

### DoublyCircularLinked (`doubly_circular_linked_list.hpp`)

Description: Doubly circular linked list (each node has `prev` and `next` and the list is circular).

Public methods:
- `void insert(const VariantData data)` — append
- `void print(const DCNode* node) const` — print a node
- `void printList() const` — print all nodes

Example:

```cpp
#include "doubly_circular_linked_list.hpp"
int main() {
    DoublyCircularLinked dcll;
    dcll.insert(10);
    dcll.insert(20);
    dcll.insert(30);
    dcll.printList();
}
```

---

### InsertionSort (`insertion_sort.hpp`)

Description: Small helper class that sorts `std::vector<unsigned short>` using insertion sort.

Public methods:
- `void sort(std::vector<unsigned short>& arr)` — sorts in-place
- `void print(std::vector<unsigned short>& arr)` — print

Example:

```cpp
#include "insertion_sort.hpp"
#include <vector>
int main() {
    InsertionSort s;
    std::vector<unsigned short> arr = {5,2,8,1};
    s.sort(arr);
    s.print(arr);
}
```

---

### RandomLinkedListGenerator (`random_linked_list_generator.hpp`)

Description: Helper class to populate a `LinkedListBase` with random unsigned integers.

Public methods:
- `RandomLinkedListGenerator(unsigned int listSize, LinkedListBase& linkedList)` — constructor
- `void generateRandom(unsigned int max = 100)` — insert `listSize` random numbers in [1,max]
- `void printList()` — calls the list's printList

Example:

```cpp
#include "random_linked_list_generator.hpp"
#include "doubly_linked_list.hpp"
int main() {
    DoublyLinkedList dll;
    RandomLinkedListGenerator gen(5, dll);
    gen.generateRandom(50);
    gen.printList();
}
```

---

## Debugging in VS Code

- The workspace includes `.vscode/launch.json` configured with `preLaunchTask` set to the `Build All` task. Press F5 to build and debug.
- Set breakpoints, inspect variables, and step through code.


## Common issues & fixes

1. **Template linker errors (`undefined reference`)**
   - Problem: method definitions for templates are not visible to translation units that instantiate them.
   - Fix: move method definitions into the header (header-only) or add explicit instantiations.

2. **`operator<<` for templates undefined**
   - Problem: operator defined in a `.cpp` will not be found for template instantiations in other TUs.
   - Fix: define `operator<<` for the template in the header (inline friend or templated free function in header).

3. **Printing `uint8_t` or `u_int8_t` prints a character**
   - Fix: `std::cout << +val;` or `std::cout << static_cast<int>(val);`

4. **Exception `what()` must return `const char*`**
   - If you store the message in `std::string message;`, implement `what()` as `return message.c_str();`.


## Next steps (optional)

If you'd like, I can:

- Add `examples/` with a standalone demo file for each data structure that compiles and runs.
- Add unit tests (Catch2 or GoogleTest) and a test runner.
- Convert the build to a CMake-based workflow for cross-platform builds.
- Improve the `Makefile` to compile objects separately then link (faster incremental builds).

Tell me which follow-up you'd like and I'll implement it.
