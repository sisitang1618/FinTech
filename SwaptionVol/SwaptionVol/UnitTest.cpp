#include<iostream>
#include "Annuity.h"

//----------------------------------------------------------------------------------------
//
// Local Helper Functions
// 
//----------------------------------------------------------------------------------------

namespace { // Anonymous namepsace
    void test_discountFactor_once(double t1, double t2) {
        double P = discountFactor(t1, t2);
        std::cout << "Discount factor P(" << t1 << ", " << t2 << ") = " << P << std::endl;
    }

    void test_discountFactor() {
        test_discountFactor_once(0, 10);
    }

    void test_annuityPV_once(double t1, double t2) {
        double A = annuityPV(t1, t2);
        std::cout << "Annuity A(" << t1 << ", " << t2 << ") = " << A << std::endl;
    }

    void test_annuityPV() {
        test_annuityPV_once(0, 3);
    }

} // end Anonymous namespace


//----------------------------------------------------------------------------------------
//
// Execute Tests
// 
//----------------------------------------------------------------------------------------

void SwaptionVol_TestAll() {
    std::cout << "================================================================================" << std::endl;
    std::cout << " Unit Test" << std::endl;
    std::cout << "================================================================================" << std::endl;
    // Test discount factor
    std::cout << " ---------- Test: discount factor ----------" << std::endl;
    try {
        test_discountFactor();
    }
    catch (...) {
        std::cout << "!!! Error: discountFactor failed !!!" << std::endl;
    }
    std::cout << std::endl;
    
    // Test discount factor
    std::cout << " ---------- Test: annuity ----------" << std::endl;
    try {
        test_annuityPV();
    }
    catch (...) {
        std::cout << "!!! Error: Annuity failed !!!" << std::endl;
    }
}
