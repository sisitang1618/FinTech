#include<iostream>
#include "BasicStat.h"

void TestAll() {
    std::cout << "================================================================================" << std::endl;
    std::cout << " Unit Test: BasicStat" << std::endl;
    std::cout << "================================================================================" << std::endl;
    // Test Gaussian distribution
    std::cout << " ---------- Test: Gaussian distribution ----------" << std::endl;
    try {
        double P = MyStat::GaussianPdf(0);
        std::cout << "Discount factor P(" << 0 << ", " << 10 << ") = " << P << std::endl;
    }
    catch (...) {
        std::cout << "!!! Error: discountFactor failed !!!" << std::endl;
    }
    std::cout << std::endl;
}