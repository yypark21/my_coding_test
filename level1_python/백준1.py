from itertools import*
n,m,*l=map(int,open(0).read().split())
print(max(x for x in map(sum,combinations(l,3))if x<=m))
