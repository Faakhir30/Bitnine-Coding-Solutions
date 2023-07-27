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
  int (*func)(int, int); // Function pointer
  int result;            // Result of the function call
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

int divi(int a, int b)
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
 * Creates a new Node containing the function pointer associated with the given TypeTag.
 * The returned Node must be freed by the caller when it is no longer needed.
 *
 * @param tag The TypeTag representing the type of function to associate with the Node.
 * @return A dynamically allocated Node struct with the associated function pointer.
 *         Returns NULL if the TypeTag is  unsupported.
 */
Node *makeFunc(TypeTag tag)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->type = tag;
  switch (tag)
  {
  case ADD:
    node->func = &add;
    break;
  case SUB:
    node->func = &sub;
    break;
  case MUL:
    node->func = &mul;
    break;
  case DIV:
    node->func = &divi;
    break;
  case FIBO:
    node->func = &fibo;
    break;
  default:
    node->func = NULL;
  }
  return node;
}

void calc(Node *node)
{
  switch (node->type)
  {
  case ADD:
    printf("-add %d\n", node->func(10, 6));
    break;
  case MUL:
    printf("-mul %d\n", node->func(5, 4));
    break;
  case SUB:
    printf("-sub %d\n", node->func(16, 20));
    break;
  case FIBO:
    printf("-fibo %d\n", node->func(4, NULL));
    break;
  default:
    printf("Undefined TypeTag Node");
  }
}

int main()
{
  Node *addNode = makeFunc(ADD);
  Node *mulNode = makeFunc(MUL);
  Node *subNode = makeFunc(SUB);
  Node *fiboNode = makeFunc(FIBO);

  calc(addNode);
  calc(mulNode);
  calc(subNode);
  calc(fiboNode);

  free(addNode);
  free(mulNode);
  free(subNode);
  free(fiboNode);

  return 0;
}
