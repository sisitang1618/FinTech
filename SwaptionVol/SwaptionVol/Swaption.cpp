#include "Swaption.h"
#include "Annuity.h"
#include "Utility\BasicStat.h"
#include <cmath>
#include <algorithm>
#include <string>
#include<locale>
#include<iomanip>

using namespace std;

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
		_delta = _N * A0 * MyStat::GaussianCdf(d1) / 10000; // DV01
		_vega = _N * A0 * MyStat::GaussianPdf(d1) * sqrt(T) /10000; // per 1bps vol move
		_gamma = _N * A0 * MyStat::GaussianPdf(d1) / vol / sqrt(T) / 100000000; // per 1bps swap rate move
	}
	if (type == SwaptionType::receiver) {
		_PV = _N * A0 * (_vol * sqrt(T) * MyStat::GaussianPdf(-d1) + (_K - _S0) * MyStat::GaussianCdf(-d1));
	}
}

double Swaption::OptionPrice() {

	return _PV;
}

double Swaption::Delta(GreekType greekType) {

	if (greekType == GreekType::finite_difference_1bps) {
		Swaption deal1(_type, _N, _optStart, _optExp, _tenor, _vol, _K, _S0 + 0.0001);
		Swaption deal2(_type, _N, _optStart, _optExp, _tenor, _vol, _K, _S0 - 0.0001);
		return (deal1.OptionPrice() - deal2.OptionPrice())/2;
	}
	else if (greekType == GreekType::finite_difference_1pct) {
		Swaption deal1(_type, _N, _optStart, _optExp, _tenor, _vol, _K, _S0 + 0.01);
		Swaption deal2(_type, _N, _optStart, _optExp, _tenor, _vol, _K, _S0 - 0.01);
		return (deal1.OptionPrice() - deal2.OptionPrice()) / 200;
	}
	return _delta;
	
}

double Swaption::Vega() {
	
	return _vega;
}

double Swaption::Gamma() {

	return _gamma;
}

void Swaption::displayDetail() {

	cout << "* ---- Trade detail ----------" << endl;
	std::locale mylocale("");
	std::cout.imbue(mylocale);

	std::string s;
	if (_type == SwaptionType::payer) s = "Payer";
	if (_type == SwaptionType::receiver) s = "Receiver";
	if (_type == SwaptionType::straddle) s = "Straddle";
	std::cout << "Swaption type: \t" << s << std::endl;

	std::cout << std::fixed << std::setprecision(0);
	cout << "Notional: \t" << _N << endl;
	
	std::cout << std::fixed << std::setprecision(2);
	cout << "Option start: \t" << _optStart << " (yr)" << endl;
	cout << "Option expire: \t" << _optExp << " (yr)" << endl;
	cout << "Swap tenor: \t" << _tenor << " (yr)" << endl;

	std::cout << std::fixed << std::setprecision(6);
	cout << "Strike: \t" << _K*100 << " %" << endl;

	cout << "* ---- Market data -----------" << endl;
	std::cout << std::fixed << std::setprecision(2);
	cout << "Volatility: \t" << _vol * 10000 << " bps" << endl;
	std::cout << std::fixed << std::setprecision(6);
	cout << "Par swap rate: \t" << _S0*100 << " %" << endl;
	cout << "* ---------------------------- " << endl;
}