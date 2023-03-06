#include <map>
#include <vector>
#include <iostream>
using namespace std;

// https://app.codility.com/demo/results/trainingKZPGAY-WTA/

int solution(vector<int> &A)
{
    // If empty return 1
    if(A.empty())
    {
        return 1;
    }

    // If only a single entry
    // return the next after this entry or before the entry
    if(A.size() == 1)
    {
        // Check if we will give the first available value
        // in the front or back based on the value
        if(A[0] <= 1)
        {
            return A[0] + 1;
        }
        else
        {
            return A[0] - 1;
        }
    }

    // Create a map to keep track of all values
    map<int, int> mapTracker;

    int minValue = 100001;
    int maxValue = 0;
    for (int x : A)
    {
        // Store all the values 
        // with the Key the integer value
        // and the Value as 1.
        mapTracker[x] = 1;

        // Keep track of the minimum value
        if(x < minValue)
        {
            minValue = x;
        }

        // Keep track of the maximum value
        if(x > maxValue)
        {
            maxValue = x;
        }
    }

    // Look for missing value
    for(int y = minValue; y < maxValue; y++)
    {
        if(mapTracker[y] != 1)
        {
            return y;
        }
    }
    
    // If none are found,
    // Look if we can use the (minValue - 1) or (maxValue+1)
    if(minValue - 1 >= 1)
    {
        return minValue - 1;
    }
    
    return maxValue + 1;
}

int main()
{
    int arr[] = { 2, 3, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> t1(arr, arr + n);
    int result1 = solution(t1);
    cout << result1 << endl;
    assert(result1 == 4);


    int arr2[] = { 0, 3, 1, 5, 2 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> t2(arr2, arr2 + n2);
    int result2 = solution(t2);
    cout << result2 << endl;
    assert(result2 == 4);


    int arr3[] = { 99999, 99998, 99996, 99994, 99995, 100000 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    vector<int> t3(arr3, arr3 + n3);
    int result3 = solution(t3);
    cout << result3 << endl;
    assert(result3 == 99997);

    int arr4[] = { };
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    vector<int> t4(arr4, arr4 + n4);
    int result4 = solution(t4);
    cout << result4 << endl;
    assert(result4 == 1);

    int arr5[] = { 1 };
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    vector<int> t5(arr5, arr5 + n5);
    int result5 = solution(t5);
    cout << result5 << endl;
    assert(result5 == 2);

    int arr6[] = { 2 };
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    vector<int> t6(arr6, arr6 + n6);
    int result6 = solution(t6);
    cout << result6 << endl;
    assert(result6 == 1);

    int arr7[] = { 1, 2, 3, 4, 5 };
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    vector<int> t7(arr7, arr7 + n7);
    int result7 = solution(t7);
    cout << result7 << endl;
    assert(result7 == 6);
}