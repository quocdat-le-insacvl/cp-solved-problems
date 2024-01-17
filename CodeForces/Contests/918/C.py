from builtins import pow
from types import GeneratorType

from math import *

rf = lambda: input().split()
rs = lambda: map(int, rf())

def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        to = f(*args, **kwargs)
        while True:
            if type(to) is GeneratorType:
                stack.append(to)
                to = next(to)
            else:
                stack.pop()
                if not stack:
                    break
                to = stack[-1].send(to)
        return to

    return wrappedfunc

n = int(input())
for i in range(n):
    _ = rf()
    s = sum(rs())
    if (s ** 0.5).is_integer():
        print("YES")
    else:
        print("NO")
