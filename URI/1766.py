class Rena:
  def __init__(self, s, p, i, a):
    self.s = s
    self.p = p 
    self.i = i 
    self.a = a

  def __lt__(self, other):
    if self.p != other.p:
      return self.p > other.p
    if self.i != other.i:
      return self.i < other.i
    if self.a != other.a:
      return self.a < other.a
    
    return self.s < other.s

t = int(input())
test = 1
for _ in range(t):
  n, m = map(int, input().split())
  renas = []
  for _ in range(n):
    line = input().split()
    renas.append(Rena(line[0], int(line[1]), int(line[2]), float(line[3])))
  renas = sorted(renas)[:m]
  print('CENARIO ' + '{' + '{}'.format(test) + '}')
  for id, rena in enumerate(renas):
    print('{} - {}'.format(id + 1, rena.s))
  test += 1
