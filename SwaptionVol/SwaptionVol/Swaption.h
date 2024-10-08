#pragma once

// ----------------------------------------------------------------------------------------
//
// Object for Swaption Price Using Bechelier Model
//
// ----------------------------------------------------------------------------------------

enum SwaptionType {
	payer,
	receiver,
	straddle
};

class Swaption {
private:
	SwaptionType type;
	double option_start;
	double option_exp;
	double tenor;
	double vol;
	double strike;
public:
	Swaption(SwaptionType tp, double st, double exp, double tnr, double sigma, double k);
	~Swaption() = default;
	double OptionPrice();
	double Delta();
	double Vega();
	double Gamma();
};