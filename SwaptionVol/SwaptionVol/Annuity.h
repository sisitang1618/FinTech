#pragma once

#include <iostream>

enum class freqType {
	quarter,
	semiAnnual,
	annual
};

std::ostream& operator<<(std::ostream& out, const freqType freq);

// ----------------------------------------------------------------------------------------
//
// Free function for Discount Factor
//
// ----------------------------------------------------------------------------------------
double discountFactor(double start, double end);

// ----------------------------------------------------------------------------------------
//
// Free function for Annuity
//
// ----------------------------------------------------------------------------------------
/* Strictly speaking, when the pay freq is not annual, it is not called annuity.
*  Here the concept is expanded to the PV of 1 dollar at each multiply of freq.
*/
double annuityPV(double start, double end, freqType freq);
