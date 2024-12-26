#include <iostream>
#include <fstream>
#include <vector>

using vi = std::vector<int>;

int part1(const vi &elvesCal)
{
    int max = 0;

    for (const int calories : elvesCal)
        if (calories > max)
            max = calories;

    return max;
}

int part2(const vi &elvesCal)
{
    int max3[3]{};

    for (const int calories : elvesCal)
    {
        if (calories > max3[0])
        {
            // Shift the array left to accomodate the new max
            max3[2] = max3[1];
            max3[1] = max3[0];
            max3[0] = calories;
        }
        else if (calories > max3[1])
        {
            // Shift the first 2 elements left to accomodate the new max
            max3[2] = max3[1];
            max3[1] = calories;
        }
        else if (calories > max3[2])
            // Replace the last element with the new max
            max3[2] = calories;
    }

    return max3[0] + max3[1] + max3[2];
}

int main()
{
    std::ifstream input("input.txt");
    std::string cal;

    vi elvesCal;
    int curCal = 0;

    while (std::getline(input, cal))
    {
        if (cal == "")
        {
            // Done with current elf, add calories to vector
            elvesCal.push_back(curCal);
            curCal = 0;
        }
        else
            // Add calories to current elf
            curCal += std::stoi(cal);
    }
    // Add last elf since there is no empty line at the end of the file
    elvesCal.push_back(curCal);

    std::cout << part1(elvesCal) << '\n';
    std::cout << part2(elvesCal) << '\n';

    return 0;
}
