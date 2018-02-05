# /* Kattis: acm
#  *
#  * Topic: others
#  *
#  * Level: easy
#  *
#  * Brief problem description:
#  *
#  *   branching summation
#  *
#  * Solution Summary:
#  *
#  *   basic arithmetic
#  *
#  * Used Resources:
#  *
#  *
#  *
#  * I hereby certify that I have produced the following solution myself
#  * using only the resources listed above in accordance with the CMPUT
#  * 403 collaboration policy.
#  *
#  *
#  * Hung Nguyen
#  */

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
