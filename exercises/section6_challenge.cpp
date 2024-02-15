#include <iostream>

constexpr double SMALL_PRICE    = 25.0;
constexpr double LARGE_PRICE    = 35.0;
constexpr double TAX_RATE_PRCNT = 0.06;
constexpr int    VALID_DAYS = 30;

int main(void)
{
    int small_count {0};
    int large_count {0};

    std::cout << "Hello, welcome to Kai's cleaning service\n";

    std::cout << "How many small rooms would you like cleaned? ";
    std::cin >> small_count;
    std::cout << "How many large rooms would you like cleaned? ";
    std::cin >> large_count; 

    std::cout << "Estimate for cleaning costs:\n";
    std::cout << "For " << small_count << " small rooms, and " << large_count << " large_rooms:\n";
    std::cout << "Price per small room: " << SMALL_PRICE << '\n';
    std::cout << "Price per large room: " << LARGE_PRICE << '\n';
    std::cout << "Tax rate: " << TAX_RATE_PRCNT*100 << "%\n";

    std::cout << "=======================================================" << std::endl;
    std::cout << "Total estimate: $" <<(small_count * SMALL_PRICE + large_count * LARGE_PRICE) * (1 + TAX_RATE_PRCNT) << std::endl;
    std::cout << "This estimate is valid for " << VALID_DAYS << std::endl;
    return 0;
}