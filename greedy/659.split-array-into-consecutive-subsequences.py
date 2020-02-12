import collections
import heapq

def isPossible(nums):
    d = collections.defaultdict(list)
    for e in nums:
        if d[e-1]: # there is sequence ending with e-1
            l = heapq.heappop(d[e-1]) # the shortest sequence
            heapq.heappush(d[e], l+1)
        else:
            heapq.heappush(d[e], 1) # create a new sequence
    for h in d.values():
        print(h)
        for hl in h:
            if hl < 3:
                return False
    return True

r = isPossible([1,2,3,3,4,5])
print(r)
