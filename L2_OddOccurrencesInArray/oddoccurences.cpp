#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// https://app.codility.com/demo/results/trainingS8EZZY-QG3/

int solution(vector<int> &A)
{
    // Create a map to keep track of values already used
    unordered_map<int, int> combos;

    // Go through the vector
    for (int x : A)
    {
        // Check if the key is contained within the map
        //if(combos.contains(x))  C++20
        if(combos.find(x) == combos.end())
        {
            // Add the key, since it is our first time finding it
            combos[x]++;
        }
        else
        {
            // Remove it since the key exists
            combos.erase(x);
        }
    }

    // Return what should be the first and only key
    return combos.begin()->first;
}


int main()
{
    int arr[] = { 3, 3, 9, 9, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> t1(arr, arr + n);
    int result1 = solution(t1);
    cout << result1 << endl;
    assert(result1 == 6);

    int arr2[] = { 9, 3, 9, 3, 9, 7, 9 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> t2(arr2, arr2 + n2);
    int result2 = solution(t2);
    cout << result2 << endl;
    assert(result2 == 7);

    int arr3[] = { 9 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    vector<int> t3(arr3, arr3 + n3);
    int result3 = solution(t3);
    cout << result3 << endl;
    assert(result3 == 9);

    int arr4[] = { 3,3,3,3,3 };
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    vector<int> t4(arr4, arr4 + n4);
    int result4 = solution(t4);
    cout << result4 << endl;
    assert(result4 == 3);
}