#include "Swaption.h"

// ----------------------------------------------------------------------------------------
//
// Implementation for Swaption Price Using Bechelier Model
//
// ----------------------------------------------------------------------------------------

Swaption::Swaption(SwaptionType tp, double st, double exp, double tnr, double sigma, double k) :
	type{ tp },
	option_start{ st },
	option_exp{ exp },
	tenor{ tnr },
	vol{ sigma },
	strike{ k }
{
}