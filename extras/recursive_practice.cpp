#include <iostream> 
#include <assert.h>

int sum_of_array(const int (&arr)[], size_t len)
{
    if(len == 0)
        return 0;

    return arr[len - 1] + sum_of_array(arr, len - 1);
}

void print_array(const int arr[], int start, int end) {
    if (start > end) {
        return;
    }
    
    // Print current element
    std::cout << arr[start] << " ";
    
    // Recursively call printArray for the next element
    print_array(arr, start + 1, end);
}

void test(const int (&arr)[], size_t arr_len, int expected_sum);

int main(void)
{
    const int test_array0[1] {};
    size_t len0 = 1;
    int expect0 = 0; 
    const int test_array1[1] = {0}; 
    size_t len1 = 1;
    int expect1 = 0; 
    const int test_array2[] = {0, 1, 2, 3, 4, 5};
    size_t len2 = 6;
    int expect2 = 15; 
    const int test_array3[] = {0, -1, -2, -3, -4 , -5};
    size_t len3 = 6;
    int expect3 = -15;

    test(test_array0, len0, expect0); 
    test(test_array1, len1, expect1); 
    test(test_array2, len2, expect2); 
    test(test_array3, len3, expect3); 

    return 0; 
}

void test(const int (&arr)[], size_t arr_len, int expected_sum)
{
    std::cout << "Sum = " << sum_of_array(arr, arr_len) << " for array: " ;
    print_array(arr, 0, arr_len -1);
    std::cout << std::endl;

    assert(sum_of_array(arr, arr_len) == expected_sum);

    return;
} 
