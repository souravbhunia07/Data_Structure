#include <iostream>
using namespace std;

void findSubset(char *input, char *output, int i, int j)
{
    // Base case

    if(input[i] == '\0')
    {
        output[j] = '\0';
        if(output[0] == '\0')
        {
            cout << "NULL" << endl;
        }
        cout << output << endl;
        return;
    }

    // Recursive case
    // Including Ith letter

    output[j] = input[i];
    findSubset(input, output, i + 1, j + 1);

    // Excluding the Ith letter
    // Overwritting

    findSubset(input, output, i + 1, j);
}

int main()
{
    char input[100];
    char output[100];
    cin >> input;
    findSubset(input, output, 0, 0);
    return 0;
}
