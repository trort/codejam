def solver(n,F):
    circle_size = [0]*(n+1)
    end_with = [0]*(n+1)
    ans = 0
    # circle
    for i in xrange(1, n+1):
        visited = {i}
        p = i
        while F[p-1] not in visited:
            visited.add(F[p-1])
            p = F[p-1]
        end_with[p] = max(len(visited),end_with[p])
        if F[p-1] == i:
            circle_size[i] = len(visited)
            
    # find pair
    for i in xrange(1, n+1):
        if circle_size[i] == 2: #pair
            ans += end_with[i] - 1
            
    for i in xrange(1, n+1):
        if circle_size[i] > ans:
            ans = circle_size[i]
            
    return ans
            

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
  n = int(raw_input())
  F = [int(x) for x in raw_input().split()]
  ans = solver(n,F)
  print "Case #{}: {}".format(i, ans)