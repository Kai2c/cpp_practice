// Section 11
// Challenge 
/*
    Recall the challenge from Section 9 below.
    Your challenge for section 11 is to modularize your solution to the Section 9
    challenge by refactoring your solution so that it uses uses functions.
    
    You decide how to modularize the program.
    you can use my solution which is included in this file, or modularize your solution.
    
    Here are a few hints:
        - Create functions for each major function
        - Keep the functions small
        - Remember the Boss/Worker analogy
        - Keep the vector declaration in the main function and pass the vector object
          to any function that requires it

        DO NOT move the vector object outside main and make it a global variable.
    
        - You can start by defining a function that displays the menu
        - You can then define a function that reads the selection from the user and returns it in uppercase
        - Create functions for each menu option
        - Create functions that display the list of numbers, calculates the mean and so forth
        
    Take it one function at a time and take your time.
    If you get frustrated, take a break -- this isn't as easy as it looks the first time you do it!
    
    Finally,  don't forget to use function prototypes!
    
    Good luck -- I know you can do it!
*/
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/

/****************************************************************************** 
 * Includes
 *****************************************************************************/
#include <iostream> 
#include <vector> 

/****************************************************************************** 
 * Prototypes
 *****************************************************************************/
void print_menu(void);
bool handle_input(std::vector<int> &vec, char c);
void add_num(std::vector<int> &vec); 
void clear_vec(std::vector<int> &vec);
void find_num(const std::vector<int> &vec);
void display_largest(const std::vector<int> &vec); 
void display_smallest(const std::vector<int> &vec);
void display_mean(const std::vector<int> &vec);
void print_nums(const std::vector<int> &vec);  

/****************************************************************************** 
 * Main
 *****************************************************************************/
int main(void)
{
    std::vector<int> vec; 
    char command {};
    bool quit {false};

    do
    {
        print_menu(); 
        std::cin >> command;
        quit = handle_input(vec, command);
    }while(quit == false);

    return 0;
}

/****************************************************************************** 
 * Function Definitions
 *****************************************************************************/
void print_menu(void)
{
    std::cout << std::endl;
    std::cout << "A - Add a number" << std::endl;
    std::cout << "C - Clear the list" << std::endl;
    std::cout << "F - Find a number" << std::endl;
    std::cout << "L - Display the largest number" << std::endl;
    std::cout << "M - Display mean of the numbers" << std::endl;
    std::cout << "P - Print numbers" << std::endl;
    std::cout << "S - Display the smallest number" << std::endl;
    std::cout << "Q - Quit" << std::endl << std::endl;

    return;
}

bool handle_input(std::vector<int> &vec, char c)
{
    bool ret = false; 
    switch(c)
    {
        case 'a':
        case 'A':
            add_num(vec);
            break;
        case 'c': 
        case 'C': 
            clear_vec(vec);
            break; 
        case 'f': 
        case 'F': 
            find_num(vec);
            break;
        case 'l': 
        case 'L': 
            display_largest(vec);
            break; 
        case 'm': 
        case 'M': 
            display_mean(vec);
            break; 
        case 'p': 
        case 'P': 
            print_nums(vec);
            break; 
        case 's': 
        case 'S': 
            display_smallest(vec);
            break; 
        case 'q': 
        case 'Q':
            std::cout << "Quitting...\n";
            ret = true;
            break; 
        default: 
            break; 
    }

    return ret;
}

void add_num(std::vector<int> &vec)
{
    int num {};

    std::cout << "Enter an integer to add to the list\n";
    std::cin >> num; 
    vec.push_back(num); 
}

void clear_vec(std::vector<int> &vec)
{
    std::cout << "Clearing number list...\n";
    vec.clear();
}

void find_num(const std::vector<int> &vec)
{
    int num {}; 
    bool found = false; 

    std::cout << "Enter an integer to find in the list\n";
    std::cin >> num; 

    for(int i = 0; i < vec.size(); i++)
    {
        if(vec.at(i) == num) 
        {
            std::cout << "Found " << num << " at postiion " << i << " in list\n";
            found = true;
            break;
        }
    }

    if(!found)
    {
        std::cout << "Did not find " << num << " in list\n";
    }
}

void display_largest(const std::vector<int> &vec)
{
    int largest = INT_MIN;

    for(auto el : vec)
    {
        if(el > largest)
        {
            largest = el;
        }
    }

    std::cout << "The largest integer in the list is " << largest << '\n';
}

void display_smallest(const std::vector<int> &vec)
{
    int smallest = INT_MAX; 

    for(auto el : vec)
    {
        if(el < smallest)
        {
            smallest = el;
        }
    }

    std::cout << "The smallest integer in the list is " << smallest << '\n';
}

void display_mean(const std::vector<int> &vec)
{
    double mean {}; 

    for(auto el : vec)
    {
        mean += el;
    }

    mean /= vec.size();

    std::cout << "The mean value of the list is " << mean << '\n';
}

void print_nums(const std::vector<int> &vec)
{
    std::cout << "[ ";
    for(auto el : vec)
    {
        std::cout << el << ' ';
    }
    std::cout << "]\n";
}