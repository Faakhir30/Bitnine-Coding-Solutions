# Problem 1: How To Complie and Run Source code

- You need to have a C/C++ compiler on your operating system, i used mingw-w64

- open terminal in the file location ```Problem1```

- to compile the code run this command in the opened terminal: ```gcc -o main Question1.c``` [You can skip this step, you have the .exe file already]

- to execute the code run this command in the opened terminal: ```./main.exe```


# Development Environment

Both `Question1.c` and `Question1-Alternate.c` are valid implementations, and the choice between the two approaches depends on the specific requirements and preferences of the programmer. Let's compare the two approaches and discuss their pros and cons:

**Approach in Question1.c:**

1. Function pointers are returned directly from `makeFunc`.
2. Function pointers are used to call the respective arithmetic or Fibonacci functions.
3. The main function calls `makeFunc` for each operation and stores the function pointers directly in variables to later call the functions.

**Pros:**
- Simple and straightforward approach.
- Does not require an additional struct to store the function pointers.

**Cons:**
- Repetitive code in the main function when calling `makeFunc` and storing the function pointers.
- No way to store the results of the function calls (e.g., if you wanted to cache them).

**Approach in Question1-Alternate.c:**

1. Uses a `Node` struct to store the function pointer and the result of the function call.
2. The `makeFunc` function creates a `Node` and associates the correct function pointer based on the provided `TypeTag`.
3. The `calc` function is responsible for calling the respective functions based on the `TypeTag` and printing the results.
4. Memory management: The caller is responsible for freeing the dynamically allocated `Node`.

**Pros:**
- Better separation of concerns: The `Node` struct handles the function pointer and result storage, and the `calc` function takes care of calling and printing the results.
- Cleaner main function: The main function is cleaner as it only calls the `calc` function for each operation, and memory management is encapsulated in `makeFunc`.

**Cons:**
- Slightly more complex due to the use of a custom `Node` struct.

**Conclusion:**

The `Question1-Alternate.c` approach using the `Node` struct is generally considered a better approach from a software design perspective. It encapsulates the function pointer and result, leading to cleaner and more modular code. The `calc` function can be expanded to handle additional operations easily without cluttering the main function.

On the other hand, the `Question1.c` approach is simpler and may be preferred for small projects or quick prototyping, where the overhead of using a custom struct may not be necessary.

In general, if you expect the codebase to grow or require additional operations, the `Question1-Alternate.c` approach is recommended. However, for smaller projects with a limited number of operations, the `Question1.c` approach could suffice.
