T = int(input())

# count = 1
while T:
    T -= 1
    # print(">>>>> " + str(count))
    # count += 1
    line_NM = input()
    # print(line_NM)
    line_NM = line_NM.split(" ")

    N = int(line_NM[0])
    M = int(line_NM[1])

    network = []
    max_len = 1

    for i in range(M):
        line_friends = input()
        line_friends = line_friends.split(" ")

        f1 = int(line_friends[0])
        f2 = int(line_friends[1])

        merge = []
        network.append({f1, f2})
        for i in range(len(network) - 1):
            if not (network[i].isdisjoint({f1, f2})):
                merge.append(i)

        if len(merge) == 0:
            max_len = max(2, max_len)
        elif len(merge) == 1:
            pair = network.pop(-1)
            m = merge.pop()
            network[m] = network[m].union(pair)
            max_len = max(len(network[m]), max_len)
        else:
            m_set = set()
            pair = network.pop(-1)
            m1 = merge.pop()
            m2 = merge.pop()

            m_set = m_set.union(pair)
            m_set = m_set.union(network[m1])
            m_set = m_set.union(network[m2])

            network.append(m_set)
            network.pop(m1)
            network.pop(m2)

            max_len = max(len(m_set), max_len)

    print(max_len)
