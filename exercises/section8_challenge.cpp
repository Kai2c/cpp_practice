/* Accept user input for number of cents then return the number of each 
   monetary denomination needed to make that amount*/

#include <iostream> 

class US_CoinConverter
{
    private: 
        struct US_Coins
        {
            int dollars;
            int quarters;
            int dimes; 
            int nickels; 
            int pennies;
        };  

        US_Coins coins;

    public:
        US_CoinConverter(int cents)
        {
            cents_to_coins(cents); 
            print_coins();
        }

        void cents_to_coins(int cents)
        {
            coins.dollars = cents / 100; 
            cents %= 100;
            coins.quarters = cents / 25; 
            cents %= 25; 
            coins.dimes = cents / 10; 
            cents %= 10; 
            coins.nickels = cents / 5; 
            cents %= 5; 
            coins.pennies = cents;
        }

        void print_coins() 
        {
            std::cout << "Dollars: " << coins.dollars << std::endl;
            std::cout << "Quarters: " << coins.quarters << std::endl;
            std::cout << "Dimes: " << coins.dimes << std::endl;
            std::cout << "Nickels: " << coins.nickels << std::endl;
            std::cout << "Pennies: " << coins.pennies << std::endl;
        }
};

int main(void)
{
    int num_cents;

    std::cout << "Enter the number of cents\n";
    std::cin >> num_cents; 

    US_CoinConverter converter(num_cents);    

}