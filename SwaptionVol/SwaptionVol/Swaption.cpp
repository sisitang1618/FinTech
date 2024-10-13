#include "Swaption.h"
#include "Annuity.h"

// ----------------------------------------------------------------------------------------
//
// Implementation for Swaption Price Using Bechelier Model
//
// ----------------------------------------------------------------------------------------

Swaption::Swaption(SwaptionType tp, double st, double exp, double tnr, double sigma, double k, double s0) :
	type{ tp },
	option_start{ st },
	option_exp{ exp },
	tenor{ tnr },
	vol{ sigma },
	strike{ k },
	par_swap_rate{ s0 }
{
}

double Swaption::OptionPrice() {
	double A0 = annuityPV(option_exp, option_exp + tenor);
	if (type == SwaptionType::payer) {

	}
	return 0;
}