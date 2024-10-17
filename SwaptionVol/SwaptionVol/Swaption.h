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

enum class GreekType {
	instantaneous,
	finite_difference_1bps,
	finite_difference_1pct
};

class Swaption {
private:
	// basic swaption specs
	SwaptionType _type;
	double _N;			// unit dollar
	double _optStart;	// unit yr
	double _optExp;		// unit yr
	double _tenor;		// unit yr
	double _vol;		// unit 1 (10000bps)
	double _K;			// unit 1 (10000bps)
	double _S0;			// unit 1 (10000bps)
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
	double Delta(GreekType greekType = GreekType::instantaneous);
	double Vega();
	double Gamma();
	void displayDetail();

};