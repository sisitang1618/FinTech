#include "Annuity.h"
#include <cmath>

// ----------------------------------------------------------------------------------------
//
// Free function for Discount Factor
//
// ----------------------------------------------------------------------------------------
// Simply implementation for now
// Will expand this function after yield curve construction is introduced

double discountFactor(double start, double end) {
	double r = 0.02; // assuming constant interest rate 2%
	return exp(-r*(end-start));
}

// ----------------------------------------------------------------------------------------
//
// Free function for Annuity
//
// ----------------------------------------------------------------------------------------
// Simply implementation for now
// Will expand this function after yield curve construction is introduced
// May convert to member function of cashflow object
double annuityPV(double start, double end) {
	double PV = 0;
	double i = end;
	while (i > start) {
		PV += discountFactor(0, i);
		i -= 1;
	}
	return PV;
}