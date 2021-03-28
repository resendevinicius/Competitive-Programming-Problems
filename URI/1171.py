n = int(input())
v = [int(input()) for _ in range(n)]
ans = dict()
for u in v:
  if u not in ans:
    ans.update({u: 1})
  else:
    ans[u] = ans[u] + 1
for key, value in sorted(ans.items()):
  print('{} aparece {} vez(es)'.format(key, value))

