line = input()

point = 0
penalty = 0

problems = dict()

while line != "-1":

    try:
        line = line.split(" ")
        # print(line)
        if line[2] == "right":
            point += 1
            penalty += int(line[0])
            penalty += problems[line[1]] * 20
        else:
            problems[line[1]] += 1
    except KeyError:
        problems[line[1]] = 1

    line = input()

print(str(point) + " " + str(penalty))
