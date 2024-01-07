from builtins import pow
from types import GeneratorType

rf = lambda: input().split()
rs = lambda: map(int, rf())

n = int(input())

l, m, r = [i for i in range(n, 0, -1) ], [], []
# [tail .... head]

# print(l)

def valid(i, arr):
    if len(arr) == 0:
        return True
    if i > arr[-1] :
        return False
    return True

known = {}
ans = ''
min_score = 1e10

def res(l_, m_, r_, track, score):
    global ans, min_score
    s = str(l_) + str(m_) + str(r_)
    if len(l_) == len(m_) == 0 :
        if min_score > score:
            min_score = score
            ans = track
            # print('#' * 10)
            # print(min_score, track)
            # print('#' * 10)
        return
    if s in known and known[s] < score:
        return
    known[s] = score
    l_, m_, r_ = map(lambda x: x.copy(), [l_, m_, r_])
    # print(s)
    if len(l_) != 0:
        k = l_.pop()
        if valid(k, m_):
            res(l_, m_ + [k], r_, track + '1 2\n', score + 1)
        if valid(k, r_):
            res(l_, m_, r_ + [k], track + '1 3\n', score + 1) 
        l_.append(k)

    if len(m_) != 0:
        k = m_.pop()
        if valid(k, r_):
            res(l_, m_, r_ + [k], track + '2 3\n', score + 1)
        if valid(k, l_):
            res(l_ + [k], m_, r_, track + '2 1\n', score + 1)
        m_.append(k)

    if len(r_) != 0:
        k = r_.pop()
        if valid(k, m_): 
            res(l_, m_ + [k], r_, track + '3 2\n', score + 1)
        if valid(k, l_):
            res(l_ + [k], m_, r_, track + '3 1\n', score + 1)
        r_.append(k)


res(l, m , r, '', 0 )

# print(known)

print(min_score)
print(ans)

