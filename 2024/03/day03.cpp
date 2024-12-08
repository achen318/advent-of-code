#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

int part_1(string memory)
{
    int results = 0;

    regex pattern(R"(mul\((\d+),(\d+)\))");

    for (sregex_iterator it(memory.begin(), memory.end(), pattern), end_it; it != end_it; ++it)
        results += stoi(it->str(1)) * stoi(it->str(2));

    return results;
}

int part_2(string memory)
{
    int results = 0;

    memory = "do()" + memory + "don't()";

    regex pattern(R"(do\(\)(.*?)don't\(\))");

    for (sregex_iterator it(memory.begin(), memory.end(), pattern), end_it; it != end_it; ++it)
        results += part_1(it->str(1));

    return results;
}

int main()
{
    ifstream input("input.txt");
    string memory;
    string line;

    while (getline(input, line))
        memory += line;

    cout << part_1(memory) << '\n';
    cout << part_2(memory) << '\n';

    return 0;
}
