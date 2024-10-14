#include "Swaption.h"
#include "Annuity.h"
#include "Utility\BasicStat.h"
#include <cmath>
#include <algorithm>

// ----------------------------------------------------------------------------------------
//
// Implementation for Swaption Price Using Bechelier Model
//
// ----------------------------------------------------------------------------------------

Swaption::Swaption(	SwaptionType type, 
					double Notional, 
					double optStart, 
					double optExp, 
					double tenor, 
					double vol, 
					double strike, 
					double parSwpRate) :
	_type{ type },
	_N{ Notional },
	_optStart{ optStart },
	_optExp{ optExp },
	_tenor{ tenor },
	_vol{ vol },
	_K{ strike },
	_S0{ parSwpRate }
{
	double A0 = annuityPV(0, _optExp + _tenor, freqType::annual) - annuityPV(0, _optExp, freqType::annual);
	double T = _optExp - std::max(_optStart, 0.0);
	double d1 = (_S0 - _K) / _vol / sqrt(T);
	if (type == SwaptionType::payer) {
		_PV = _N * A0 * (_vol * sqrt(T) * MyStat::GaussianPdf(d1) + (_S0 - _K) * MyStat::GaussianCdf(d1));
		_delta = _N * A0 * MyStat::GaussianCdf(d1);
		_vega = _N * A0 * MyStat::GaussianPdf(d1) * sqrt(T);
		_gamma = _N * A0 * MyStat::GaussianPdf(d1) / vol / sqrt(T);
	}
}

double Swaption::OptionPrice() {

	return _PV;
}

double Swaption::Delta() {

	return _delta;
}

double Swaption::Vega() {
	
	return _vega;
}

double Swaption::Gamma() {

	return _gamma;
}