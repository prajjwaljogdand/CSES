n = int(input())

arry =list(map(int, input().strip().split()))

newarr = list()

for i in arry:
    if i not in newarr:
        newarr.append(i)

print(newarr)