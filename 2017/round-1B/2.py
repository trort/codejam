def solver():
    N, R, O, Y, G, B, V = [int(x) for x in raw_input().split()]
    if O == B and O + B == N:
        return ''.join(['OB'] * O)
    elif R == G and R + G == N:
        return ''.join(['RG'] * R)
    elif Y == V and Y + V == N:
        return ''.join(['YV'] * Y)
    # mixed colors
    elif (O > 0 and O > B-1) or (G > 0 and G > R-1) or (V > 0 and V > Y-1):
        return 'IMPOSSIBLE'
    else:
        RR = R - G
        YY = Y - V
        BB = B - O
        NN = RR + YY + BB
    
    #print [RR, YY, BB], NN
    if 2 * max([RR, YY, BB]) > NN:
        return 'IMPOSSIBLE'
    else:
        ans = [None] * NN
        idx = 0
        first_round = True
        spot = NN
        put_order = sorted([(-RR, 'R'), (-YY, 'Y'), (-BB, 'B')])
        unordered = []
        for num, color in put_order:
            unordered.extend([color] * (-num))
        #unordered = unordered + (['R'] * RR) + (['Y'] * YY) + (['B'] * BB)
        for i in unordered:
            if i == 'R' and G > 0:
                temp = []
                for j in xrange(G):
                    temp.append('R')
                    temp.append('G')
                temp.append('R')
                temp = ''.join(temp)
                ans[idx] = temp
                G = 0
            elif i == 'R' and G == 0:
                ans[idx] = 'R'
            elif i == 'Y' and V > 0:
                temp = []
                for j in xrange(V):
                    temp.append('Y')
                    temp.append('V')
                temp.append('Y')
                temp = ''.join(temp)
                ans[idx] = temp
                V = 0
            elif i == 'Y' and V == 0:
                ans[idx] = 'Y'
            elif i == 'B' and O > 0:
                temp = []
                for j in xrange(O):
                    temp.append('B')
                    temp.append('O')
                temp.append('B')
                temp = ''.join(temp)
                ans[idx] = temp
                O = 0
            elif i == 'B' and O == 0:
                ans[idx] = 'B'
            
            spot -= 1
            if first_round:
                idx += 2
            if idx >= NN:
                first_round = False
                idx -= NN
            #print ans
            while spot > 0 and ans[idx] is not None:
                idx = (idx + 1)%NN
        return ''.join(ans)

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    ans = solver()
    print "Case #{}: {}".format(i, ans)