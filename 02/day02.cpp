#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using vs = std::vector<std::string>;
using msi = std::map<std::string, int>;

constexpr int ROCK = 1;
constexpr int PAPER = 2;
constexpr int SCISSORS = 3;

constexpr int LOSE = 0;
constexpr int DRAW = 3;
constexpr int WIN = 6;

int part1(const vs &rounds)
{
    int total = 0;

    // A/X: rock, B/Y: paper, C/Z: scissors
    const msi outcomes = {
        {"A X", ROCK + DRAW},
        {"A Y", PAPER + WIN},
        {"A Z", SCISSORS + LOSE},
        {"B X", ROCK + LOSE},
        {"B Y", PAPER + DRAW},
        {"B Z", SCISSORS + WIN},
        {"C X", ROCK + WIN},
        {"C Y", PAPER + LOSE},
        {"C Z", SCISSORS + DRAW}};

    for (const std::string &round : rounds)
        total += outcomes.at(round);

    return total;
}

int part2(const vs &rounds)
{
    int total = 0;

    // A: rock, B: paper, C: scissors
    // X: lose, Y: draw, Z: win
    const msi outcomes = {
        // Input: rock
        {"A X", LOSE + SCISSORS},
        {"A Y", DRAW + ROCK},
        {"A Z", WIN + PAPER},
        // Input: paper
        {"B X", LOSE + ROCK},
        {"B Y", DRAW + PAPER},
        {"B Z", WIN + SCISSORS},
        // Input: scissors
        {"C X", LOSE + PAPER},
        {"C Y", DRAW + SCISSORS},
        {"C Z", WIN + ROCK}};

    for (const std::string &round : rounds)
        total += outcomes.at(round);

    return total;
}

int main()
{
    std::ifstream input("input.txt");
    std::string round;

    vs rounds;

    while (std::getline(input, round))
        rounds.push_back(round);

    std::cout << part1(rounds) << '\n';
    std::cout << part2(rounds) << '\n';

    return 0;
}
