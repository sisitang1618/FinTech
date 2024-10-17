#include<iostream>
#include<locale>
#include<iomanip>
#include "Annuity.h"
#include "Swaption.h"

//----------------------------------------------------------------------------------------
//
// Local Helper Functions
// 
//----------------------------------------------------------------------------------------

namespace { // Anonymous namepsace
    // 1. discountFactor
    void test_discountFactor_once(double t1, double t2) {
        double P = discountFactor(t1, t2);
        std::cout << "Discount factor P(" << t1 << ", " << t2 << ") = " << P << std::endl;
    }

    void test_discountFactor() {
        test_discountFactor_once(0, 1);
        test_discountFactor_once(0, 10);
    }

    // 2. annuityPV
    void test_annuityPV_once(double t1, double t2, freqType freq) {

        double A = annuityPV(t1, t2, freq);
        std::cout << "Freq = " << freq << ". Annuity A(" << t1 << ", " << t2 << ") = " << A << std::endl;
    }

    void test_annuityPV() {
        test_annuityPV_once(0, 3, freqType::annual);
        test_annuityPV_once(0, 3, freqType::semiAnnual);
        test_annuityPV_once(0, 3, freqType::quarter);
        test_annuityPV_once(0, 3.9, freqType::annual);
        test_annuityPV_once(0.8, 4, freqType::annual);
    }

    // 3. Swaption
    void test_Swaption_once(SwaptionType tp, double N, double start, double exp, double tnr, double sigma, double k, double s0) {
        
        Swaption Swptn(tp, N, start, exp, tnr, sigma, k, s0);
        
        Swptn.displayDetail();

        std::locale mylocale("");
        std::cout.imbue(mylocale);

        std::cout << std::fixed << std::setprecision(0);
        std::cout << "Swaption PV = " << Swptn.OptionPrice() << std::endl;
        std::cout << "Delta = " << Swptn.Delta() << std::endl;
        std::cout << "Delta (FD_1bps) = " << Swptn.Delta(GreekType::finite_difference_1bps) << std::endl;
        std::cout << "Delta (FD_1pct) = " << Swptn.Delta(GreekType::finite_difference_1pct) << std::endl;
        std::cout << "Vega = " << Swptn.Vega() << std::endl;
        std::cout << "Vega (FD_1bps) = " << Swptn.Vega(GreekType::finite_difference_1bps) << std::endl;
        std::cout << "Vega (FD_1pct) = " << Swptn.Vega(GreekType::finite_difference_1pct) << std::endl;
        std::cout << "Gamma = " << Swptn.Gamma() << std::endl;
        std::cout << "Gamma (FD_1bps) = " << Swptn.Gamma(GreekType::finite_difference_1bps) << std::endl;
        std::cout << "Gamma (FD_1pct) = " << Swptn.Gamma(GreekType::finite_difference_1pct) << std::endl;
        std::cout << std::endl;

    }

    void test_Swaption() {
        test_Swaption_once(SwaptionType::payer, 100000000, 0, 2, 5, 0.0107, 2.1993/100, 2.1993/100);
        //test_Swaption_once(SwaptionType::receiver, 100000000, 0, 2, 5, 0.0107, 2.1993 / 100, 2.1993 / 100);
        test_Swaption_once(SwaptionType::payer, 100000000, 0, 1, 1, 0.0142, 2.6576666/100, 2.6576666/100);
        test_Swaption_once(SwaptionType::payer, 100000000, 0, 1, 1, 0.0135, 1.6576666/100, 2.6576666/100);
    }

} // end Anonymous namespace


//----------------------------------------------------------------------------------------
//
// Execute Tests
// 
//----------------------------------------------------------------------------------------

void SwaptionVol_TestAll() {

    std::cout << "================================================================================" << std::endl;
    std::cout << " Swaption Vol Unit Test" << std::endl;
    std::cout << "================================================================================" << std::endl;
    // Test discount factor
    std::cout << " ---------- Test: discountFactor ----------" << std::endl;
    try {
        test_discountFactor();
    }
    catch (...) {
        std::cout << "!!! Error: discountFactor failed !!!" << std::endl;
    }
    std::cout << std::endl;
    
    // Test annuityPV
    std::cout << " ---------- Test: annuityPV ----------" << std::endl;
    try {
        test_annuityPV();
    }
    catch (...) {
        std::cout << "!!! Error: annuityPV failed !!!" << std::endl;
    }
    std::cout << std::endl;

    // Test Swaption
    std::cout << " ---------- Test: Swaption ----------" << std::endl;
    try {
        test_Swaption();
    }
    catch (...) {
        std::cout << "!!! Error: Swaption failed !!!" << std::endl;
    }
    std::cout << std::endl;
}
