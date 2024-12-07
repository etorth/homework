#include <array>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>

int random_pick(int min, int max)
{
    return std::rand() % (max - min + 1) + min;
}

int split(int sum)
{
    const auto fn = [sum]() -> int
    {
        if(sum % 10 == 9){
            return random_pick(sum / 3, sum / 2);
        }

        const int sum_ones_digit = sum % 10; // 0 ~ 8

        const int p1_ones_digit = random_pick(sum_ones_digit + 1, 9);
        const int p1_tens_digit = random_pick(sum / 3, sum / 2) / 10;

        return p1_tens_digit * 10 + p1_ones_digit;
    };

    while(true){
        if(auto p = fn(); p < sum){
            return p;
        }
    }
    return 0;
}

std::string f3(int sum)
{
    const int p3 = split(sum);
    const int p2 = split(sum - p3);
    const int p1 = sum - p2 - p3;

    char buf[128];
    switch(std::rand() % 4){
        case 0:
            {
                std::sprintf(buf, "%2d + %2d + %2d =", p1, p2, p3);
                break;
            }
        case 1:
            {
                std::sprintf(buf, "%2d + %2d - %2d =", p1 + p2, p3, split(p1 + p2 + p3));
                break;
            }
        case 2:
            {
                std::sprintf(buf, "%2d - %2d + %2d =", p1 + p2 + p3, p3, split(p1 + p2));
                break;
            }
        default:
            {
                std::sprintf(buf, "%2d - %2d - %2d =", p1 + p2 + p3, p3, p2);
                break;
            }
    }
    return buf;
}

int main(int argc, char *argv[])
{
    if(argc != 3){
        std::fprintf(stderr, "Usage: calc max_sum lines\n");
        return 1;
    }

    std::srand(std::time(nullptr));

    const int max_sum = std::atoi(argv[1]);
    const int lines   = std::atoi(argv[2]);

    if(max_sum < 30 || max_sum >= 100){
        std::fprintf(stderr, "max_sum must be >= 30 and < 100\n");
        return 1;
    }

    if(lines < 1){
        std::fprintf(stderr, "lines must be >= 1\n");
        return 1;
    }

    for(int i = 0; i < lines; ++i){
        std::cout << f3(max_sum) << "       " << f3(max_sum) << "       " << f3(max_sum) << "       " << f3(max_sum) << std::endl;
    }
    return 0;
}
