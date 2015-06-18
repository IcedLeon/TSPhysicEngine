/********************************************************************************/
/* [File]: CoreMath.h														*/
/* [Description]: */
/* */
/* [Author]: Tommaso Galatolo tommaso.galatolo@gmail.com						*/
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
#ifndef _COREMATH_H_
#define _COREMATH_H_
//Libs
#include <math.h>
#include "UsedLibs.h"

namespace TSPx
{
	/*
	The sleep epsilon holds the value for the energy under which a body (all body)
	will be put to sleep (rest). Being a global value, this rest value would effect
	the entire solution. By default it's 0.1, which is fine for most physic simulation
	and when gravity is about 20 units per seconds squared, masses are about one, and
	other forces are around that of gravity. It need tweaking to adapt to the current
	simulation running.
	*/
	extern real m_rSleepEpsilon;
	/*
	Set the current sleep epsilon value: the kinetic energy under a body is put to rest
	Bodies are put to sleep if the appear to have a stable or "irrelevant" kinetic
	energy less that the epsilon. For example in simulation where bodys are moving slow,
	or the body etra light, this value might need to be reduced.
	*/
	void SetSleepEpsilon(real a_rSleepEpsilon);
	/*
	Get the current sleep epsilon value.
	*/
	real GetSleepEpsilon();

	//class CoreMath
	//{
	//private:
	//	
	//public:
	//	const static vec3 m_vGravity;
	//	const static vec3 m_vHighGravity;

	//public:
	//	CoreMath();
	//	~CoreMath();

	//	void AddScaleToVec(const vec3& a_vVector, real a_rScale);

	//	void Magnitude(const vec3& a_vVector);

	//	void TrimVector(real a_rTrim);

	//};
}
#endif //!_COREMATH_H_