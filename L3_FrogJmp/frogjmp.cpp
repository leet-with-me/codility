#include <cmath>
#include <iostream>
using namespace std;

// https://app.codility.com/demo/results/trainingNRB6JD-PGH/

int solution(int X, int Y, int D)
{
    // D range will never be 0
    // So do not need to protect against dividing by 0.
    // Cast to double to get a double result so that it is
    // within the range of the parameters. Use ceil
    // to round up if needed.
    return ceil(double(Y - X) / (double)D);
}


int main()
{
    int result1 = solution(10, 85, 30);
    cout << result1 << endl;
    assert(result1 == 3);

    int result2 = solution(1, 1, 1);
    cout << result2 << endl;
    assert(result2 == 0);

    int result3 = solution(1, 1, 1000000);
    cout << result3 << endl;
    assert(result3 == 0);

    int result4 = solution(1, 2, 1000000);
    cout << result4 << endl;
    assert(result4 == 1);

    int result5 = solution(1, 1000000, 2);
    cout << result5 << endl;
    assert(result5 == 500000);

    int result6 = solution(3, 999111321, 7);
    cout << result6 << endl;
    assert(result6 == 142730189);
}