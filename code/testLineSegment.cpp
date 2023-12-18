#include<iostream>
#include "LineSegment.hpp"
#include "unitTest.hpp"


void test_equals(){
    std::cout << "test_equals" << std::endl;
    bool result = true;

    Vector3D a(1.,0.,0.);
    Vector3D b(1.,0.,0.);
    
    result = (result && unitTest::assertTrue(a==b,"should be equal."));

    Vector3D c(0.,0.,0.);
    Vector3D d(0.,0.,0.);
    
    result = (result && unitTest::assertTrue(c==d,"should be equal."));

    
    if (!result) {
        std::cerr << "test_CrossProduct FAILED" << std::endl;
    }

    std::cout << std::endl;
}

void test_CrossProduct(){
    std::cout << "test_CrossProduct" << std::endl;
    bool result = true;

    Vector3D a(1.,0.,0.);
    Vector3D b(0.,1.,0.);
    
    result = (result && unitTest::assertTrue(a.cross(b)==Vector3D(0.,0.,1.0),"should be equal."));

    Vector3D c(1.,0.,0.);
    Vector3D d(1.,0.,0.);
    
    result = (result && unitTest::assertTrue(c.cross(d)==Vector3D(0.,0.,0.0),"should be equal."));

    
    if (!result) {
        std::cerr << "test_CrossProduct FAILED" << std::endl;
    }

    std::cout << std::endl;
}


void test_LineSegmentpositionDistance(){
    std::cout << "test_LineSegmentpositionDistance" << std::endl;
    bool result = true;

    Vector3D R1(0.,0.,0.);
    Vector3D R2(1.,0.,0.);

    LineSegment LineSegment1(R1,0.0,10.);
    LineSegment LineSegment2(R2,0.0,10.);


    result = (result && unitTest::assertMaxDiffence(LineSegment1.positionDistance(LineSegment2),1.0,1E-12,"positionDistance should be 1."));
    
    LineSegment2.change_position({1.,1.,0.});
    result = result && unitTest::assertMaxDiffence(LineSegment1.positionDistance(LineSegment2),sqrt(2.),1E-12,"positionDistance should be sqrt(2).");

    LineSegment2.change_position({1.,1.,1.});
    result = result && unitTest::assertMaxDiffence(LineSegment1.positionDistance(LineSegment2),sqrt(3.),1E-12,"positionDistance should be sqrt(3).");

    LineSegment2.change_position({0.,0.,0.});
    result = result && unitTest::assertMaxDiffence(LineSegment1.positionDistance(LineSegment2),0.,1E-12,"positionDistance should be 0.");

    LineSegment2.change_position({-1.,0.,0.});
    result = result && unitTest::assertMaxDiffence(LineSegment1.positionDistance(LineSegment2),1.,1E-12,"positionDistance should be 1.");

    LineSegment2.change_position({-10.,0.,0.});
    result = result && unitTest::assertMaxDiffence(LineSegment1.positionDistance(LineSegment2),10.,1E-12,"positionDistance should be 10.");

    LineSegment2.change_position({-INFINITY,0.,0.});
    result = result && unitTest::assertEqual(LineSegment1.positionDistance(LineSegment2),INFINITY,"positionDistance should be INFINITY.");

    if (!result) {
        std::cerr << "test_LineSegmentpositionDistance FAILED" << std::endl;
    }

    std::cout << std::endl;
}


void test_LineSegmentOverlap(){
    std::cout << "test_LineSegmentOverlap" << std::endl;
    bool result = true;

    LineSegment LineSegment1(Vector3D(0.,0.,0.),0.0,10.);
    LineSegment LineSegment2(Vector3D(1.,0.,0.),0.0,10.);

    result = (result && unitTest::assertFalse(LineSegment1.overlap(LineSegment2),"parallel shoult not overlap."));
    result = (result && unitTest::assertFalse(LineSegment2.overlap(LineSegment2),"parallel shoult not overlap."));

    LineSegment LineSegment3(Vector3D(0.,0.,0.),0.0,10.);
    LineSegment LineSegment4(Vector3D(0.,0.,0.),0.5*M_PI,10.);

    result = (result && unitTest::assertTrue(LineSegment3.overlap(LineSegment4),"cross shoult overlap."));
    result = (result && unitTest::assertTrue(LineSegment4.overlap(LineSegment3),"cross shoult overlap."));

    LineSegment LineSegment5(Vector3D(0.,0.,0.),0.0,10.);
    LineSegment LineSegment6(Vector3D(1000.,0.,0.),0.5*M_PI,10.);

    result = (result && unitTest::assertFalse(LineSegment5.overlap(LineSegment6),"cross far apart shoult not overlap."));
    result = (result && unitTest::assertFalse(LineSegment6.overlap(LineSegment5),"cross far apart shoult not overlap."));

    LineSegment LineSegment7(Vector3D(0.,0.,0.),0.0,100.);
    LineSegment LineSegment8(Vector3D(1.,0.,0.),0.6*M_PI,100.);

    result = (result && unitTest::assertTrue(LineSegment7.overlap(LineSegment8),"slanted cross shoult overlap."));
    result = (result && unitTest::assertTrue(LineSegment8.overlap(LineSegment7),"slanted cross shoult overlap."));

    LineSegment LineSegment9(Vector3D(0.,0.,0.),0.0,10000.);
    LineSegment LineSegment10(Vector3D(0.,1.,0.),0.1*M_PI,1000.);

    result = (result && unitTest::assertTrue(LineSegment9.overlap(LineSegment10),"almost parallel shoult overlap."));
    result = (result && unitTest::assertTrue(LineSegment10.overlap(LineSegment9),"almost parallel shoult overlap."));

    
    if (!result) {
        std::cerr << "test_LineSegmentOverlap FAILED" << std::endl;
    }

    std::cout << std::endl;
}





int main() {
    std::cout << std::endl;
    std::cout << "//-----------------------------------" << std::endl;
    std::cout << "STARTING SPHEROCYLINDER UNIT TESTS MAIN" << std::endl;
    std::cout << "//-----------------------------------" << std::endl;
    std::cout << std::endl;

    test_equals();
    test_CrossProduct();
    test_LineSegmentpositionDistance();
    test_LineSegmentOverlap();


    return 0;


}