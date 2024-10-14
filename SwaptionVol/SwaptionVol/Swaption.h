#pragma once

// ----------------------------------------------------------------------------------------
//
// Object for Swaption Price Using Bechelier Model
//
// ----------------------------------------------------------------------------------------

enum class SwaptionType {
	payer,
	receiver,
	straddle
};

class Swaption {
private:
	// basic swaption specs
	SwaptionType _type;
	double _N;
	double _optStart;
	double _optExp;
	double _tenor;
	double _vol;
	double _K;
	double _S0;
	// to store values
	double _PV;
	double _delta;
	double _vega;
	double _gamma;
	// The values are stored because the authos believes they are used very frequent.
	// Otherwise, they can be calculated on-the-fly.
public:
	Swaption(SwaptionType type, double Notional, double optStart, double optExp, 
		double tenor, double vol, double strike, double parSwpRate);
	~Swaption() = default;
	double OptionPrice();
	double Delta();
	double Vega();
	double Gamma();
};