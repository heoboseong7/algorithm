n = int(input())
weights = list(map(int, input().split(' ')))
test_count = int(input())
test_weights = list(map(int, input().split(' ')))

checks = [[False for i in range(80001)] for j in range(30)];

checks[0][40000] = True
checks[0][weights[0] + 40000] = True
checks[0][40000 - weights[0]] = True

for i in range(1, n):
    for j in range(80001):
        if checks[i - 1][j]:
            if(j + weights[i] <= 80000):
                checks[i][j + weights[i]] = True
            if(j - weights[i] >= 0):
                checks[i][j - weights[i]] = True
            checks[i][j] = True

for t in test_weights:
    if checks[n - 1][t + 40000]:
        print("Y ", end='')
        continue
    print("N ", end='')
            

            