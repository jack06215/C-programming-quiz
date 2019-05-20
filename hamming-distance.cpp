#include <iostream>


int hamming_distance(int x, int y)
{
    int diff = x ^ y;
    int count = 0;
    
    while (diff)
    {
        count++;
        diff = diff & (diff - 1);
    }
    return count;
}


int main()
{
    std::cout << "the answer is: " << hamming_distance(1, 4) << std::endl;
    return 0;
}
