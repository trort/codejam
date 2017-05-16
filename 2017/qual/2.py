def solver(num):
    l = len(num)
    for i in xrange(l-1, 0, -1):
        if num[i] < num[i-1]:
            for j in xrange(i, l):
                num[j] = '9'
            if num[i-1] != '0':
                num[i-1] = chr(ord(num[i-1]) - 1)
            else:
                j = i-1
                while j >= 0 and num[j] == '0':
                    num[j] = '9'
                    j -= 1
                if j >= 0:
                    num[j] = chr(ord(num[j]) - 1)
    return ''.join(num).lstrip('0')
        

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
  num = raw_input()
  ans = solver(list(num))
  print "Case #{}: {}".format(i, ans)