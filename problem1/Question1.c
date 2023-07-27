#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag
{
  ADD,
  SUB,
  MUL,
  DIV,
  FIBO,
} TypeTag;

typedef struct Node
{
  TypeTag type;
} Node;

int add(int a, int b)
{
  return a + b;
}

int sub(int a, int b)
{
  return a - b;
}

int mul(int a, int b)
{
  return a * b;
}

int divv(int a, int b)
{
  return a / b;
}

/**
 * Calculate the nth Fibonacci number using Dynamic Programming.
 *
 * The function takes an integer 'a' as input and returns the (a-1)th Fibonacci number.
 * Fibonacci series is a sequence of numbers in which each number is the sum of the two preceding ones.
 * The first two numbers in the sequence are 0 and 1.
 *
 * @param a The input integer for which the corresponding Fibonacci number is to be calculated.
 *
 * @return The (a-1)th Fibonacci number.
 */
int fibo(int a, int b)
{
  if (a == 1)
  {
    return 0;
  }
  else if (a == 2)
  {
    return 1;
  }
  else
  {
    int fib[a];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < a; i++)
    {
      fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[a - 1];
  }
}
/**
 * Returns a function pointer to an arithmetic or Fibonacci function based on the provided TypeTag.
 *
 * @param tag The TypeTag value representing the desired operation. Should be one of ADD, SUB, MUL, DIV, or FIBO.
 * @return A function pointer to the selected arithmetic or Fibonacci function.
 */
int (*makeFunc(TypeTag tag))(int, int)
{
  switch (tag)
  {
  case ADD:
    return &add;
  case SUB:
    return &sub;
  case MUL:
    return &mul;
  case DIV:
    return &divv;
  case FIBO:
    return &fibo;
  }
}

int main()
{

  int add = (*makeFunc(ADD))(10, 6);
  int mul = (*makeFunc(MUL))(5, 4);
  int sub = (*makeFunc(SUB))(add, mul);
  int fibo = (*makeFunc(FIBO))(abs(sub), NULL); // Get n-th from fibonacci numbers.

  printf("-add %d\n", add);
  printf("-mul %d\n", mul);
  printf("-sub %d\n", sub);
  printf("-fibo %d\n", fibo);

  return 0;
}