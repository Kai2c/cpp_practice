#include <iostream> 
#include <vector>

int main(void)
{
    std::vector <int> vector1;
    std::vector <int> vector2;
    
    vector1.push_back(10); 
    vector1.push_back(20);

    for(int i = 0; i < vector1.size(); i++)
    {
        std::cout << "vector1 value at " << i << " is " << vector1.at(i) << std::endl;
    }

    vector2.push_back(100); 
    vector2.push_back(200);

    for(int i = 0; i < vector2.size(); i++)
    {
        std::cout << "vector2 value at " << i << " is " << vector2.at(i) << std::endl;
    }


    std::vector <std::vector <int>> vector_2d;

    vector_2d.push_back(vector1); 
    vector_2d.push_back(vector2);

    for(int i = 0; i < vector_2d.size(); i++)
    {
        for(int j = 0; j < vector_2d.at(i).size(); j++)
        {
            std::cout << "value of vector2d[" << i << "][" << j << "] is " << vector_2d.at(i).at(j) << std::endl; 
        }
    }

    std::cout << "Assigning vector1[0] = 1000" << std::endl;
    vector1.at(0) = 1000;

    for(int i = 0; i < vector_2d.size(); i++)
    {
        for(int j = 0; j < vector_2d.at(i).size(); j++)
        {
            std::cout << "value of vector2d[" << i << "][" << j << "] is " << vector_2d.at(i).at(j) << std::endl; 
        }
    }


    for(int i = 0; i < vector1.size(); i++)
    {
        std::cout << "vector1 value at " << i << " is " << vector1.at(i) << std::endl;
    }

    return 0;
}