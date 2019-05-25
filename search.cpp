#include <vector>
#include <iostream>

int linear(const std::vector<int> &my_array, int num)
{
    int index = 0;
    for (const int &i : my_array)
    {
        if (i == num) return index;
        index++;
    }
    return -1;
}

int binary_iterative(const std::vector<int> &my_arr, int num)
{
    int lhs = 0;
    int rhs = my_arr.size() - 1;
    
    while (lhs <= rhs)
    {
        int m = lhs + (rhs - lhs) / 2;
        if (my_arr[m] == num) return m;
        
        if (my_arr[m] < num) lhs = m + 1;
        else rhs = m - 1;
    }
    return -1;
}

int binary_iterative2(const std::vector<int> &my_arr, int num)
{
    int lhs = 0;
    int rhs = my_arr.size() - 1;
    while (rhs - lhs > 1)
    {
        int m = static_cast<int>(((lhs + rhs) / 2) + 0.5);
        if (my_arr[m] <= num) lhs = m;
        else rhs = m;
    }

    return (my_arr[lhs] == num)? lhs : -1;
}

int binary_recursive(const std::vector<int> &my_arr, int num, int lhs, int rhs)
{
    if (rhs > lhs)
    {
        int m = lhs + (rhs + lhs) / 2;
        if (my_arr[m] == num) return m;
        if (my_arr[m] < num) return binary_recursive(my_arr, num, m + 1, rhs);
        else return binary_recursive(my_arr, num, lhs, m - 1);
    }
    return -1;
}


int binary_findFloor(const std::vector<int> &my_arr, int key)
{
    if (key < my_arr[0]) return -1;
    int lhs = 0;
    int rhs = my_arr.size();
    int m;
    while (rhs - lhs > 1)
    {
        m = lhs + (rhs - lhs) / 2;
        if (my_arr[m] <= key) lhs = m;
        else rhs = m;
    }
    return m;
}


int main()
{
    std::vector<int> arr = { 2, 3, 4, 10, 40 };
    int lookup = 6;
    int rtn = binary_findFloor(arr, lookup);
    //int rtn = binary_recursive(arr, lookup, 0, arr.size() - 1);
    (rtn == -1)? std::cout << "Element not found" << std::endl
               : std::cout << "Element found at index " << rtn << std::endl;

    return 0;    
}
