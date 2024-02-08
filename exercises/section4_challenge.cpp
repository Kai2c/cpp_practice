#include <iostream>

int main(void)
{
    int fav_num = 0; 
    int ret = 0; 

    std::cout << "Enter your favorite number between 1 and 100\n";

    std::cin >> fav_num; 

    if (fav_num < 1 || fav_num > 100)
    {
        std::cout << "Error, your favorite number must be between 1 and 100\n";
        ret = -1;    
    }
    else
    {
        std::cout << "Amazing!! That's my favorite number too!\n";
        std::cout << "No really!!, " << fav_num << " is my favorite number!\n";
    }

    return ret;
}