def solver():
    N, P = [int(x) for x in raw_input().split()]
    G = [int(x) for x in raw_input().split()]
    if P == 2:
        c0 = 0
        c1 = 0
        for g in G:
            if g % P == 0:
                c0 += 1
            else:
                c1 += 1
        ans = 0
        ans += c0
        while c1 >= 2:
            ans += 1
            c1 -= 2
        if c1 > 0:
            ans += 1
        return ans
    elif P == 3:
        c0 = 0
        c1 = 0
        c2 = 0
        for g in G:
            if g % P == 0:
                c0 += 1
            elif g % P == 1:
                c1 += 1
            else:
                c2 += 1
        #print c0, c1, c2
        ans = 0
        ans += c0
        while c1 > 0 and c2 > 0:
            ans += 1
            c1 -= 1
            c2 -= 1
        while c1 >= 3 or c2 >= 3:
            ans += 1
            c1 -= 3
            c2 -= 3
        if c1 > 0 or c2 > 0:
            ans += 1
        return ans
    elif P == 4:
        c0 = 0
        c1 = 0
        c2 = 0
        c3 = 0
        for g in G:
            if g % P == 0:
                c0 += 1
            elif g % P == 1:
                c1 += 1
            elif g % P == 2:
                c2 += 1
            else:
                c3 += 1
        #print c0, c1, c2, c3
        ans = 0
        ans += c0
        while c1 > 0 and c3 > 0:
            ans += 1
            c1 -= 1
            c3 -= 1
        while c2 >= 2:
            ans += 1
            c2 -= 2
        if c2 >= 1 and (c1 >= 2 or c3 >= 2):
            ans += 1
            c2 -= 1
            c1 -= 2
            c3 -= 2
        while c1 >= 4 or c3 >= 4:
            ans += 1
            c1 -= 4
            c3 -= 4
        if c1 > 0 or c2 > 0 or c3 > 0:
            ans += 1
        return ans

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    ans = solver()
    print "Case #{}: {}".format(i, ans)