#include<iostream>
#include "Annuity.h"

void TestAll() {
    std::cout << "================================================================================" << std::endl;
    std::cout << " Unit Test" << std::endl;
    std::cout << "================================================================================" << std::endl;
    // Test discount factor
    std::cout << " ---------- Test: discount factor ----------" << std::endl;
    try {
        double P = discountFactor(0, 10);
        std::cout << "Discount factor P(" << 0 << ", " << 10 << ") = " << P << std::endl;
    }
    catch (...) {
        std::cout << "!!! Error: discountFactor failed !!!" << std::endl;
    }
    std::cout << std::endl;
    
    // Test discount factor
    std::cout << " ---------- Test: annuity ----------" << std::endl;
    try {
        double A = annuityPV(0, 3);
        std::cout << "Annuity A(" << 0 << ", " << 3 << ") = " << A << std::endl;
    }
    catch (...) {
        std::cout << "!!! Error: Annuity failed !!!" << std::endl;
    }
}