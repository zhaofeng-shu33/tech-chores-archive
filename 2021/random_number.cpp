#include <random>
#include <iostream>
int main() {
std::random_device dev;
    std::default_random_engine generator(dev());
    std::uniform_real_distribution<double> distribution(0, 1);
    for (int i = 0; i < 10; i++) {
        double random_number = distribution(generator);
        std::cout << random_number << std::endl;
    }
}
