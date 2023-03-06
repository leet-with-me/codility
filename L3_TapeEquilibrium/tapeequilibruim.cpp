#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

// https://app.codility.com/demo/results/trainingDPD2F2-TWG/

int solution(vector<int> &A)
{
    int N = A.size();

    // Calculate for P=1
    int beginTape = A[0];
    int endTape = accumulate(A.begin()+1, A.end(), 0);
    int tapeValue = abs(beginTape - endTape);

    // Try all remaining P values 0 < P < N
    // Except P = 1, since we just did that above
    for(int P = 1; P < N-1; P++)
    {
        // For the next interation, 
        // Add the value from endTape to beginTape
        beginTape += A[P];
        endTape -= A[P];

        // Calculat the tape value
        int newTapeValue = abs(beginTape - endTape);
        //cout << "begin: " << beginTape << " end: " << endTape << " Result: " << tapeVal << endl;
        
        // Check if this new value is the smallest
        if(newTapeValue < tapeValue)
        {
            tapeValue = newTapeValue;
        }
    }

    return tapeValue;
}

int main()
{
    int arr[] = { 3, 1, 2, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> t1(arr, arr + n);
    int result1 = solution(t1);
    cout << result1 << endl;
    assert(result1 == 1);

    int arr2[] = { 3, 1 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> t2(arr2, arr2 + n2);
    int result2 = solution(t2);
    cout << result2 << endl;
    assert(result2 == 2);

    int arr3[] = { -3, -1, -2, 4, -3 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    vector<int> t3(arr3, arr3 + n3);
    int result3 = solution(t3);
    cout << result3 << endl;
    assert(result3 == 1);

    int arr4[] = { -1000, 1000 };
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    vector<int> t4(arr4, arr4 + n4);
    int result4 = solution(t4);
    cout << result4 << endl;
    assert(result4 == 2000);
}