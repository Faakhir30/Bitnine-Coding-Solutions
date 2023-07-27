# Problem 2: How To Complie and Run Source code

- You need to have a C/C++ compiler on your operating system, i used mingw-w64

- open terminal in the file location

- to compile the code run this command in the opened terminal: ```gcc -o main Question2.c``` [You can skip this step, you have the .exe file already]

- to execute the code run this command in the opened terminal: ```./main.exe```


# Development Environment

You will see a main.c file that has 4 fibonacci functions, F1, F2, F3, F4

# Functions Differences Explaination
i wrote comments above each function in main,c, but i will explain it here as well for better readability

**Differences between the four Fibonacci calculation approaches:**

1. **F1 (Matrix Exponentiation):**

   - Time Complexity: O(log n)
   - Space Complexity: O(1)

   This approach uses matrix exponentiation to efficiently compute the nth Fibonacci number for larger values of 'n'. It uses a 2x2 matrix to calculate Fibonacci numbers. It has a logarithmic time complexity, making it optimal for large Fibonacci indexes. The space complexity is constant since it only uses a fixed-size 2x2 matrix and doesn't require any additional data structures that grow with the input size.

2. **F2 (Dynamic Programming with Array):**

   - Time Complexity: O(n)
   - Space Complexity: O(n)

   This approach uses dynamic programming with an array to calculate the nth Fibonacci number. It stores previously calculated Fibonacci numbers in an array to avoid redundant calculations. The time complexity is linear as it iterates from 3 up to n, and the space complexity is linear because it uses an array of size n.

3. **F3 (Space-Optimized Dynamic Programming):**

   - Time Complexity: O(n)
   - Space Complexity: O(1)

   This approach is a space-optimized version of dynamic programming. It only stores the three previous Fibonacci numbers and updates them in each iteration to calculate the next number. The time complexity is linear, similar to F2, but the advantage is that it uses only three variables and doesn't require additional memory space proportional to n.

4. **F4 (Recursion):**

   - Time Complexity: O(2^n)
   - Space Complexity: O(n)

   This approach uses simple recursion to calculate the nth Fibonacci number. However, it has exponential time complexity because it makes redundant calculations and computes the same Fibonacci numbers multiple times. The space complexity is O(n) due to the recursion call stack.

**Advantages and Disadvantages:**

1. F1 (Matrix Exponentiation):
   - **Advantage**: Highly efficient for large Fibonacci indexes, significantly faster than other approaches.
   - **Disadvantage**: Implementation may be more complex due to the matrix multiplication.

2. F2 (Dynamic Programming with Array):
   - **Advantage**: Simple implementation, efficient for small to moderate Fibonacci indexes.
   - **Disadvantage**: Uses additional memory to store the array of size n, not optimal for large indexes.

3. F3 (Space-Optimized Dynamic Programming):
   - **Advantage**: Simple implementation, space-efficient, and better than F2 for large Fibonacci indexes.
   - **Disadvantage**: Still uses linear space, not optimal for extremely large indexes.

4. F4 (Recursion):
   - **Advantage**: Simple implementation.
   - **Disadvantage**: Very inefficient for large indexes due to redundant calculations and exponential time complexity. Not recommended for practical use.

**Conclusion:**

For practical use and optimal performance, F1 (Matrix Exponentiation) and F3 (Space-Optimized Dynamic Programming) are the recommended approaches. F1 is suitable for extremely large Fibonacci indexes, while F3 provides a balance between simplicity and efficiency. F2 is suitable for moderate indexes but may not be optimal for very large ones. F4 should generally be avoided for anything other than small indexes, as it has exponential time complexity and is highly inefficient.