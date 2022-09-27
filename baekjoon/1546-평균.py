n = int(input())
numbers = list(map(int, input().split(' ')))
M = max(numbers)

new_sum = 0
for number in numbers:
    new_sum += number / M * 100

answer = new_sum / n
print(answer)