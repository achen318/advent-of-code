with open("input.txt", "r") as f:
    data = f.read().splitlines()


def part1():
    moves = {"A": "X", "B": "Y", "C": "Z"}
    total_score = 0

    for line in data:
        opp, you = line.split()

        total_score += ord(you) - 87

        if moves[opp] == you:
            total_score += 3
        else:
            if opp == "A":
                total_score += 6 if you == "Y" else 0
            elif opp == "B":
                total_score += 6 if you == "Z" else 0
            else:
                total_score += 6 if you == "X" else 0

    print(total_score)


def part2():
    total_score = 0

    for line in data:
        opp, result = line.split()

        # Lose
        if result == "X":
            if opp == "A":
                total_score += 3
            elif opp == "B":
                total_score += 1
            else:
                total_score += 2

        # Draw
        elif result == "Y":
            total_score += ord(opp) - 64 + 3

        # Win
        else:
            if opp == "A":
                total_score += 2
            elif opp == "B":
                total_score += 3
            else:
                total_score += 1

            total_score += 6

    print(total_score)


part1()
part2()
