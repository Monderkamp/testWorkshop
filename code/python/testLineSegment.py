import unittest
import math
from LineSegment import Vector3D
from LineSegment import LineSegment

class TestVector3D(unittest.TestCase):

    def test_equals(self):
        a = Vector3D(1., 0., 0.)
        b = Vector3D(1., 0., 0.)
        self.assertEqual(a, b)

        c = Vector3D(0., 0., 0.)
        d = Vector3D(0., 0., 0.)
        self.assertEqual(c, d)

class TestLineSegment(unittest.TestCase):

    def test_position_distance(self):
        R1 = Vector3D(0., 0., 0.)
        R2 = Vector3D(1., 0., 0.)
        LineSegment1 = LineSegment(R1, 0.0, 10.)
        LineSegment2 = LineSegment(R2, 0.0, 10.)

        self.assertAlmostEqual(LineSegment1.position_distance(LineSegment2), 1.0, places=12)

        LineSegment2.change_position(Vector3D(1., 1., 0.))
        self.assertAlmostEqual(LineSegment1.position_distance(LineSegment2), math.sqrt(2), places=12)

        LineSegment2.change_position(Vector3D(1., 1., 1.))
        self.assertAlmostEqual(LineSegment1.position_distance(LineSegment2), math.sqrt(3), places=12)

        LineSegment2.change_position(Vector3D(0., 0., 0.))
        self.assertAlmostEqual(LineSegment1.position_distance(LineSegment2), 0., places=12)

        LineSegment2.change_position(Vector3D(-1., 0., 0.))
        self.assertAlmostEqual(LineSegment1.position_distance(LineSegment2), 1., places=12)

        LineSegment2.change_position(Vector3D(-10., 0., 0.))
        self.assertAlmostEqual(LineSegment1.position_distance(LineSegment2), 10., places=12)


if __name__ == '__main__':
    unittest.main()
