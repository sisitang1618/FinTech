//#define _USE_MATH_DEFINES
//#include <math.h>

#include <iostream>
#include <cmath>
#include "BasicStat.h"

namespace MyStat {

double GaussianPdf(double x, double mean, double sd) {

	return 1/sqrt(2* PI)/sd * exp(-pow((x - mean)/sd, 2) / 2);
}

double GaussianCdf(double x, double mean, double sd) {

	return 1.0 / 2 * (1 + erf((x-mean) / sqrt(2) / sd));
}

} // end of namespace MyStat