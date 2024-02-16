/* Substitution cipher 
    Map alphabet characters to key characters. 
*/

#include <iostream> 
#include <map>
#include <string>
#include <limits>

class sub_cipher
{
    private:
        std::map<char, char> cipher_map{
            {'a', 'x'},
            {'b', 'y'},
            {'c', 'z'},
            {'d', 'w'},
            {'e', 'v'},
            {'f', 'u'},
            {'g', 't'},
            {'h', 's'},
            {'i', 'r'},
            {'j', 'q'},
            {'k', 'p'},
            {'l', 'o'},
            {'m', 'n'},
            {'n', 'm'},
            {'o', 'l'},
            {'p', 'k'},
            {'q', 'j'},
            {'r', 'i'},
            {'s', 'h'},
            {'t', 'g'},
            {'u', 'f'},
            {'v', 'e'},
            {'w', 'd'},
            {'x', 'c'},
            {'y', 'b'},
            {'z', 'a'},
            {' ', '!'}
        };
        // Function to get keys by value
        char getKeyByValue(const char& value) const {
            char key;
            for (const auto& pair : cipher_map) {
                if (pair.second == value) {
                    key = pair.first;
                }
            }
            return key;
        }
    public:
        std::string encode(std::string str)
        {
            std::string encoded_msg;

            for(char c : str)
            {
                encoded_msg.push_back(cipher_map.at(tolower(c)));
            }

            return encoded_msg;
        }
        std::string decode(std::string code)
        {
            std::string decoded_msg;

            for(char c : code)
            {
                decoded_msg.push_back(getKeyByValue(tolower(c)));
            }

            return decoded_msg;
        }
};

void print_menu(void)
{
    std::cout << "Welcome to the substitution cipher translater\n";
    std::cout << "Options:\n";
    std::cout << "  e - encode\n";
    std::cout << "  d - decode\n";
    std::cout << "  q - quit\n";
    std::cout << std::endl;
}

int main(void)
{
    std::string usr_msg;
    sub_cipher enc;
    bool quit = false;
    char opt{};

    do
    {
        print_menu();
        std::cin >> opt;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(opt)
        {
            case 'e':
                std::cout << "Enter a message to encode (case is ignored).\n" << std::endl;
                std::getline(std::cin, usr_msg, '\n');
                std::cout << "Encoded message: " << enc.encode(usr_msg) << '\n'; 
            break;
            case 'd': 
                std::cout << "Enter a message to decode (case is ignored).\n" << std::endl;
                std::getline(std::cin, usr_msg, '\n');
                std::cout << "Decoded message: " << enc.decode(usr_msg) << '\n'; 
            break; 
            case 'q': 
                std::cout << "Exiting...";
                quit = true;
            break;
            default:
                std::cout << "Invalid command\n";
            break;
        }
    } while (!quit);
    
    return 0;
}