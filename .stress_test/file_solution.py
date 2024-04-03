s = input()
ch = input()
res = 0
for i in range(0, len(s)):
    if ch == s[i:i+1]:
        res += 1

print(res)
