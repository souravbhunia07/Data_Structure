#include <iostream>
#include <cstdlib> // Required for rand() and srand()
#include <ctime>   // Required for time()

using namespace std;

// Function to generate a random number between 0 and 1
int ZeroOneRandom() {
    return rand() % 2; // Returns either 0 or 1
}

int uniformRandom(int lower_bound, int upper_bound) {
    int number_of_outcomes = upper_bound - lower_bound + 1, result;
    do {
        result = 0;
        for(int i = 0; (1 << i) < number_of_outcomes; i++) {
            // Using the provided random number generator (ZeroOneRandom())
            result = (result << 1) | ZeroOneRandom();
        }
    } while(result >= number_of_outcomes);
    return result + lower_bound;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    int x, y;
    cout << "Enter lower and upper bounds: ";
    cin >> x >> y;

    cout << uniformRandom(x, y) << endl;
    
    return 0;
}
