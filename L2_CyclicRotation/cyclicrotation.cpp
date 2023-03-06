#include <vector>
#include <iostream>
using namespace std;

https://app.codility.com/demo/results/trainingAEYMSY-5NE/

vector<int> solution(vector<int> &A, int K) {
    // Get the size of the vector
    int N = A.size();

    if(K == 0 || N == 0)
    {
        return A;
    }

    // If multiple wraps will occur, narrow it down to a single wrap
    if(K > N)
    {
        K = K % N;
    }

    // Initialize the vector to the correct size with 0s
    vector<int> result(N, 0);

    // Go through each value and shift it
    for(int x = 0; x < N; x++)
    {
        // Check if the value is wrapping
        if(x <= ((N-K)-1))
        {
            // No wrap so just assign
            result.at(x+K) = A.at(x);
        }
        else
        {
            // Get the wrap index
            // This will determine the number of positions it will
            // consume before the wrap (N - (x+1)).
            // Then determine the number of positions it will consume
            // after the wrap starting at 0.  And subtract 1 for 0-based index.
            int index = (K - (N - (x+1))) - 1;
            result.at(index) = A.at(x);
        }
    }

    return result;
}


int main()
{
    //vector<int> t1{ 3, 8, 9, 7, 6 };
    int arr[] = { 3, 8, 9, 7, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> t1(arr, arr + n);

    vector<int> result1 = solution(t1, 3);

    for (int x : result1)
        cout << x << " ";
    cout << endl;

    vector<int> result2 = solution(t1, 0);

    for (int x : result2)
        cout << x << " ";
    cout << endl;

    int arr3[] = { 3 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    vector<int> t3(arr3, arr3 + n3);
    vector<int> result3 = solution(t3, 2);

    for (int x : result3)
        cout << x << " ";
    cout << endl;

    int arr4[] = { 1, 1, 2, 3, 5 };
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    vector<int> t4(arr4, arr4 + n4);
    vector<int> result4 = solution(t4, 42);

    for (int x : result4)
        cout << x << " ";
    cout << endl;
    //expected [3, 5, 1, 1, 2]
}