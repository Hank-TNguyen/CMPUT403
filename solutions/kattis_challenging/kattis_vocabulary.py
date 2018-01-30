import string

al = string.ascii_lowercase


def pow_mod(a, b, c):
    result = 1
    while b > 0:
        if (b % 2 == 1):
            result = (result * a) % c

        b = b >> 1
        a = (a * a) % c

    return result

T = int(input())

while T:
    T -= 1
    word_1 = input()
    word_2 = input()
    word_3 = input()


print( pow_mod(5, 3, 3) )