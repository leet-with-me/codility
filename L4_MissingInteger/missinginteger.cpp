#include <vector>
#include <iostream>
#include <map>
#include <numeric>
using namespace std;

// https://app.codility.com/demo/results/training7ATGV2-GSH/

int solution(vector<int> &A) {
    // Implement your solution here
    int maxValue = 0;

    map<int, bool> vals;

    for(int x = 0; x < (int)A.size(); x++)
    {
        if(A[x] >= 1)
        {
            vals[A[x]] = true;
        }

        // Used to limit the search
        if(A[x] > maxValue)
        {
            maxValue = A[x];
        }
    }

    // No values were found
    if(vals.size() == 0)
    {
        return 1;
    }

    // Go through the found values to see what is the next smallest value
    for(int y = 1; y <= maxValue; y++)
    {
        // If we found a gap
        // Return that value
        if(!vals[y])
        {
            return y;
        }
    }

    // If we get here, it means we did not find a value yet
    // This can mean that we have a list in order with no gaps
    // So we will get the next value after max value
    return maxValue + 1;
}

int main()
{
    int arr[] = {1, 3, 6, 4, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> t1(arr, arr + n);
    int result1 = solution(t1);
    assert(result1 == 5);
}
