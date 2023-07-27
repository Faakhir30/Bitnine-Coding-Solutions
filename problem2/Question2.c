#include <stdio.h>
#include <stdlib.h>
void multiply(int F[2][2], int M[2][2])
{
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(int F[2][2], int n)
{
    if (n <= 1)
        return;

    int M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}
/**
 * Calculate the nth Fibonacci number using matrix exponentiation.
 * This function uses matrix exponentiation to efficiently compute the nth Fibonacci number for larer values of 'n'.
 *
 * @param n The index of the Fibonacci number to calculate.
 * @return The nth Fibonacci number.
 */
int fib1(int n)
{
    if (n == 0)
        return 0;

    int F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);

    return F[0][0];
}
/**
 * Calculate the nth Fibonacci number using dynamic programming (DP) with an array.
 * This function uses dynamic programming with an array to calculate the nth Fibonacci number.
 *
 * @param n The index of the Fibonacci number to calculate.
 * @return The nth Fibonacci number.
 */
int fib2(int n)
{
    int F[n];
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
    {
        F[0] = 0, F[1] = 1;
        F[2] = 2;
        int i = 3;
        while (i <= n)
        {
            F[i] = F[i - 3] + F[i - 2];
            i++;
        }
    }
    return F[n];
}

/**
 * Calculate the nth Fibonacci number using a space-optimized approach with three variables.
 * This function uses a space-optimized approach with three variables to calculate the nth Fibonacci number.
 *
 * @param n The index of the Fibonacci number to calculate.
 * @return The nth Fibonacci number.
 */

int fib3(int n)
{
    int result = 0;
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
    {
        int first = 0;
        int second = 1;
        int third = 2;
        int i = 3;
        while (i <= n)
        {
            result = first + second;
            first = second;
            second = third;
            third = result;
            i++;
        }
    }
    return result;
}

/**
 * Calculate the nth Fibonacci number using recursion.
 * This function calculates the nth Fibonacci number using recursion.
 *
 * @param n The index of the Fibonacci number to calculate.
 * @return The nth Fibonacci number.
 */
int fib4(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return fib1(n - 3) + fib1(n - 2);
}
/*
 *DIFFERENCES BETWEEN APPROACHES
 *
 *test case for all approaches
 */
int main()
{
    /*
    1st way Fibonacci number using matrix exponentiation.
    Optimal for large fibbonacci indexes
    Time complexity: logarithmic (O(log n))
    Space Complexity: O(1) doesn't require any additional data structures that grow with the input size n.
    It only uses a constant-size 2x2 matrix F and a constant-size 2x2 matrix M for multiplication.
    Hence, its space complexity is O(1) or constant.
     */

    /*
    2nd Way - Using DP array to store previous results and calculate accordingly
    Time Complexity O(n), Space Complexity O(n), n is the nth Fibonacci num.
    Time is linear.
    */
   
    /*
     3rd Way - Using DP but only storing three previous calculated F(). and
     updating in every iteration
     Time Complexity O(n), Space Complexity O(1), n is the nth Fibonacci num.
     Time is linear but advantage is that we aren't using any space.
    */

    /*
    4th Way - Using Recursion method to calculate this custom Fibonacci number
    Time Complexity O(2^n), Space Complexity O(n), n is the nth Fibonacci num.
    Disadvantage - Time is Exponential so it won't return answers immediately
    */
    printf("Matrix Exponentiaion : Fib(6) = %d\n", fib1(6));
    printf("DP Array : Fib(6) = %d\n", fib2(6));
    printf("3 variables only : Fib(6) = %d\n", fib3(6));
    printf("Recursion : Fib(6) = %d\n", fib3(6));

    return 0;
}