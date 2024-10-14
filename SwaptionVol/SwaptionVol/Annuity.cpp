#include "Annuity.h"
#include <cmath>

std::ostream& operator<<(std::ostream& out, const freqType freq) {
	return out << [freq](){
#define PROCESS_VAL(p) case(p): return #p;
		switch (freq) {
			PROCESS_VAL(freqType::annual);
			PROCESS_VAL(freqType::semiAnnual);
			PROCESS_VAL(freqType::quarter);
		}
#undef PROCESS_VAL
		}();
}

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
double annuityPV(double start, double end, freqType freq) {

	double stride = 0;
	switch (freq) {
	case freqType::annual:
		stride = 1;
		break;
	case freqType::semiAnnual:
		stride = 0.5;
		break;
	case freqType::quarter:
		stride = 0.25;
		break;
	}
	double PV = 0;
	double t = end;
	// assuming paying $1 every time
	// roll convention = backward
	while (t >= start + stride) {
		PV += discountFactor(0, t);
		t -= stride;
	}
	return PV;
}
