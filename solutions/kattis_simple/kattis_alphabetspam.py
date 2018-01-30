import string

ascii_lowercase = list(string.ascii_lowercase)
ascii_uppercase = list(string.ascii_uppercase)

line = input()
length = len(line)

line = line.replace("_", " ")
spaces = line.count(" ")

lowercases = 0
uppercases = 0

for c in ascii_lowercase:
    lowercases += line.count(c)

for c in ascii_uppercase:
    uppercases += line.count(c)

others = length - spaces - lowercases - uppercases

print(spaces/length)
print(lowercases/length)
print(uppercases/length)
print(others/length)