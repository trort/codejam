def solver():
    d, n = [int(x) for x in raw_input().split()]
    max_time = float(0)
    for i in xrange(n):
        k, s = [int(x) for x in raw_input().split()]
        time = float(d - k) / float(s)
        max_time = max(max_time, time)
    return float(d) / max_time

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    ans = solver()
    print "Case #{}: {}".format(i, ans)