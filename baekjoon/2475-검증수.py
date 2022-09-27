numbers = list(map(int, input().split()))

s = sum(map(lambda x: pow(x, 2), numbers))
print(s % 10)