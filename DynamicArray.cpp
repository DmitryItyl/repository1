#include <iostream>
#include <vector>

void showVector(std::vector<int> vector);

int main()
{
    std::cout << "Enter the size of your array:" << std::flush;
    size_t size;
    std::cin >> size;

    std::vector<int> numbers(size);

    for (size_t i = 0; i < numbers.size(); i++)
    {
        std::cout << "Enter the element a[" << i << "] =  " << std::flush;
        std::cin >> numbers[i];
    }

    std::cout << "Your array" << std::endl;
    showVector(numbers);

    bool swap = true;
    while (swap)
    {
        swap = false;
        for (size_t i = 0; i < numbers.size() - 1; i++) {
            if (numbers[i] > numbers[i + 1]) {
                std::swap(numbers[i], numbers[i + 1]);
                swap = true;
            }
        }
    }

    std::cout << std::endl << "===============" << std::endl << "Your array sorted:" << std::endl;
    showVector(numbers);

    return 0;
}


void showVector(std::vector<int> vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << "     " << std::flush;
    }
}