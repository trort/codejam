def solver():
    N, Q = [int(x) for x in raw_input().split()]
    E = [None] * N
    S = [None] * N
    for i in xrange(N):
        E[i], S[i] = [int(x) for x in raw_input().split()]
    D = [None] * N
    for i in xrange(N):
        D[i] = [int(x) for x in raw_input().split()]
    
    INF = 999999999999
    shortest_dist = [([INF] * N) for x in xrange(N)]
    for i in xrange(N):
        shortest_dist[i][i] = 0
    for i in xrange(N):
        for j in xrange(N):
            if D[i][j] != -1:
                shortest_dist[i][j] = D[i][j]
    for k in xrange(N):
        for i in xrange(N):
            for j in xrange(N):
                if shortest_dist[i][j] > shortest_dist[i][k] + shortest_dist[k][j]:
                    shortest_dist[i][j] = shortest_dist[i][k] + shortest_dist[k][j]
                    
    shortest_time = [([float(INF)] * N) for x in xrange(N)]
    for i in xrange(N):
        shortest_time[i][i] = 0
    for i in xrange(N):
        for j in xrange(N):
            if shortest_dist[i][j] <= E[i]:
                shortest_time[i][j] = float(shortest_dist[i][j]) / float(S[i])
    for k in xrange(N):
        for i in xrange(N):
            for j in xrange(N):
                if shortest_time[i][j] > shortest_time[i][k] + shortest_time[k][j]:
                    shortest_time[i][j] = shortest_time[i][k] + shortest_time[k][j]
    
    ans = []
    for i in xrange(Q):
        U, V = [int(x) for x in raw_input().split()]
        ans.append("{}".format(shortest_time[U-1][V-1]))
    return ' '.join(ans)

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    ans = solver()
    print "Case #{}: {}".format(i, ans)