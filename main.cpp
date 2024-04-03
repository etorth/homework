#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>

std::string f3()
{
    const int sum = (std::rand() % 35) + 15;

    const int p1 = std::clamp(std::rand() % (sum     ), 6, 33);
    const int p2 = std::clamp(std::rand() % (sum - p1), 7, 42);

    const int p3 = std::max<int>(sum - p1 - p2, 8);

    char buf[128];
    switch(std::rand() % 3){
        case 0:
            {
                std::sprintf(buf, "%2d + %2d + %2d = ____", p1, p2, p3);
                break;
            }
        case 1:
            {
                std::sprintf(buf, "%2d + %2d - %2d = ____", p1 + p2, p3, p1);
                break;
            }
        default:
            {
                std::sprintf(buf, "%2d - %2d + %2d = ____", p1 + p2, p1, p3);
                break;
            }
    }
    return buf;
}

std::string f2()
{
    const int sum = (std::rand() % 35) + 15;
    const int p1 = std::clamp(std::rand() % sum, 7, 42);

    char buf[128];
    if(std::rand() % 2){
        const auto p2 = sum - p1;
        std::sprintf(buf, "%2d + %2d = ____", p1, p2);
    }
    else{
        std::sprintf(buf, "%2d - %2d = ____", sum, p1);
    }

    return buf;
}

int main(int, char *argv[])
{
    std::srand(std::time(nullptr));

    const int digits = std::atoi(argv[1]);
    const int  lines = std::atoi(argv[2]);

    if(digits == 2){
        for(int j = 0; j < lines; ++j){
            for(int i = 0; i < 7; ++i){
                std::cout << f2() << "          " << f2() << "          " << f2() << std::endl;
            }
            std::cout << std::endl;
            std::cout << std::endl;
        }
    }
    else if(digits == 3){
        for(int j = 0; j < lines; ++j){
            for(int i = 0; i < 7; ++i){
                std::cout << f3() << "          " << f3() << std::endl;
            }
            std::cout << std::endl;
            std::cout << std::endl;
        }
    }
    return 0;
}
