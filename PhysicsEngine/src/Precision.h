/********************************************************************************/
/* [File]: Precision.h															*/
/* [Description]: The current designe of this physics engine is to work either  */
/* in single and double precision, mathematical functions such as sqrt			*/
/* cannot be used in the source code or headers. This file provvide definitions */
/* for the real numbers type and the equivalent formulae that would work on it. */
/* [Author]: Tommaso Galatolo [tommaso.galatolo@gmail.com]						*/
/* [Date]: 5/6/2015																*/
/* [License]:																	*/
/* This program is free software: you can redistribute it and/or modify			*/
/* it under the terms of the GNU Lesser General Public License as published by	*/
/* the Free Software Foundation, either version 3 of the License, or			*/
/* (at your option) any later version.											*/
/*																				*/
/* This program is distributed in the hope that it will be useful,				*/
/* but WITHOUT ANY WARRANTY; without even the implied warranty of				*/
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the				*/
/* GNU Lesser General Public License for more details.							*/
/*																				*/
/* You should have received a copy of the GNU Lesser General Public License		*/
/* along with this program.  If not, see <http://www.gnu.org/licenses/>.		*/
/********************************************************************************/
#ifndef _PRECISION_H_
#define _PRECISION_H_

#include <float.h>

namespace TSPx
{
#if 0
	/*
	Defines we're in single precision mode,
	for anu code that needs to be conditionally compiled.
	*/
	#define SINGLE_PRECISION
	/*
	Defines a real number precision. TommasoSource Physics Engine
	(if i can pull it off) would provvide both single and double precision
	version. By default single precision is provvided
	*/
	typedef float real;
	/*
	Max value for the real numbers.
	*/
	#define MAX_REAL FLT_MAX
	/*
	Single precision square root operator.
	*/
	#define real_sqrt sqrtf
	/*
	Single precision inverse square root.
	*/
	#define real_inv_sqrt(real v) static_cast<real>(1) / real_sqrt(v)
	/*
	Single precision absolute magnitude operator.
	*/
	#define real_abs fabsf
	/*
	Single precision sine operator.
	*/
	#define real_sin sinf
	/*
	Single precision cosine operator.
	*/
	#define real_cos cosf
	/*
	Single precision exponent operator.
	*/
	#define real_exp expf
	/*
	Single precision power operator.*/
	#define real_pow powf
	/*
	Single precision floating point modulo operator.
	*/
	#define real_fmod fmodf
	/*
	Defines the number of epsilon on which 1 + e == 1. 
	In computing, the precision of a numeric data type and floating-point machine epsilon.
	*/
	#define real_epsilon FLT_EPSILON
	/*
	Constant pi for single precision.
	*/
	#define R_PI 3.14159f
#else
	/*
	Defines we're in double precision mode,
	for anu code that needs to be conditionally compiled.
	*/
#define DOUBLE_PRECISION
	/*
	Defines a real number double precision.
	*/
	typedef double real;
	/*
	Max value for the (double)real numbers.
	*/
	#define MAX_REAL DBL_MAX
	/*
	Double precision square root operator.
	*/
	#define real_sqrt sqrt
	/*
	Single precision inverse square root.
	*/
	#define real_inv_sqrt(v) static_cast<real>(1) / real_sqrt(v)
	/*
	Double precision absolute magnitude operator.
	*/
	#define real_abs fabs
	/*
	Double precision sine operator.
	*/
	#define real_sin sin
	/*
	Double precision cosine operator.
	*/
	#define real_cos cos
	/*
	Double precision exponent operator.
	*/
	#define real_exp exp
	/*
	Double precision power operator.*/
	#define real_pow pow
	/*
	Double precision floating point modulo operator.
	*/
	#define real_fmod fmod
	/*
	Defines the number of epsilon on which 1 + e == 1.
	In computing, the precision of a numeric data type and floating-point machine epsilon.
	*/
	#define real_epsilon DBL_EPSILON
	/*
	Constant pi for single precision.
	*/
	#define R_PI 3.14159265358979
#endif
}

#endif //!_PRECISION_H_