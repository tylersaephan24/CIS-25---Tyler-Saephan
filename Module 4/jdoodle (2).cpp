#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3;

    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;

    // FIXED: Replaced separate if statements with a nested if structure
    if (n1 >= n2)
    {
        // FIXED: Nested comparison to check n1 against n3
        if (n1 >= n3)
        {
            // FIXED: Correctly output n1 as the largest number
            cout << "Largest number: " << n1;
        }
        else
        {
            // FIXED: Output n3 when it is larger than n1 and n2
            cout << "Largest number: " << n3;
        }
    }
    else
    {
        // FIXED: Nested comparison to check n2 against n3
        if (n2 >= n3)
        {
            // FIXED: Corrected output to display n2 (was incorrectly printing n1)
            cout << "Largest number: " << n2;
        }
        else
        {
            // FIXED: Output n3 when it is the largest value
            cout << "Largest number: " << n3;
        }
    }

    return 0;
}
