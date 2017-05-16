def solver(n, k):
    nn = n-1
    kk = k-1
    if k == 1:
        return (nn//2, nn//2) if nn % 2 == 0 else (nn//2 + 1, nn//2)
    
    n_next = (nn//2) if nn % 2 == 0 else (nn//2 + 1)
    if kk % 2 == 1: #left
        return solver(n_next, kk//2 + 1)
    else:
        return solver(nn//2, kk//2)

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
  n, k = [int(x) for x in raw_input().split()]
  ans = solver(n, k)
  print "Case #{}: {} {}".format(i, ans[0], ans[1])