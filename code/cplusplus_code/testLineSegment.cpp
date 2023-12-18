#include<iostream>
#include "LineSegment.hpp"
#include "unitTest.hpp"


void test_equals(){
    std::cout << "test_equals" << std::endl;
    bool result = true;

    Vector3D a(1.,0.,0.);
    Vector3D b(1.,0.,0.);
    
    result = (result & unitTest::assertTrue(a==b,"should be equal."));

    Vector3D c(0.,0.,0.);
    Vector3D d(0.,0.,0.);
    
    result = (result & unitTest::assertTrue(c==d,"should be equal."));

    
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


    result = (result & unitTest::assertMaxDiffence(LineSegment1.positionDistance(LineSegment2),1.0,1E-12,"positionDistance should be 1."));
    
    LineSegment2.change_position({1.,1.,0.});
    result = result & unitTest::assertMaxDiffence(LineSegment1.positionDistance(LineSegment2),sqrt(2.),1E-12,"positionDistance should be sqrt(2).");

    LineSegment2.change_position({1.,1.,1.});
    result = result & unitTest::assertMaxDiffence(LineSegment1.positionDistance(LineSegment2),sqrt(3.),1E-12,"positionDistance should be sqrt(3).");

    LineSegment2.change_position({0.,0.,0.});
    result = result & unitTest::assertMaxDiffence(LineSegment1.positionDistance(LineSegment2),0.,1E-12,"positionDistance should be 0.");

    LineSegment2.change_position({-1.,0.,0.});
    result = result & unitTest::assertMaxDiffence(LineSegment1.positionDistance(LineSegment2),1.,1E-12,"positionDistance should be 1.");

    LineSegment2.change_position({-10.,0.,0.});
    result = result & unitTest::assertMaxDiffence(LineSegment1.positionDistance(LineSegment2),10.,1E-12,"positionDistance should be 10.");

    LineSegment2.change_position({-INFINITY,0.,0.});
    result = result & unitTest::assertEqual(LineSegment1.positionDistance(LineSegment2),INFINITY,"positionDistance should be INFINITY.");

    if (!result) {
        std::cerr << "test_LineSegmentpositionDistance FAILED" << std::endl;
    }

    std::cout << std::endl;
}




int main() {
    std::cout << std::endl;
    std::cout << "//-----------------------------------" << std::endl;
    std::cout << "STARTING LINE SEGMENT UNIT TESTS MAIN" << std::endl;
    std::cout << "//-----------------------------------" << std::endl;
    std::cout << std::endl;

    test_equals();
    test_LineSegmentpositionDistance();


    return 0;


}