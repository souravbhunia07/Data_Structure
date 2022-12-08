#include <iostream>
using namespace std;

void generateBracket(string output, int n, int open, int close, int i)
{
    // Base case

    if(i == 2 * n)
    {
        cout << output << endl;
        return;
    }

    // Open

    if(open < n)
    {
        generateBracket(output + '(', n, open + 1, close, i + 1);
    }

    // Closeing

    if(close < open)
    {
        generateBracket(output + ')', n, open, close + 1, i + 1);
    }
}

int main()
{
    string output;
    int n;
    cin >> n;
    generateBracket(output, n, 0, 0, 0);
    return 0;
}