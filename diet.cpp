#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

int main()
{   
    int arr1[] = {1,3,5,7,10};
    int arr2[] = {2,3,7,8,9};
    int target = 12;
    int high = target + 1;
    int low = target - 1;

    int width = sizeof(arr1)/sizeof(arr1[0]);
    int height = sizeof(arr2)/sizeof(arr2[0]);
    std::vector<int> sum;
    std::unordered_set<int> result;

    for (const int& i : arr1)
        for (const int& j : arr2)
            sum.push_back(i + j);

    int stride = sizeof(arr1)/sizeof(arr1[0]);
    int idx_h = 0;
    int buttom = sizeof(arr2)/sizeof(arr2[0]);
    int step = buttom;
    while (idx_h < buttom || step < 0)
    {
        int col = step - 1;
        int row = stride * idx_h;
        
        if (sum[col + row] < target)
        {
            for (int i = 0; i < step; i++)
            {
                int tmp = sum[row + i];
                if (std::abs(tmp-low) < (high-low))
                {
                    std::cout << "arr1[" << i << "] + arr2[" << row << "] = " << tmp << std::endl;
                    result.insert(tmp);
                }
            }
        }
        
        else if (sum[col + row] >= target)
        {
            for (int i = col + row; i < buttom * stride; i+=stride)
            {
                int tmp = sum[i];
                if (std::abs(tmp-low) < (high-low))
                {
                    std::cout << "arr1[" << i-stride << "] + arr2[" << row << "] = " << tmp << std::endl;
                    result.insert(tmp);
                }
            }
        }
        idx_h++;
        step--;
    }
    
    for (const int& num: result)
        std::cout << num << " ";

    std::cout << '\n';

    return 0;
}
