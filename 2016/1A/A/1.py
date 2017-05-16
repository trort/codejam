def solver(s):
    ans = ''
    for c in s:
        if (ans + c) < (c + ans):
            ans = c + ans
        else: ans = ans + c
    return ans

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
  s = raw_input().strip()
  ans = solver(s)
  print "Case #{}: {}".format(i, ans)