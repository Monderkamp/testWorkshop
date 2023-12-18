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

    def test_cross_product(self):
        a = Vector3D(1., 0., 0.)
        b = Vector3D(0., 1., 0.)
        self.assertEqual(a.cross(b), Vector3D(0., 0., 1.))

        c = Vector3D(1., 0., 0.)
        d = Vector3D(1., 0., 0.)
        self.assertEqual(c.cross(d), Vector3D(0., 0., 0.))

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


    def test_line_segment_overlap(self):
        # Test case 1: Parallel segments should not intersect
        LineSegment1 = LineSegment(Vector3D(0., 0., 0.), 0.0, 10.)
        LineSegment2 = LineSegment(Vector3D(1., 0., 0.), 0.0, 10.)
        self.assertFalse(LineSegment1.intersect(LineSegment2))
        self.assertFalse(LineSegment2.intersect(LineSegment1))

        # Test case 2: Identical segments should not intersect
        self.assertFalse(LineSegment2.intersect(LineSegment2))

        # Test case 3: Perpendicular segments should intersect
        LineSegment3 = LineSegment(Vector3D(0., 0., 0.), 0.0, 10.)
        LineSegment4 = LineSegment(Vector3D(0., 0., 0.), 0.5 * math.pi, 10.)
        self.assertTrue(LineSegment3.intersect(LineSegment4))
        self.assertTrue(LineSegment4.intersect(LineSegment3))

        # Test case 4: Segments far apart should not intersect
        LineSegment5 = LineSegment(Vector3D(0., 0., 0.), 0.0, 10.)
        LineSegment6 = LineSegment(Vector3D(1000., 0., 0.), 0.5 * math.pi, 10.)
        self.assertFalse(LineSegment5.intersect(LineSegment6))
        self.assertFalse(LineSegment6.intersect(LineSegment5))

        # Test case 5: Slanted cross should intersect
        LineSegment7 = LineSegment(Vector3D(0., 0., 0.), 0.0, 100.)
        LineSegment8 = LineSegment(Vector3D(1., 0., 0.), 0.6 * math.pi, 100.)
        self.assertTrue(LineSegment7.intersect(LineSegment8))
        self.assertTrue(LineSegment8.intersect(LineSegment7))

        # Test case 6: Almost parallel, large segments should intersect
        LineSegment9 = LineSegment(Vector3D(0., 0., 0.), 0.0, 10000.)
        LineSegment10 = LineSegment(Vector3D(0., 1., 0.), 0.1 * math.pi, 1000.)
        self.assertTrue(LineSegment9.intersect(LineSegment10))
        self.assertTrue(LineSegment10.intersect(LineSegment9))

if __name__ == '__main__':
    unittest.main()
