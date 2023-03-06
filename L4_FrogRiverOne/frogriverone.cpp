#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

// https://app.codility.com/demo/results/trainingHMYHYY-9XJ/

/**
 * This problem is very poorly worded.
 * 
 * Basically you are given a number X, then you
 * have to ensure you find all values in the array 1-X.
 * So if X = 5, you must find 1, 2, 3, 4, and 5 in the array.  They do
 * not need to be in order.  Once you have found all the values,
 * give the index when the last value was found.  If you have duplicates,
 * you ignore the duplicate value.  You only care that you find
 * at least one of the 1 - X.  If a value is missing, say X = 5 and the array
 * does not contain the value 2, then you will return -1 because
 * you can never cross the river because a leaf never fell at position 2.
 *
 * So go through the vector and determine all the positions you have found,
 * once you find all the positions, then return the last index that got you
 * to all the positions.
 */

int solution(int X, vector<int> &A)
{
    // Keep track of all the positions found
    vector<bool> positionSeen(X + 1);

    // Keep track of how many positions have been found
    int positionsFound = 0;

    // Go through the array looking at all the positions
    // We are trying to find all the positions 1 - X.
    for (int i = 0; i < (int)A.size(); ++i)
    {
        // Check if we have already seen this position
        // The value is the position
        if (!positionSeen[A[i]])
        {
            // If we not seen this position
            // Then it is new and we can remove the number
            // of position left to find
            positionsFound++;

            // If we find all the positions, we are done
            // Return i, which is the number of times
            // we checked for all positions
            if (positionsFound == X)
            {
                return i;
            }

            // Mark that this position has been seen
            positionSeen[A[i]] = true;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 3, 1, 4, 2, 3, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> t1(arr, arr + n);
    int result1 = solution(5, t1);
    cout << result1 << endl;
    assert(result1 == 6);

    int arr2[] = {1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> t2(arr2, arr2 + n2);
    int result2 = solution(1, t2);
    cout << result2 << endl;
    assert(result2 == 0);

    int arr3[] = {3};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    vector<int> t3(arr3, arr3 + n3);
    int result3 = solution(5, t3);
    cout << result3 << endl;
    assert(result3 == -1);
}
