

def solution(N: int) -> int:
    """
    A binary gap within a positive integer N is any maximal 
    sequence of consecutive zeros that is surrounded by 
    ones at both ends in the binary representation of N.

    For example, number 9 has binary representation 1001 
    and contains a binary gap of length 2. The number 529 
    has binary representation 1000010001 and contains two 
    binary gaps: one of length 4 and one of length 3. The 
    number 20 has binary representation 10100 and contains 
    one binary gap of length 1. The number 15 has binary 
    representation 1111 and has no binary gaps. The number 
    32 has binary representation 100000 and has no binary gaps.

    Write a function:

    int solution(int N);

    that, given a positive integer N, returns the length of 
    its longest binary gap. The function should return 0 if 
    N doesn't contain a binary gap.

    For example, given N = 1041 the function should return 
    5, because N has binary representation 10000010001 and 
    so its longest binary gap is of length 5. Given N = 32 
    the function should return 0, because N has binary 
    representation '100000' and thus no binary gaps.

    Write an efficient algorithm for the following assumptions:

    N is an integer within the range [1..2,147,483,647].

    @desc: Convert N to binary. Go there each digit and find 
    the first 1 Then look for the next 1.  Keep track of 
    number of moves after next 1, look for the next 1 again 
    until the end.  
 
 
    Args:
        N (int): Integer input [1..2,147,483,647]

    Returns:
        int: Largest binary gap.
    """
    # Check for 0 or less than 0
    # Cannot divide by zero and range is only positive integers
    if N <= 0:
        return 0

    # Init values
    test_val = N
    count = 0
    first_1_found = False
    max_count = 0
    debug_result = ""

    # Convert to binary
    while int(test_val) > 0:
        # Cast to int to ensure an int result
        temp = int(test_val) % 2

        # DEBUG OUTPUT
        #debug_result += str(temp)
        
        if temp == 1 and first_1_found == False:
            # First 1 found
            # Start counting zeros
            first_1_found = True
            count = 0
        elif temp == 1 and first_1_found == True:
            # Find a 1, so check if this is the largest count
            # Set the new max value
            if count > max_count:
                max_count = count
            # Reset the count
            count = 0
        else:
            # Zero found, so count
            count += 1

        # Move to the next value
        test_val /= 2


    # DEBUG OUTPUT
    #print(debug_result)

    # Return largest count
    return max_count


if __name__ == "__main__":
    result = solution(1041)
    print("{}".format(result))
    assert(result == 5)

    result = solution(32)
    print("{}".format(result))
    assert(result == 0)

    result = solution(0)
    print("{}".format(result))
    assert(result == 0)

    result = solution(529)
    print("{}".format(result))
    assert(result == 4)

    result = solution(20)
    print("{}".format(result))
    assert(result == 1)

    result = solution(15)
    print("{}".format(result))
    assert(result == 0)

    result = solution(2147483647)
    print("{}".format(result))
    assert(result == 0)

    result = solution(1)
    print("{}".format(result))
    assert(result == 0)

    result = solution(-1)
    print("{}".format(result))
    assert(result == 0)
    
    result = solution(2147483648)
    print("{}".format(result))
    assert(result == 0)
