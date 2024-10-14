#include<iostream>
#include "BasicStat.h"

//----------------------------------------------------------------------------------------
//
// Local Helper Functions
// 
//----------------------------------------------------------------------------------------

namespace { // Anonymous namepsace

    void test_GaussianPdf_once(double x, double m, double sig) {
        double P = MyStat::GaussianPdf(x, m, sig);
        std::cout << "Mean = " << m << ", sd = " << sig << ". Gaussian Pdf(" << x << ") = " << P << std::endl;
    }

    void test_GaussianPdf() {
        test_GaussianPdf_once(0, 0, 1);
        test_GaussianPdf_once(1, 0, 1);
        test_GaussianPdf_once(5, 5, 1);
        test_GaussianPdf_once(0, 0, sqrt(5));
        test_GaussianPdf_once(0, 0, sqrt(0.2));
    }

    void test_GaussianCdf_once(double x, double m, double sig) {
        double P = MyStat::GaussianCdf(x, m, sig);
        std::cout << "Mean = " << m << ", sd = " << sig << ". Gaussian Cdf(" << x << ") = " << P << std::endl;
    }

    void test_GaussianCdf() {
        test_GaussianCdf_once(0, 0, 1);
        test_GaussianCdf_once(1, 0, 1);
        test_GaussianCdf_once(5, 5, 1);
        test_GaussianCdf_once(0, 0, sqrt(5));
    }
} // end Anonymous namespace



//----------------------------------------------------------------------------------------
//
// Execute Tests
// 
//----------------------------------------------------------------------------------------

void TestAll() {
    std::cout << "================================================================================" << std::endl;
    std::cout << " Unit Test: BasicStat" << std::endl;
    std::cout << "================================================================================" << std::endl;
    // Test Gaussian distribution
    std::cout << " ---------- Test: Gaussian distribution ----------" << std::endl;
    std::cout << "1. GaussianPfd" << std::endl;
    try {
        test_GaussianPdf();
    }
    catch (...) {
        std::cout << "!!! Error: Mystat::GaussianPdf failed !!!" << std::endl;
    }

    std::cout << "2. GaussianCfd" << std::endl;
    try {
        test_GaussianCdf();
    }
    catch (...) {
        std::cout << "!!! Error: Mystat::GaussianCdf failed !!!" << std::endl;
    }
    std::cout << std::endl;
}

