def solver(n):
    heights = [0]*2502
    for i in xrange(2*n-1):
        line = raw_input().split()
        for h in line:
            heights[int(h)] += 1
    mis = []
    for i in xrange(len(heights)):
        if heights[i] %2 != 0:
            mis.append(i)
    return ' '.join([str(x) for x in sorted(mis)])

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
  n = int(raw_input())
  ans = solver(n)
  print "Case #{}: {}".format(i, ans)