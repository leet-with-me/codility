#include <vector>
#include <iostream>
#include <map>
#include <numeric>
using namespace std;

// https://app.codility.com/demo/results/trainingE88UHJ-84A/

/**
 * My original code worked, but failed the performance.  I had
 * to find a way to remove the inner loop to fill the values with
 * maxValue.  Now I just keep track of the maxValue and when a fill
 * is needed, I record what that current maxValue is.  Then at the end
 * I replace all the smaller counters with the maxValue.  When the 
 * counter is incremented, it always make sure it greater than the maxValue
 * if we only increment, or if it is less the maxValue, then use the maxValue + 1.
*/

vector<int> solution(int N, vector<int> &A)
{
    // Keep track of the last maxValue
    int maxValue = 0;
    int finalMaxValue = 0;

    // Create a vector to hold the counters initialized to 0
    vector<int> counters(N, 0);


    for(int x = 0; x < (int)A.size(); x++)
    {
        if(A[x] == N+1)
        {
            // Replace all the values in the counters with the latest maxValue
            //counters.assign(N, maxValue);
            // Keep track of the current max
            // All values at the end should be at least greater
            // or equal to this max value
            // Store the final max value, because this may never
            // get called.
            finalMaxValue = maxValue;
            continue;
        }

        if(A[x] >= 1 && A[x] <= N )
        {
            // Increase the indexed value
            int index = A[x]-1;

            // Check if the new value needs to include the new
            // maxValue.  If it does, then include the new max value
            // with the addition
            if(counters[index] < finalMaxValue)
            {
                counters[index] = finalMaxValue + 1;
            }
            else
            {
                // This value is already at least up to max value
                counters[index]++;
            }

            // Set the new max value
            if(counters[index] > maxValue)
            {
                maxValue = counters[index];
            }
        }
    }

    // Now apply any missing maxValues to any counters that are below
    // maxValue.  All counters must at least be greater than or equal to
    // finalMaxValue.  
    for(int y = 0; y < (int)counters.size(); y++)
    {
        if(counters[y] < finalMaxValue)
        {
            // This value was never incremented,
            // so trueup to the last max value
            counters[y] = finalMaxValue;
        }
    }

    return counters;
}

int main()
{
    int arr[] = {3, 4, 4, 6, 1, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> t1(arr, arr + n);
    vector<int> result1 = solution(5, t1);
    for(int x =0; x < result1.size(); x++)
    {
        cout << result1[x] << endl;
    }
}