def isInt(a):
    return int(a) == a

def find_a(m, n):
    if (num & (num - 1)) == 0:
        # 2^i is impossible since (d+1)(2a + d) = 2m
        return -1
    return (2 * m + n - n * n) / 2 / n

T = int(input())
while T:
    T -= 1
    num = int(input())
    dist = 0
    i = 1
    a = -1
    # print(num)
    while i < num:
        i += 1
        a = find_a(num, i)
        if (isInt(a)):
            dist = i
            a = int(a)
            break
        elif a < 0:
            break

    if a < 0:
        print ("IMPOSSIBLE")
    else:

        l = [str(a + j) for j in range(dist)]
        print(str(num) + " = " + " + ".join(l))