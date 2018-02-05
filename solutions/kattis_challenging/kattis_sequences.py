# /* Kattis: sequences
#  *
#  * Topic: Combinatorics
#  *
#  * Level: challenging
#  *
#  * Brief problem description:
#  *
#  *    Given a string of 0s, 1s and ?'s. Define number of inversions is number of adjacent swap to transform
#  *    the 0 and 1 sequences to 00000..11111..
#  *
#  * Solution Summary:
#  *
#  *    Combinatoric and counting. Traversing the given string and process each character. Each 1 behind a 0
#  *    will incur a swap, ...
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

modulo = 1000000007

line = input()

length = len(line)

numberOfQM = line.count("?")
numberOfCombinations = (1 << numberOfQM) % modulo

no = 0
result = 0
qs = 0
qs1 = 0
qs2 = 0
if numberOfQM == 1:
    qs1 = 1
elif numberOfQM == 2:
    qs1 = 2
    qs2 = 1
elif numberOfQM > 2:
    qs1 = (1 << (numberOfQM - 1)) % modulo
    qs2 = (1 << (numberOfQM - 2)) % modulo

for c in line:
    if c == "1":
        no += 1
    elif c == "0":
        result += no * numberOfCombinations % modulo
        result += qs * qs1 % modulo

    else: # c == ?
        result += no * qs1 % modulo
        result += qs * qs2 % modulo
        qs += 1
    result = result % modulo

print(result)