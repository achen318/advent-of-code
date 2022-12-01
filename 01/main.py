with open("input.txt", "r") as f:
    data = f.read().splitlines()


def part1():
    max_cal = 0

    current_cal = 0

    for line in data + [""]:
        if line == "":
            if current_cal > max_cal:
                max_cal = current_cal
            current_cal = 0
        else:
            current_cal += int(line)

    print(max_cal)


def part2():
    max_3_cals = [0, 0, 0]

    current_cal = 0

    for line in data + [""]:
        if line == "":
            if current_cal > max_3_cals[0]:
                max_3_cals[0] = current_cal
                max_3_cals.sort()
            current_cal = 0
        else:
            current_cal += int(line)

    print(sum(max_3_cals))


part1()
part2()
