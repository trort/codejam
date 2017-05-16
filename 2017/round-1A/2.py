def solver():
    n, p  = [int(x) for x in raw_input().split()]
    R = [int(x) for x in raw_input().split()]
    Q = []
    for i in xrange(n):
        Q.append(sorted([int(x) for x in raw_input().split()]))
    
    clearq = []
    for i in xrange(n):
        cleaned_line = []
        for num in Q[i]:
            start = (10 * num) // (11 * R[i])
            if (10 * num) % (11 * R[i]) != 0:
                start += 1
            end = (10 * num) // (9 * R[i])
            cleaned_line.append((start, end))
        clearq.append(cleaned_line)
    #print clearq
    
    count = 0
    idx = [0] * n
    while True:
        share_range = None
        min_row = None
        min_end = None
        for i in xrange(n):
            if idx[i] >= len(clearq[i]):
                return count
            cur_range = clearq[i][idx[i]]
            if share_range == None:
                share_range = cur_range
            else:
                new_start = max(share_range[0], cur_range[0])
                new_end = min(share_range[1], cur_range[1])
                share_range = (new_start, new_end)
            if min_row == None:
                min_row = i
                min_end = cur_range[1]
            else:
                if cur_range[1] < min_end:
                    min_row = i
                    min_end = cur_range[1]
                    
        if share_range[1] >= share_range[0]:
            count += 1
            for i in xrange(n):
                idx[i] += 1
        else:
            idx[min_row] += 1
            
    print 'ERROR'

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
  ans = solver()
  print "Case #{}: {}".format(i, ans)