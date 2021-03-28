import sys
mod = 1000000007
all_lines = []
for line in sys.stdin:
  all_lines += map(int, line.split())

i = 0
while i < len(all_lines):
  a = all_lines[i]
  b = all_lines[i + 1]
  ans = 0
  v = []
  for u in range(i + 2, i + 2 + a):
    v.append(all_lines[u])
  v = sorted(v, reverse = True)[:b]
  for u in v:
    ans = (ans + u) % mod
  print(ans)
  i = i + a + 2
