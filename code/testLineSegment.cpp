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

    result = (result && unitTest::assertFalse(LineSegment1.intersect(LineSegment2),"parallel should not intersect."));
    result = (result && unitTest::assertFalse(LineSegment2.intersect(LineSegment2),"parallel should not intersect."));

    LineSegment LineSegment3(Vector3D(0.,0.,0.),0.0,10.);
    LineSegment LineSegment4(Vector3D(0.,0.,0.),0.5*M_PI,10.);

    result = (result && unitTest::assertTrue(LineSegment3.intersect(LineSegment4),"cross should intersect."));
    result = (result && unitTest::assertTrue(LineSegment4.intersect(LineSegment3),"cross should intersect."));

    LineSegment LineSegment5(Vector3D(0.,0.,0.),0.0,10.);
    LineSegment LineSegment6(Vector3D(1000.,0.,0.),0.5*M_PI,10.);

    result = (result && unitTest::assertFalse(LineSegment5.intersect(LineSegment6),"cross far apart should not intersect."));
    result = (result && unitTest::assertFalse(LineSegment6.intersect(LineSegment5),"cross far apart should not intersect."));

    LineSegment LineSegment7(Vector3D(0.,0.,0.),0.0,100.);
    LineSegment LineSegment8(Vector3D(1.,0.,0.),0.6*M_PI,100.);

    result = (result && unitTest::assertTrue(LineSegment7.intersect(LineSegment8),"slanted cross should intersect."));
    result = (result && unitTest::assertTrue(LineSegment8.intersect(LineSegment7),"slanted cross should intersect."));

    LineSegment LineSegment9(Vector3D(0.,0.,0.),0.0,10000.);
    LineSegment LineSegment10(Vector3D(0.,1.,0.),0.1*M_PI,1000.);

    result = (result && unitTest::assertTrue(LineSegment9.intersect(LineSegment10),"almost parallel should intersect."));
    result = (result && unitTest::assertTrue(LineSegment10.intersect(LineSegment9),"almost parallel should intersect."));

    
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