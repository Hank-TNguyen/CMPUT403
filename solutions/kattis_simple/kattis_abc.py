# /* Kattis: abc
#  *
#  * Topic: others
#  *
#  * Level: easy
#  *
#  * Brief problem description:
#  *
#  *   ordering number according to a given order
#  *
#  * Solution Summary:
#  *
#  *   basic io
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

line1 = input()

line1 = line1.split(" ")

for i in range(len(line1)):
    line1[i] = int(line1[i])

line1 = sorted(line1)

A = line1[0]
B = line1[1]
C = line1[2]

line2 = input()
_A = line2.index("A")
_B = line2.index("B")
_C = line2.index("C")

out = ["", "", ""]
out[_A] = A
out[_B] = B
out[_C] = C

for i in range(len(out)):
    out[i] = str(out[i])

print(" ".join(out))




