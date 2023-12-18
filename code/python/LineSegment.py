import math

class Vector3D:
    def __init__(self, x=0.0, y=0.0, z=0.0):
        self.x = x
        self.y = y
        self.z = z

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y and self.z == other.z

    def __sub__(self, other):
        return Vector3D(self.x - other.x, self.y - other.y, self.z - other.z)

    def __add__(self, other):
        return Vector3D(self.x + other.x, self.y + other.y, self.z + other.z)

    def __mul__(self, scalar):
        return Vector3D(self.x * scalar, self.y * scalar, self.z * scalar)

    def norm2(self):
        return self.x ** 2 + self.y ** 2 + self.z ** 2

    def norm(self):
        return math.sqrt(self.norm2())


class LineSegment:
    def __init__(self, R_=Vector3D(), PHI_=0.0, L_=0.0):
        self.u = Vector3D(math.cos(PHI_), math.sin(PHI_), 0.0)
        self.L = L_
        self.change_position(R_)

    def change_position(self, R_):
        self.r = R_
        self.plusEnd = Vector3D(self.r.x + 0.5 * self.L * self.u.x,
                                self.r.y + 0.5 * self.L * self.u.y,
                                self.r.z + 0.5 * self.L * self.u.z)

        self.minusEnd = Vector3D(self.r.x - 0.5 * self.L * self.u.x,
                                 self.r.y - 0.5 * self.L * self.u.y,
                                 self.r.z - 0.5 * self.L * self.u.z)

    def position_distance(self, otherLineSegment_):
        dist = otherLineSegment_.r - self.r
        return dist.norm()
