###### **Declaration and Usage:**
```cpp
int arr[5] = {1, 2, 3, 4, 5};  // Static array
int* heapArr = new int[5];     // Heap allocation (must be deleted manually)
delete[] heapArr;              // Free memory
```

### **Passing to Functions:**
```cpp
void func(int* arr, int size) { /* process array */ }
int arr[5] = {1, 2, 3, 4, 5};
func(arr, 5); // Decays to pointer
```

### **Pros & Cons:**
✅ Fast, cache-friendly, minimal overhead.  
❌ No size information at runtime, no bounds checking, prone to memory leaks.

## 2. `std::array<T, N>`
### **Characteristics:**
- Fixed size at compile time (like raw arrays).
- Safer than C-style arrays (provides bounds checking with `.at()`).
- Supports STL features.

### **Declaration and Usage:**
```cpp
#include <array>
std::array<int, 5> arr = {1, 2, 3, 4, 5};
arr[0] = 10;
```

### **Passing to Functions:**
```cpp
void func(std::array<int, 5>& arr) { /* process array */ }
func(arr);
```



### **Pros & Cons:**
✅ Type-safe, supports iterators and STL algorithms.  
❌ Still fixed size, slightly more overhead than raw arrays.

## 3. `std::vector<T>`
### **Characteristics:**
- Dynamically sized (can grow/shrink at runtime).
- Allocates memory on the heap.
- Provides bounds checking with `.at()`.
- Supports iterators and STL algorithms.

### **Declaration and Usage:**
```cpp
#include <vector>
std::vector<int> vec = {1, 2, 3, 4, 5};
vec.push_back(6);
vec.pop_back();
```

### **Passing to Functions:**
```cpp
void func(std::vector<int>& vec) { /* process vector */ }
func(vec);
```

### **Pros & Cons:**
✅ Dynamic resizing, safer memory management, supports STL.  
❌ Slightly slower than raw arrays due to heap allocation.

## 4. Memory Management
### **Heap vs Stack Arrays:**
```cpp
// Stack allocation (automatic deallocation)
int stackArr[5];

// Heap allocation (must be manually freed)
int* heapArr = new int[5];
delete[] heapArr;
```

### **Smart Pointers for Heap Arrays:**
```cpp
#include <memory>
std::unique_ptr<int[]> arr(new int[5]);
```

## 5. Performance Considerations
- **Cache Friendliness:** Raw arrays and `std::array` have better cache locality than `std::vector`.
- **Insertion/Deletion Complexity:**
  - Raw Arrays: O(1) for access, O(N) for insertion/deletion in the middle.
  - `std::vector`: Amortized O(1) for push_back, O(N) for insertion/deletion in the middle.
- **Memory Overhead:** `std::vector` may allocate more memory than required to optimize growth.

## 6. Security Considerations
- **Buffer Overflows:** Accessing out-of-bounds elements in C-style arrays can cause undefined behavior.
- **Dangling Pointers:** Deleting an array but still using its pointer can cause memory corruption.
- **Memory Leaks:** Forgetting to free heap-allocated arrays leads to leaks.
- **Safe Practices:** Prefer `std::vector` or `std::array` over raw arrays when possible.

## 7. Returning Arrays from Functions
```cpp
// Return by value (RVO applies)
std::array<int, 5> func() { return {1, 2, 3, 4, 5}; }

// Return by reference (unsafe if returning local array)
const std::vector<int>& func() {
    static std::vector<int> v = {1, 2, 3, 4, 5};
    return v;
}
```

## Conclusion
This cheat sheet provides an overview of arrays in C++, covering different implementations, best practices, and security considerations. Understanding these concepts helps in writing efficient and safe C++ code.

---------------------------
template<typename T>
typename std::enable_if<
    std::is_same<decltype(std::declval<T>() + std::declval<T>()), T>::value,
    T
>::type
count(T a, T b) {
    return a + b;
}
#include <concepts>

template<typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};

template<Addable T>
T count(T a, T b) {
    return a + b;
}