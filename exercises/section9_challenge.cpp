/* Vector manipulation based on user inputs
    Commands: 
        * A or a - prompt the user for an integer input and add it to the list
        * C or c - clear vector
        * M or m - calculate and display the mean 
        * S or s - display the smallest element
        * L or l - display the largest element
        * P or p - print the list of values
        * Q or q - display 'Goodbye' and quit
*/

#include <iostream>
#include <vector>

class VectorManager
{
    private:
        std::vector <int> vec{};
    public:
        void add_element(int num)
        {
            vec.push_back(num);
        }

        void clear_vec(void)
        {
            vec.clear();
        }

        void print_vect(void)
        {
            std::cout << "[ ";
            for(auto el : vec)
            {
                std::cout << el << ' ';
            }
            std::cout << "]\n";
        }

        double calc_mean(void)
        {
            int sum = 0;
            for(auto el : vec)
            {
                sum += el;
            }
            return sum / vec.size();
        }

        int get_smallest(void)
        {
            int s = INT_MAX; 
            
            for(auto el : vec)
            {
                s = std::min(s, el);
            }
            
            return s;
        } 

        int get_largest(void)
        {
            int s = INT_MIN; 

            for(auto el : vec)
            {
                s = std::max(s, el);
            }

            return s;
        }
};

class InputHandler : private VectorManager
{
    private:
        bool quit = false;
    public:
        bool get_quit(void)
        {
            return quit;
        }
        void print_menu(void)
        {
            std::cout << std::endl;
            std::cout << "Vector Manipulation Commands\n";
            std::cout << "  A - Add an integer to the vector\n";
            std::cout << "  C - Clear the vector\n";
            std::cout << "  M - Display the mean of the values\n";
            std::cout << "  S - Display the smallest of the values\n";
            std::cout << "  L - Display the largest of the values\n";
            std::cout << "  P - Print the list of values\n";
            std::cout << "  Q - Quit this program\n";
        }
        void handle_input(char in_char)
        {
            switch(in_char)
            {
                case 'A':
                case 'a':
                    int num;
                    std::cout << "Enter the integer to add: ";
                    std::cin >> num;
                    add_element(num);
                    break;

                case 'C': 
                case 'c':
                    clear_vec();
                    break;

                case 'M':
                case 'm':
                    std::cout << calc_mean() << '\n';
                    break;

                case 'S':
                case 's':
                    std::cout << get_smallest() << '\n';
                    break;

                case 'L':
                case 'l':
                    std::cout << get_largest() << '\n';
                    break;

                case 'P':
                case 'p':
                    print_vect();
                    break;

                case 'Q':
                case 'q':
                    std::cout << "Goodbye...\n";
                    quit = true;
                    break;

                default:
                    std::cout << "Invalid input\n"; 
                    break;
            }
        }
};

int main(void)
{
    InputHandler in_hndlr;
    char input;
    do
    {
        in_hndlr.print_menu();
        std::cin >> input; 
        in_hndlr.handle_input(input);
    } while (in_hndlr.get_quit() == false);
    
}