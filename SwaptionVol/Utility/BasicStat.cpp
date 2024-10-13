//#define _USE_MATH_DEFINES
//#include <math.h>
#include <iostream>

#include "BasicStat.h"

namespace MyStat {

double GaussianPdf(double x, double mean, double sd) {

	return 1/sqrt(2* PI) * exp(-pow((x - mean)/sd, 2)/2);
}

double GaussianCdf(double x, double mean, double sd) {
	return 0;
}

} // end of namespace MyStat