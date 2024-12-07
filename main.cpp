#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>

int random_pick(int min, int max)
{
    return std::rand() % (max - min + 1) + min;
}

std::string f3()
{
    const int p1 = random_pick(25, 29);
    const int p2 = random_pick(25, 29);
    const int p3 = random_pick(25, 29);

    char buf[128];
    switch(std::rand() % 3){
        case 0:
            {
                std::sprintf(buf, "%2d + %2d + %2d =", p1, p2, p3);
                break;
            }
        case 1:
            {
                std::sprintf(buf, "%2d + %2d - %2d =", p1 + p2, p3, p1);
                break;
            }
        default:
            {
                std::sprintf(buf, "%2d - %2d + %2d =", p1 + p2, p1, p3);
                break;
            }
    }
    return buf;
}

std::string f2()
{
    const int p1 = random_pick(25, 29);
    const int p2 = random_pick(25, 29);

    char buf[128];
    if(std::rand() % 2){
        std::sprintf(buf, "%2d + %2d =", p1, p2);
    }
    else{
        std::sprintf(buf, "%2d - %2d =", p1 + p2, p2);
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
            std::cout << f2() << "          " << f2() << "          " << f2() << std::endl;
        }
    }
    else if(digits == 3){
        for(int j = 0; j < lines; ++j){
            std::cout << f3() << "          " << f3() << std::endl;
        }
    }
    return 0;
}
