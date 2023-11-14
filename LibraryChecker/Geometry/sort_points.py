from builtins import pow
import math
from types import GeneratorType

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

EPS = 1E-9

class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    def __mul__(self, other):
        if isinstance(other, Vector):
            return self.x * other.x + self.y * other.y  # Dot product
        else:
            return Vector(self.x * other, self.y * other)  # Scalar multiplication

    def __truediv__(self, factor):
        return Vector(self.x / factor, self.y / factor)

    def __neg__(self):
        return Vector(-self.x, -self.y)

    def cross(self, other):
        return self.x * other.y - self.y * other.x

    def length(self):
        return math.sqrt(self.x ** 2 + self.y ** 2)

    def normalized(self):
        length = self.length()
        if length == 0:
            return Vector()
        return self / length

    def angle(self):
        return math.atan2(self.y, self.x)

    def rotate(self, angle):
        cos_theta, sin_theta = math.cos(angle), math.sin(angle)
        return Vector(cos_theta * self.x - sin_theta * self.y, sin_theta * self.x + cos_theta * self.y)

    def perp(self):
        return Vector(-self.y, self.x)

    def distance_to(self, other):
        return (self - other).length()

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __ne__(self, other):
        return not self.__eq__(other)

    def __lt__(self, other):
        return (self.x < other.x - EPS) or (abs(self.x - other.x) < EPS and self.y < other.y - EPS)

    def __repr__(self):
        return f"{self.x} {self.y}"

class Line:
    def __init__(self, p1, p2):
        self.a = p1.y - p2.y
        self.b = p2.x - p1.x
        self.c = -self.a * p1.x - self.b * p1.y
        self.norm()

    def norm(self):
        z = math.sqrt(self.a ** 2 + self.b ** 2)
        if abs(z) > EPS:
            self.a /= z
            self.b /= z
            self.c /= z

    def dist(self, point):
        return self.a * point.x + self.b * point.y + self.c

def det(a, b, c, d):
    return a * d - b * c

def intersect_1d(a, b, c, d):
    return max(a, c) <= min(b, d) + EPS

def intersect(p1, p2, p3, p4):
    if not (intersect_1d(p1.x, p2.x, p3.x, p4.x) and intersect_1d(p1.y, p2.y, p3.y, p4.y)):
        return False, None, None
    line1 = Line(p1, p2)
    line2 = Line(p3, p4)
    zn = det(line1.a, line1.b, line2.a, line2.b)
    if abs(zn) < EPS:
        if abs(line1.dist(p3)) > EPS or abs(line2.dist(p1)) > EPS:
            return False, None, None
        # Logic for overlapping lines
        # ...
        return True, Vector(max(p1.x, p3.x), max(p1.y, p3.y)), Vector(min(p2.x, p4.x), min(p2.y, p4.y))
    else:
        x = -det(line1.c, line1.b, line2.c, line2.b) / zn
        y = -det(line1.a, line1.c, line2.a, line2.c) / zn
        return True, Vector(x, y), Vector(x, y)


rf = lambda: input().split()
rs = lambda: list(map(int, rf()))

n = int(input())
vec = [Vector(*rs()) for _ in range(n)]
vec = [(v.angle(), v) for v in vec]
vec.sort()

vec = [v[1] for v in vec]
for v in vec:
    print(v)


