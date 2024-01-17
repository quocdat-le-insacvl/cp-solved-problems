from builtins import pow
from types import GeneratorType

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
# grid = [input() for _ in range(n)]
for i in range(n*3):
    s = input()
    if '?' in s:
        for c in "ABC":
            if c not in s:
                print(c) 
                break



