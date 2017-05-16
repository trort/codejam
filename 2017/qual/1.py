def solver(state, k):
    if k > len(state) and '-' in state:
        return 'IMPOSSIBLE'
    count = 0
    for i in xrange(len(state) - k + 1):
        if state[i] == '-':
            for j in xrange(k):
                if state[i + j] == '-':
                    state[i + j] = '+'
                else:
                    state[i + j] = '-'
            count += 1
    for i in xrange(len(state) - k + 1, len(state)):
        if state[i] == '-':
            return 'IMPOSSIBLE'
    return count

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
  state, k = raw_input().split(" ")
  ans = solver(list(state), int(k))
  print "Case #{}: {}".format(i, ans)