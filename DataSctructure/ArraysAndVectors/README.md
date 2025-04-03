# Arrays and Vectors

This document provides a comprehensive overview of arrays in C++, including raw arrays, `std::array`, and `std::vector`. It covers memory management, performance considerations, safe usage patterns, best practices, and cybersecurity concerns. 

## Table of Contents

1. [Introduction](#introduction)
2. [Arrays - C Style and C++ Style](#arrays---c-style-and-c-style)
    - 2.1. [Key Characteristics](#key-characteristics)
    - 2.2. [Commom operations](#commom-operations)
        - [1. Initialization](#1-initialization)
        - [2. Accessing Elements](#2-accessing-elements)
        - [3. Updating Elements](#3-updating-elements)
        - [4. Array Traversal](#4-array-traversal)
        - [5. Size of Array](#5-size-of-array)
        - [6. Copying Arrays](#6-copying-arrays)
        - [7. Searching for an Element](#7-searching-for-an-element)
        - [8. Sorting Arrays](#8-sorting-arrays)
        - [9. Filling Arrays](#9-filling-arrays)
        - [10. Reversing Arrays](#10-reversing-arrays)
    - 2.3. [Passing and Returning Arrays](#passing-and-returning-arrays)
        - [C-Style Arrays](#c-style-arrays)
        - [Cpp Style Arrays](#cpp-style-arrays)
    - 2.4. [C-Style Array Improvements](#c-style-array-improvements)
    - 2.5. [Implementation in Assembly](#implementation-in-assembly)
    - 2.5. [Implementation std::array](#implementation-std::array)
3. [Resizable Arrays (Vectors) - C Style and C++ Style [DRAFT]](#resizable-arrays-vectors---c-style-and-c-style)
4. [Exercises](#exercises)
    - [1. Is Unique](#1-is-unique)
    - [2. Check Permutation](#2-check-permutation)
    - [3. URLify](#3-urlify)
    - [4. Palindrome Permutation](#4-palindrome-permutation)
    - [5. One Away](#5-one-away)
    - [6. String Compression](#6-string-compression)
    - [7. Rotate Matrix](#7-rotate-matrix)
    - [8. Zero Matrix](#8-zero-matrix)
    - [9. String Rotation](#9-string-rotation)
    - [10. Two Pointer](#10-two-pointer)
    - [11. Binary Search](#11-binary-search)
    - [12. Sliding Windows](#12-sliding-windows)
    - [13. Exponential Search](#13-exponential-search)
    - [14. HashMap](#14-hashmap)
    - [15. Contains Nearby Duplicate](#15-contains-nearby-duplicate)
    - [16. Two Sum](#16-two-sum)
    - [17. Extract Nibble](#17-extract-nibble)
    - [18. MEMCPY and STRLEN](#18-memcpy-and-strlen)
    - [19. Snowpack](#19-snowpack)    
    

# Introduction

Arrays and Resizable Arrays (Vectors) are both used to store collections of elements. However, they differ in their characteristics, flexibility, and usage. This section covers the key differences, operations, and use cases for both.

# Arrays - C Style and C++ Style

Arrays are a fundamental data structure that allows you to store a collection of elements of the same type. The size of the array is fixed at the time of declaration, and all elements are stored in contiguous memory locations.

## Key Characteristics
- **Fixed size:** The size of an array is determined at compile time and cannot be changed during runtime.
- **Contiguous memory:** Elements are stored next to each other in memory, ensuring fast access, and making arrays cache-friendly. This means that when iterating over the array, elements are likely to be loaded into cache together, leading to fewer cache misses and better performance.
- **Zero-based indexing:** The first element of an array has index `0`, and you can access elements using an index. For example, in arr[2], the index 2 refers to the third element.
- **No bounds checking:** Arrays do not automatically check if an index is within bounds. This means you can potentially access memory outside the allocated space (leading to undefined behavior or crashes). You need to manually ensure that you are accessing valid indexes.

    *However, you can encapsulate the array in an abstraction that provides bounds checking and other safety features. This can be achieved by wrapping the array in a class that provides methods like `begin()`, `end()`, and `size()`, similar to how the Standard Template Library (STL) containers like `std::array` work. This allows you to safely manage arrays without directly dealing with manual bounds checking. This allows you to maintain the performance benefits of arrays while minimizing common programming mistakes.*

- **Size information:** The size of an array is not attached to the array itself; it’s typically passed as a separate argument to functions. For example, when working with a C-style array, you need to know its size manually, unlike other data structures like std::vector where the size is embedded in the object.

---

## Commom operations

#### 1. Initialization
```cpp
// C-style array initialization
int arr[5] = {1, 2, 3, 4, 5};

// std::array initialization
std::array<int, 5> arr = {1, 2, 3, 4, 5};
```

#### 2. Accessing Elements
```cpp
// Accessing an element in a C-style array
int val = arr[2];

// Accessing an element in std::array
int val = arr.at(2); 
```

#### 3. Updating Elements
```cpp
// Updating an element in a C-style array
int arr[2] = 10;

// Updating a std::array
arr[2] = 10;  // Updates the third element (index 2) to 10

// Safe access with bounds checking
arr.at(2) = 10;  // If index is out of bounds, throws std::out_of_range
```

#### 4. Array Traversal
```cpp
// Traversing a C-style array
for (int i = 0; i < 5; ++i) {
    std::cout << arr[i] << " ";
}

// Traversing a std::array
for (auto val : arr) {
    std::cout << val << " ";
}
```

#### 5. Size of Array
```cpp
// For C-style arrays (manual size tracking)
int size = sizeof(arr) / sizeof(arr[0]);

// For std::array
int size = arr.size();
```

#### 6. Copying Arrays
```cpp
// Copying C-style arrays (manual copying)
int arr2[5];
for (int i = 0; i < 5; ++i) {
    arr2[i] = arr[i];
}

// Copying std::array (using the assignment operator)
std::array<int, 5> arr2 = arr;
```

#### 7. Searching for an Element
```cpp
// Searching in a C-style array
int target = 3;
bool found = false;
for (int i = 0; i < 5; ++i) {
    if (arr[i] == target) {
        found = true;
        break;
    }
}

// Searching in a std::array
auto it = std::find(arr.begin(), arr.end(), target);
if (it != arr.end()) {
    std::cout << "Found at index: " << std::distance(arr.begin(), it) << std::endl;
}
```

#### 8. Sorting Arrays
```cpp
// Sorting a C-style array
std::sort(arr, arr + 5);

// Sorting a std::array
std::sort(arr.begin(), arr.end());
```

#### 9. Filling Arrays
```cpp
// Filling a C-style array
std::fill(arr, arr + 5, 0);  // Set all elements to 0

// Filling a std::array
std::fill(arr.begin(), arr.end(), 0);
```

#### 10. Reversing Arrays
```cpp
// Reversing a C-style array
std::reverse(arr, arr + 5);

// Reversing a std::array
std::reverse(arr.begin(), arr.end());
```
---

## 2.1.3 Passing and Returning Arrays

### C Style Arrays

**Passing C-style Arrays to Functions:**
When passing a C-style array to a function, only the pointer to the first element is passed. The size of the array is not automatically passed, so you must pass it explicitly as an additional argument to prevent out-of-bounds access.
```cpp
// Example: Passing C-style array
void modifyArray(int arr[], int size) {
    arr[0] = 100;  // Modify first element
}

int main() {
    int arr[3] = {1, 2, 3};
    modifyArray(arr, 3);  // Passing array and its size
}
```
**Risks:**
- **No size information**: The function receiving the array doesn't know the size, so there’s no built-in check for out-of-bounds access. This can lead to **buffer overflows** and **undefined behavior**.
- **Memory safety**: Passing a pointer to a stack-allocated array to a function can lead to dangling pointers if the array goes out of scope.

**Correct Way**:
To make it safer, pass both the array and its size explicitly. Additionally, encapsulating arrays in a wrapper (e.g., `std::vector`) or using safer abstractions (like `std::array` or `std::vector`) is recommended to avoid manual size tracking.

**Returning C-style Arrays:**
Returning a C-style array from a function is dangerous because it would involve returning a pointer to a local array, which would go out of scope when the function exits (leading to a **dangling pointer**).
```cpp
// Incorrect: Returning a C-style array (dangerous)
int* returnArray() {
    int arr[3] = {1, 2, 3};  // Local array
    return arr;  // Dangerous: returns pointer to local array
}
```

**Risks:**
- **Dangling pointer**: The array goes out of scope once the function exits, but the returned pointer still points to the memory location of the array, which is now invalid.

**Correct Way**:
Instead of returning a local C-style array, you can return a **pointer to dynamically allocated memory** or use a `std::vector` or `std::array`.
```cpp
// Correct: Returning a pointer to dynamically allocated memory
int* returnArray() {
    int* arr = new int[3]{1, 2, 3};  // Dynamically allocated array
    return arr;
}
```

### **Cpp Style Arrays**

**Passing `std::array` to Functions:**
`std::array` is safer because the size is known at compile-time. It can be passed by reference or value. When passed by reference, the function can modify the original array; when passed by value, a copy of the array is passed.
```cpp
// Example: Passing std::array by reference
void modifyArray(std::array<int, 3>& arr) {
    arr[0] = 100;  // Modify first element
}

int main() {
    std::array<int, 3> arr = {1, 2, 3};
    modifyArray(arr);  // Passing by reference
}
```

**Advantages:**
- **Fixed size**: Since `std::array` is a fixed-size array, the size is known and is part of the type.
- **Safety**: It provides access through iterators and bounds-checked functions (`.at()`), avoiding the risk of out-of-bounds access.

**Returning `std::array`:**
`std::array` is safe to return from functions because its memory is managed automatically. When returning a `std::array`, it can be returned by value (due to Return Value Optimization, RVO) or by reference if you’re returning an already existing array.
```cpp
// Correct: Returning a std::array by value
std::array<int, 3> returnArray() {
    std::array<int, 3> arr = {1, 2, 3};
    return arr;  // No risk, RVO applies
}
```

**Risks:**
- None for `std::array` when used properly. It's safer compared to C-style arrays because it includes bounds checking and size tracking.

---

### **Comparison of C-style Arrays and `std::array` (in Terms of Passing and Returning):**

| Aspect                        | **C-style Array**                        | **`std::array`**                            |
|-------------------------------|------------------------------------------|--------------------------------------------|
| **Passing to Function**        | Pass as a pointer (no size info)         | Pass by reference or value (size is part of the type) |
| **Bounds Checking**            | No bounds checking, can cause errors     | Automatic bounds checking (via `.at()`)    |
| **Returning from Function**    | Dangerous if returning local arrays      | Safe, can be returned by value (RVO applies) |
| **Memory Management**          | Must manually manage memory (e.g., with `new[]`/`delete[]`) | Memory is automatically managed           |
| **Size Tracking**              | No size information, must be passed manually | Size is part of the type (`std::array<T, N>`) |

### **Best Practices:**
- **Avoid returning C-style arrays** from functions. Use `std::array` to handle arrays safely.
- **Always pass the size** of C-style arrays to functions. For `std::array`, no need to pass the size—it's built-in.
- **Prefer `std::array`** for fixed-size arrays as it provides more safety and functionality (e.g., iterators, bounds checking).

---
## C-Style Array Improvements

This C array library encapsulates an array in a struct, providing safe access, iteration, and encapsulation similar to std::array in C++. It consists of:
- **array.h** (Header file with function declarations)
- **array.c** (Implementation of functions)
- **main.c** (Example usage)

```cpp
// array.h
#pragma once

#include <stdio.h>

#define SIZE 5

typedef struct {
    int data[SIZE];
    int size;
} Array;

// Function declarations
void printArray(const Array* arr);
int getElement(const Array* arr, int index);
int* begin(Array* arr);
int* end(Array* arr);
void iterate(Array* arr);

// array.c
#include "array.h"

void printArray(const Array* arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int getElement(const Array* arr, int index) {
    if (index >= 0 && index < arr->size) {
        return arr->data[index];
    }
    printf("Error: Index out of bounds\n");
    return -1;  // Return an invalid value
}

int* begin(Array* arr) {
    return &arr->data[0];
}

int* end(Array* arr) {
    return &arr->data[arr->size];
}

void iterate(Array* arr) {
    for (int* it = begin(arr); it != end(arr); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
}

// main.c
#include "array.h"

int main() {
    Array arr = {{1, 2, 3, 4, 5}, SIZE};
    printArray(&arr);
    iterate(&arr);
    return 0;
}

```

---

## Implementation in Assembly

```cpp
#include <stdio.h>
#include <stdlin.h>

void func() {
    int arr[3] = {1, 2, 3};
    print("%d\n", arr[1]);
}

int main() {
    func();
    return 0;
}
```

```assembly
.LCO
    .string "%d\n"

func:
    push    pop
    mov     rbp, rsp
    sub     rsp, 16                 # Reserve space on stack (align to 16 byte)
    mov     DWORD PTR[rbp - 12], 1  # arr[0] = 1  
    mov     DWORD PTR[rbp - 8], 2   # arr[1] = 2
    mov     DWORD PTR[rbp - 4], 3   # arr[3] = 3
    mov     eax, DWORD PTR[rbp - 8] # Load arr[1] into eax
    mov     esi, eax                # Move to esi for printf
    mov     edi, OFFSET FLAT:.LCO   # format string
    mov     eax, 0
    call    printf                  # Call printf
    nop
    leave
    ret

main: 
    push    rbp
    mov     rbp, rsp
    mov     eax, 0
    call    func
    mov     eax, 0
    pop     rbp
    ret
```

---
## Implementation std::array

```cpp
#include <iostream>
#include <initializer_list>
#include <algorithm>

template <typename T, std::size_t N>
class MyArray {
private:
    T data[N];

public:
    // 1. Default constructor (zero-initialize elements)
    MyArray() {
        std::fill(begin(), end(), T{});
    }

    // 2. Constructor with initializer list
    MyArray(std::initializer_list<T> init) {
        std::copy(init.begin(), init.end(), data);
    }

    // 3. Copy constructor
    MyArray(const MyArray& other) {
        std::copy(other.begin(), other.end(), data);
    }

    // 4. Move constructor
    MyArray(MyArray&& other) noexcept {
        std::move(other.begin(), other.end(), data);
    }

    // 5. Constructor with default value
    MyArray(const T& defaultValue) {
        std::fill(begin(), end(), defaultValue);
    }

    // Element access
    T& operator[](std::size_t index) {
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        return data[index];
    }

    // Iterators
    T* begin() { return data; }
    T* end() { return data + N; }
    const T* begin() const { return data; }
    const T* end() const { return data + N; }

    // Size
    constexpr std::size_t size() const { return N; }

    // Assignment operator
    MyArray& operator=(const MyArray& other) {
        std::copy(other.begin(), other.end(), data);
        return *this;
    }

    // Comparison operator
    bool operator==(const MyArray& other) const {
        return std::equal(begin(), end(), other.begin());
    }
};

// Example usage
int main() {
    MyArray<int, 5> arr = {1, 2, 3, 4, 5};
    
    std::cout << "Array elements: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}
```

---

# Resizable Arrays (Vectors) - C Style and C++ Style

---

# Exercises
## 1. Is Unique
Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures
#### Solution:
```cpp
#include <iostream>
#include <string>

bool isUnique(const std::string& str) {
    if (str.length() > 128) return false;

    bool seen[128] = {false};

    for (char ch : str) {
        if (seen[ch]) return false;
        seen[ch] = true;
    }
    return true;
}

// Test cases
int main() {
    std::string test1 = "abcdefg";
    std::string test2 = "hello"; 
    std::string test3 = "";      
    std::string test4 = "abcABC";
    std::string test5 = "aabbcc";

    std::cout << std::boolalpha;
    std::cout << "Test 1 (abcdefg): " << isUnique(test1) << "\n";
    std::cout << "Test 2 (hello): " << isUnique(test2) << "\n";
    std::cout << "Test 3 (empty string): " << isUnique(test3) << "\n";
    std::cout << "Test 4 (abcABC): " << isUnique(test4) << "\n";
    std::cout << "Test 5 (aabbcc): " << isUnique(test5) << "\n";

    return 0;
}
```
## 2. Check Permutation
Check Permutation: Given two strings, write a method to decide if one is a permutation of the others
#### Solution:
```cpp
#include <iostream>
#include <string>

bool checkPermutation( const std::string& str1, const std::string& str2) {
    if (str1.length() !=  str2.length()) return false;

    bool seen[128] = {false};

    for (char ch: str1) {
        if (!seen[ch])
            seen[ch] = true;
    }

    for (char ch: str2) {
        if (!seen[ch]) return false;
    }

    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "abc & bca: " << checkPermutation("abc", "bca") << "\n"; // true
    std::cout << "hello & ollhe: " << checkPermutation("hello", "ollhe") << "\n"; // true
    std::cout << "test & best: " << checkPermutation("test", "best") << "\n"; // false
    return 0;
}
```
## 3. URLify
URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.
#### Solution:
```cpp
#include <iostream>
#include <string>

void replaceSpaces(std::string& str) {
    int spaceCount = 0;

    for (char ch : str) {
        if (ch == ' ') spaceCount++;
    }

    int originalLength = str.length();
    str.resize(originalLength + (spaceCount * 2));
    int j = str.length() - 1;
    for (int i = originalLength - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = str[i];
        }
    }
}

// Test cases
int main() {
    std::string str = "Mr John Smith";
    replaceSpaces(str);
    std::cout << "URLified: " << str << std::endl; // Output: "Mr%20John%20Smith"
    return 0;
}
```

## 4. Palindrome Permutation
Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word of phrase that is the same fowards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
#### Solution:
```cpp
#include <iostream>
#include <string>
#include <array>
#include <cctype>

bool isPermutationOfPalindrome(const std::string& s) {
    std::array<int, 26> charCount = {};
    int oddCount = 0;

    for (char ch : s) {
        if (std::isalpha(ch)) {
            int index = std::tolower(ch) - 'a';
            charCount[index]++;

            if (charCount[index] % 2 == 0) {
                oddCount--;
            } else {
                oddCount++;
            }
        }
    }

    return oddCount <= 1;
}

// Test cases
int main() {
    std::string input1 = "Tact Coa";
    std::string input2 = "hello";
    std::string input3 = "racecar";
    
    std::cout << "Is Palindrome Permutation? " << (isPermutationOfPalindrome(input1) ? "Yes" : "No") << std::endl;
    std::cout << "Is Palindrome Permutation? " << (isPermutationOfPalindrome(input2) ? "Yes" : "No") << std::endl;
    std::cout << "Is Palindrome Permutation? " << (isPermutationOfPalindrome(input3) ? "Yes" : "No") << std::endl;

    return 0;
}
```

## 5. One Away
One Away: There are three types of edits that can be performed on string insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one editor(or zero edit) away.
#### Solution:
```cpp
#include <iostream>
#include <string>

bool oneEditAway(const std::string& s1, const std::string& s2) {
    int len1 = s1.length(), len2 = s2.length();

    if (std::abs(len1 - len2) > 1) return false;

    const std::string& shorter = (len1 < len2) ? s1 : s2;
    const std::string& longer = (len1 < len2) ? s2 : s1;

    int i = 0, j = 0;
    bool foundDifference = false;

    while (i < shorter.length() && j < longer.length()) {
        if (shorter[i] != longer[j]) {
            if (foundDifference) return false;
            foundDifference = true;

            if (len1 == len2) i++;
        } else {
            i++;
        }
        j++;
    }

    return true;
}

// Test cases
int main() {
    std::cout << std::boolalpha;
    std::cout << "pale, ple: " << oneEditAway("pale", "ple") << "\n";   // True (remove)
    std::cout << "pales, pale: " << oneEditAway("pales", "pale") << "\n"; // True (remove)
    std::cout << "pale, bale: " << oneEditAway("pale", "bale") << "\n"; // True (replace)
    std::cout << "pale, bake: " << oneEditAway("pale", "bake") << "\n"; // False (two replacements)
    std::cout << "apple, aple: " << oneEditAway("apple", "aple") << "\n"; // True (remove)
    std::cout << "pale, pales: " << oneEditAway("pale", "pales") << "\n"; // True (insert)
    std::cout << "pale, paless: " << oneEditAway("pale", "paless") << "\n"; // False (two inserts)
    return 0;
}
```

## 6. String Compression
String Compression: Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters.
#### Solution:
```cpp

#include <iostream>
#include <string>

std::string compressString(const std::string& str) {
    if (str.length() <= 1) return str;

    std::string compressed;
    int count = 1;

    for (size_t i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) {
            count++;
        } else {
            compressed += str[i - 1];
            compressed += std::to_string(count);
            count = 1;
        }
    }

    compressed += str.back();
    compressed += std::to_string(count);

    return (compressed.length() < str.length()) ? compressed : str;
}

// Test cases
int main() {
    std::cout << compressString("aabcccccaaa") << "\n"; // Expected: a2b1c5a3
    std::cout << compressString("abcd") << "\n";        // Expected: abcd (since compressed isn't shorter)
    std::cout << compressString("aa") << "\n";          // Expected: aa (compressed isn't shorter)
    std::cout << compressString("aabbcc") << "\n";      // Expected: aabbcc (compressed isn't shorter)
    return 0;
}

```

## 7. Rotate Matrix
Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes write a method to rotate the image by 90 degrees. Can you do this in place?
#### Solution:
```cpp
#include <vector>
#include <algorithm>
#include <iostream>

void rotateMatrix (std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        std::reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateMatrix(matrix);
    printMatrix(matrix); // Expected output: 7 4 1  8 5 2  9 6 3

    return 0;
}

```

## 8. Zero Matrix
Zero Matrix: Write an algorithm such that if an element in a MxN matrix is 0, it's entire row and column are set to 0.
#### Solution:
```cpp

#include <iostream>
#include <vector>

void setZeros(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0) {
        for (int i = 0; i < m; i++) matrix[i][0] = 0;
        for (int j = 0; j < n; j++) matrix[0][j] = 0;
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}

// Test cases
int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 0, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
    };

    std::cout << "Original Matrix:\n";
    printMatrix(matrix);

    setZeros(matrix);

    std::cout << "\nMatrix after setZeros:\n";
    printMatrix(matrix);

    return 0;
}

```

## 9. String Rotation
String Rotation: Assume you have a method isSubstring which check if one wod is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring
#### Solution:
```cpp
#include <iostream>
#include <string>

bool isSubstring (const std::string& str, const std::string& sub) {
    return str.find(sub) != std::string::npos;
}

bool isRotation (const std::string& s1, const std::string& s2) {
    if (s1.length() != s2.length() || s1.empty()) return false;

    std::string concatenated = s1 + s1;
    return isSubstring(concatenated, s2);
}

// Test cases
int main() {
    std::string s1 = "waterbottle";
    std::string s2 = "erbottlewat";

    std::cout << "Is Rotation? " << (isRotation(s1, s2) ? "Yes" : "No") << std::endl;

    return 0;
}
```

## 10. Two Pointer
Two Pointer
#### Solution:
```cpp
#include <iostream>
#include <algorithm>

void reverseWord(std::string& s) {
    int l = 0, r = 0, n = s.size();

    while (r <= n) {
        if (r == n || s[r] == ' ') {
            std::reverse(s.begin() + l, s.begin() + r);
            l = r + 1;
        }
        r++;
    }
}

// Test cases
int main() {
    std::string str = "hello world";
    reverseWord(str);
    std::cout << str << std::endl;  // Output: "olleh dlrow"
    return 0;
}
```

## 11. Binary Search
Binary Search
#### Solution:
```cpp
#include <iostream>
#include <array>

int binarySearch(const std::array<int, 10>& arr, int x) {
    int l = 0, r = arr.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) return mid;
        if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

// Test cases
int main() {
    std::array<int, 10> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    int x = 7;
    int index = binarySearch(arr, x);

    if (index != -1) {
        std::cout << "Element found at index: " << index << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }
    
    return 0;
}

```

## 12. Sliding Windows
Sliding Windows
#### Solution:
```cpp
#include <iostream>
#include <array>
#include <string>
#include <algorithm>

int maximumLengthSubstring(const std::string& s) {
    if (s.empty()) return 0; 

    std::array<int, 128> counter = {}; 
    int l = 0, r = 0, maxLen = 0;

    while (r < s.size()) {
        counter[s[r]]++;

        while (counter[s[r]] > 1) {
            counter[s[l]]--;
            l++;
        }

        maxLen = std::max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}

// Test cases
int main() {
    std::string s = "abcabcbb";
    std::cout << "Max Length of Unique Substring: " << maximumLengthSubstring(s) << std::endl;

    return 0;
}
```

## 13. Exponential Search
Exponential Search
#### Solution:
```cpp

#include <iostream>
#include <array>
#include <algorithm>

int binarySearch(const std::array<int, 10>& arr, int target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int exponentialSearch(const std::array<int, 10>& arr, int target) {
    if (arr[0] == target) return 0;

    int n = arr.size();
    int i = 1;

    while (i < n && arr[i] < target)
        i *= 2;

    return binarySearch(arr, target, i / 2, std::min(i, n - 1));
}

// Test cases
int main() {
    std::array<int, 10> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 13;

    int index = exponentialSearch(arr, target);
    if (index != -1)
        std::cout << "Element found at index: " << index << std::endl;
    else
        std::cout << "Element not found." << std::endl;

    return 0;
}

```

## 14. HashMap
HashMap
#### Solution:
```cpp
#include <iostream>
#include <array>
#include <string>
#include <limits>

int firstUniqueChar(const std::string& s) {
    std::array<std::pair<int, int>, 128> charInfo = {};

    for (int i = 0; i < s.size(); i++) {
        if (charInfo[s[i]].second == 0)
            charInfo[s[i]] = {i, 1};
        else
            charInfo[s[i]].second++;
    }

    int firstIndex = std::numeric_limits<int>::max();
    for (auto& [idx, count] : charInfo) {
        if (count == 1)
            firstIndex = std::min(firstIndex, idx);
    }

    return (firstIndex == std::numeric_limits<int>::max()) ? -1 : firstIndex;
}

// Test cases
int main() {
    std::string s = "leetcode";
    int index = firstUniqueChar(s);
    
    if (index != -1)
        std::cout << "First unique character at index: " << index << " ('" << s[index] << "')" << std::endl;
    else
        std::cout << "No unique character found." << std::endl;

    return 0;
}
```

## 15. Contains Nearby Duplicate
Contains Nearby Duplicate
#### Solution:
```cpp

#include <iostream>
#include <vector>
#include <unordered_map>

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        if (map.find(nums[i]) != map.end() && (i - map[nums[i]]) <= k) 
            return true;
        map[nums[i]] = i;
    }
    return false;
}

// Test cases
int main() {
    std::vector<std::vector<int>> testCases = {
        {1, 2, 3, 1},      // Expected: true (1 appears at index 0 and 3, diff = 3)
        {1, 2, 3, 4, 5},   // Expected: false (no duplicates)
        {1, 2, 3, 1, 2, 3},// Expected: false (no duplicate within k range)
        {1, 2, 3, 4, 1},   // Expected: true (1 appears at index 0 and 4, diff = 4)
        {99, 99},          // Expected: true (same number twice, diff = 1)
    };
    
    std::vector<int> kValues = {3, 2, 2, 4, 1};

    for (size_t i = 0; i < testCases.size(); i++) {
        std::cout << "Test Case " << i + 1 << ": "
                  << (containsNearbyDuplicate(testCases[i], kValues[i]) ? "true" : "false") 
                  << std::endl;
    }

    return 0;
}

```

## 16. Two Sum
Two Sum
#### Solution:
```cpp

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; 
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

// Test cases
int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
    } else {
        std::cout << "No two sum solution found." << std::endl;
    }

    return 0;
}

```

## 17. Extract Nibble
Extract Nibble
#### Solution:
```cpp

uint8_t extract_nibble(uint32_t * fuse, uint8_t size, uint8_t nibble_index)
{
    uint8_t nibbles_per_word = sizeof(uint32_t) * 2;
    uint8_t array_index = nibble_index / nibbles_per_word;
    
    if (array_index >= size) {
        printf("Error: nibble_index out of bounds\n");
        return 255;
    }
    
    uint8_t nibble_position = nibble_index % nibbles_per_word;
    uint8_t shift_amount = (nibbles_per_word - 1 - nibble_position) * 4;
    
    return (fuse[array_index] >> shift_amount) & 0xF;
}

int main() 
{
    uint32_t fuse[] = {0xABCDEF01, 0xF2345678};
    uint8_t size = 2;
    uint8_t nibble_index = 0;
    
    
    printf("Nibble value is: 0x%x\n", extract_nibble(fuse, size, nibble_index));
    
    return 0;
}

```

## 18. MEMCPY and STRLEN
MEMCPY and STRLEN
#### Solution:
```cpp
#include <assert.h>
#include <stdio.h>
#include <string.h>

void *my_memcpy(void *restrict dest, const void *restrict src, size_t count)
{
    char *d = (char *)dest;
    const char *s = (const char *)src;

    for (size_t i = 0; i < count; i++)
    {
        d[i] = s[i];
    }

    return dest;
}

size_t my_strnlen(const char *s, size_t max)
{
    size_t size = 0;
    while (size < max && s[size] != '\0')
    {
        size++;
    }
    return size;
}

int main()
{
    char buffer[32] = {};
    const char *str = "Hello, world! This is a test";

    int str_len = my_strnlen(str, 23);
    char *buf = my_memcpy(buffer, str, str_len);

    assert(23 == my_strnlen(buf, 24));
    assert(23 == str_len);
    assert(memcmp(str, buffer, str_len) == 0);
    assert(buf == &buffer[0]);
    assert(strcmp("Hello, world! This is a", buf) == 0);
    printf("TEST PASSED!\n");
    return 0;
}
```

## 19. Snowpack
Snowpack
#### Solution:
```cpp
/*
**  1) Given an array of non-negative integers representing the elevations
**     from the vertical cross section of a range of hills, determine how
**     many units of snow could be captured between the hills. 
**
**     See the example array and elevation map below.
**                                 ___
**             ___                |   |        ___
**            |   |        ___    |   |___    |   |
**         ___|   |    ___|   |   |   |   |   |   |
**     ___|___|___|___|___|___|___|___|___|___|___|___
**     {0,  1,  3,  0,  1,  2,  0,  4,  2,  0,  3,  0}
**                                 ___
**             ___                |   |        ___
**            |   | *   *  _*_  * |   |_*_  * |   |
**         ___|   | *  _*_|   | * |   |   | * |   |
**     ___|___|___|_*_|___|___|_*_|___|___|_*_|___|___
**     {0,  1,  3,  0,  1,  2,  0,  4,  2,  0,  2,  0}
**
**     Solution: In this example 13 units of snow (*) could be captured.
**
**  2) Consider adding some additional tests in doTestsPass().
**  3) Implement computeSnowpack() correctly.
*/

#include <iostream>
using namespace std;

/*
**  Find the amount of snow that could be captured.
*/
int computeSnowpack(int arr[], int arr_size)
{
  // Todo: Implement computeSnowpack
  int left = 0, right = arr_size - 1;
  int leftMax = 0, rigthMax = 0;
  int snow_sum = 0;

  while (left < right) {
    if (arr[left] < arr[right]) {
      if (arr[left] >= leftMax) {
        leftMax = arr[left];
      } else {
        snow_sum += leftMax - arr[left];
      }
      left++;
    } else {
      if (arr[right] >= rigthMax) {
        rigthMax = arr[right];
      } else {
        snow_sum += rigthMax - arr[right];
      }
      right--;
    }
  }

  cout << "neve: " << snow_sum << endl;

  return snow_sum;
}

/*
**  Returns true if the tests pass. Otherwise, returns false;
*/
bool doTestsPass()
{
  bool result = 1;
  int int_size = sizeof(int);
  
  int a[] = {0,1,3,0,1,2,0,4,2,0,2,0};
  result &= computeSnowpack(a, sizeof(a)/int_size) == 11;
  
  return result;
}

/*
**  Execution entry point.
*/
int main()
{
  // Run the tests
  if(doTestsPass())
  {
  printf("All tests pass");
  }
  else
  {
  printf("Tests failed");
  }

  return 0;
}
```

---
