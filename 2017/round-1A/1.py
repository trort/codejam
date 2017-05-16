def solver():
    r, c = [int(x) for x in raw_input().split()]
    grid = []
    for i in xrange(r):
        grid.append(list(raw_input()))
    
    for i in xrange(r):
        paint = '?'
        for j in xrange(c):
            if grid[i][j] != '?':
                paint = grid[i][j]
            else:
                grid[i][j] = paint
                    
    for i in xrange(r):
        paint = '?'
        for j in xrange(c-1, -1, -1):
            if grid[i][j] != '?':
                paint = grid[i][j]
            else:
                grid[i][j] = paint
                    
    for j in xrange(c):
        paint = '?'
        for i in xrange(r):
            if grid[i][j] != '?':
                paint = grid[i][j]
            else:
                grid[i][j] = paint
                
    for j in xrange(c):
        paint = '?'
        for i in xrange(r-1, -1, -1):
            if grid[i][j] != '?':
                paint = grid[i][j]
            else:
                grid[i][j] = paint
    # print
    for i in xrange(r):
        print ''.join(grid[i])

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    print "Case #{}:".format(i)
    solver()