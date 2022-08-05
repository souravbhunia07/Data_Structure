#include <iostream>
using namespace std;

// Tail recursion.

void function1(int x)
{
    if (x > 0)
    {
        cout << x << " "; 
        function1(x - 1);
    }
}

// Head recursion.

void function2(int x)
{
    if (x > 0)
    {
        function2(x - 1);
        cout << x << " "; 
    }
}

// Use of static variable.(makes only single copy of varianle are retain it's value throughout the program.)

int staticFunc(int n)
{
    static int x = 0;

    if (n > 0)
    {
        x++;
        return staticFunc(n - 1) + x;
    }
    return 0;
}

// using non-static variable.

int nonStaticFunc(int n)
{

    if (n > 0)
    {
        return nonStaticFunc(n - 1) + n;
    }
    return 0;
}

// Global variable in recursion.

int variable = 0;

int globalVariableFunc(int n)
{
    if (n > 0)
    {
        variable++;
        return globalVariableFunc(n - 1) + variable;
    }
    return 0;
}

// Tree recursion:- calling function more than one time.
// Linear recursion:- calling function one time.

int treeRecursion(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        treeRecursion(n - 1);
        treeRecursion(n - 1);
    }
}

// Indirect zrecusion:-

int funcB(int n);

int funcA(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        funcB(n - 1);
    }
}

int funcB(int n)
{
    if (n > 1)
    {
        cout << n << endl;
        funcA(n/2);
    }
}

// Nested recursion:-

int nestedRecursion(int n)
{
    if (n > 100)
    {
        return n - 10;
    }
    else
    {
        return nestedRecursion(nestedRecursion(n + 11));
    }
}

// Sum of natural number using recursion.

int sumRecursion(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return sumRecursion(n - 1) + n;
    }
}

// Factorial of a number.

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return factorial(n - 1) * n;
    }
}

// Exponent

int power(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return power(m, n - 1) * m;
    }
}

// Taylr series:-

int e(int x, int n)
{
    static int pow = 1, fact = 1;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        int result = e(x, n - 1);
        pow = pow * x;
        fact = fact * n;
        return result + pow/fact; 
    }
}

// Optimized solution.
// Iterative method.

int iterativeE(int x, int n)
{
    int s = 1;
    while (n > 0)
    {
        s = (1 + x/n) * s;
        n--;
    }
    return s;
}

// Recursive method(Taylor series Horner's rule):-

int recursiveE(int x, int n)
{
    static int s = 1;
    if (n == 0)
    {
        return s;
    }
    else
    {
        s = (1 + x/n) * s;
    }
    return recursiveE(x, n - 1);
}

// Fibonacci series:-

int fiboSeries(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fiboSeries(n - 1) + fiboSeries(n - 2); 
    }
}

// Iterstive version

int iterativeFibo()
{
    int n, t1 = 0, t2 = 1, nextTerm = 0;

    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i) {
        // Prints the first two terms.
        if(i == 1) {
            cout << t1 << ", ";
            continue;
        }
        if(i == 2) {
            cout << t2 << ", ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        cout << nextTerm << ", ";
    }
}

// optimised solution(using memoization)

int f[100];
int optmFibo(int n)
{
    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n - 1] == -1)
        {
            f[n - 1] = optmFibo(n - 1);
        }
        else if (f[n - 2] == -1)
        {
            f[n - 2] = optmFibo(n - 2);
        }
        return optmFibo(n - 2) + optmFibo(n - 1);
    }
}

// combination formula:-

int combination(int n, int r)
{
    int t1, t2, t3;
    t1 = factorial(n);
    t2 = factorial(r);
    t3 = factorial(n - r);
    return t1/(t2 * t3);
}

// pascal's triangle (optimised solution)

int pascalTriangle(int n, int r)
{
    if (r == 0 || n == r)
    {
        return 1;
    }
    else
    {
        return pascalTriangle(n - 1, r - 1) + pascalTriangle(n - 1, r);
    }
}

// Tower of hanoi using recursion:-

int toh(int n, int a, int b, int c)
{
    if (n > 0)
    {
        toh(n - 1, a, c, b);
        cout << "Moves from " << a << " to C " << c <<endl;
        toh(n - 1, b, a, c); 
    }
}

int main()
{
    int x = 20;

    // function1(x);

    // cout << endl;

    // function2(x);

    // cout << staticFunc(x) << endl;

    // cout << nonStaticFunc(x) << endl;

    // cout << globalVariableFunc(x);

    // treeRecursion(x);

    // funcA(20);

    // cout << nestedRecursion(95) << endl;
    // cout << nestedRecursion(200) << endl;

    // cout << sumRecursion(5) << endl;

    // cout << factorial(5) << endl;

    // cout << power(5, 4) << endl;

    // cout << e(2, 1) << endl;

    // cout << iterativeE(2, 1) << endl;

    // cout << recursiveE(2, 1) << endl;

    // cout << fiboSeries(7) << endl;

    // cout << optmFibo(7) << endl; 

    // cout << combination(5, 3) << endl;

    // cout << pascalTriangle(5, 3) << endl;

    toh(3, 1, 2, 3);
}