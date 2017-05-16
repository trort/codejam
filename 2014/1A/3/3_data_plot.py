import random,numpy,pylab
total = 0
times = 1000
N = 1000
min = 5555555
hist_data = []
for t in range(times):
    count = 0
    a = [0]*N
    for k in range(N):
        a[k] = k
    for k in range(N):
        p = numpy.random.randint(0,N)
        a[k], a[p] = a[p], a[k]
    for k in range(N):
        if a[k]<k:
            count += 1
    total += count
    hist_data.append(count)
    #print count
##    if count<min:
##        min = count

print float(total)/float(times)
#print min
pylab.hist(hist_data)
pylab.show()
