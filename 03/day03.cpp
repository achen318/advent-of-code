#include <iostream>
#include <fstream>

int part1(fstream input)
{
    std::string priority = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int sum = 0;

    std::string rucksack;
    std::string compartment0;
    std::string compartment1;

    while (input >> rucksack)
    {
        int size = rucksack.length();
        compartment0 = rucksack.substr(0, size / 2);
        compartment1 = rucksack.substr(size / 2, size);

        for (char c : compartment0)
            if (compartment1.find(c) != std::string::npos)
            {
                sum += priority.find(c);
                break;
            }
    }

    return sum;
}

int main()
{
    std::fstream input("input.txt");

    std::cout << part1(input) << '\n';

    return 0;
}
