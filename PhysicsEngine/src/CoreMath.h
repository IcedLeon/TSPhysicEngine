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
	real m_rSleepEpsilon;
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
	/*
	Holds a vector in 3 dimensions. Four data members are allocated
	to ensure alignment in an union.
	*/
	class Vec3
	{
	public:
		union
		{
			struct { real _x, _y, _z, _pad; };//Pad is there to ensure the 4 word alignement.
		};


	public:
		/*Implicit basic constructors*/

		Vec3();

		Vec3(const Vec3& a_Other);

		Vec3(const real& a_rValue);

		Vec3(const real& a_rX, const real& a_rY, const real& a_rZ);

		/*Conversion scalar constructors*/

		template<typename A, typename B, typename C>
		Vec3(const A& a_X, const B& a_Y, const C& a_Z);

		template<typename V>
		Vec3(const V& a_Value);

		/*
		glm version.
		*/
		Vec3(const vec3& a_glOther);

		~Vec3();		
		
		const size_t Size() const;

		/*Component accesses*/

		real& operator[](size_t a_idx);
		const real& operator[](size_t a_idx) const;

		/*Arithmetic operators*/

		Vec3& operator+(const Vec3& a_vVector) const;
		Vec3& operator-(const Vec3& a_vVector) const;
		Vec3& operator*(const Vec3& a_vVector) const;
		Vec3& operator/(const Vec3& a_vVector) const;

		/*Unary arithmetic operators*/

		Vec3& operator=(const Vec3& a_vVector);
		Vec3& operator+=(real a_Value);
		Vec3& operator+=(const Vec3& a_vVector);
		Vec3& operator+=(const vec3& a_glmVec);
		Vec3& operator-=(real a_Value);
		Vec3& operator-=(const Vec3& a_vVector);
		Vec3& operator-=(const vec3& a_glmVec);
		Vec3& operator*=(real a_Value);
		Vec3& operator*=(const Vec3& a_vVector);
		Vec3& operator*=(const vec3& a_glmVec);
		Vec3& operator/=(real a_Value);
		Vec3& operator/=(const Vec3& a_vVector);
		Vec3& operator/=(const vec3& a_glmVec);

		/*Boolean operators*/
		bool operator==(const Vec3& a_vVector);
		bool operator!=(const Vec3& a_vVector);
		bool operator<(const Vec3& a_vVector);
		bool operator>(const Vec3& a_vVector);
		bool operator<=(const Vec3& a_vVector);
		bool operator>=(const Vec3& a_vVector);

		/*Increment and decrement operators*/

		Vec3& operator++();
		Vec3& operator--();
		Vec3 operator++(int a_iVal);
		Vec3 operator--(int a_iVal);

		/*
		Set the current vector to NULL
		*/
		void Zero();
		/*
		Invert all the components value to be the opposite sign.
		*/
		void Invert();
		/*
		Return the magnitude of this vector.
		*/
		real Magnitude() const;
		/*
		Return the squared magnitude of this vector.
		*/
		real SqrMagnitude() const;
		/*
		Dot product.
		*/
		real Dot(const Vec3& a_vVector);
		/*
		Cross product.
		*/
		Vec3 Cross(const Vec3& a_vVector);
		/*
		Limitis the size of the vector components to a given maximum ammount.
		*/
		real Trim(real a_vTrimmer);
		/*
		Scale this vector by a x ammount.
		*/
		Vec3 ScaleVector(const real a_rScale);
		/*
		Add this vector by a given vector, and scaled by a given ammount.
		*/
		void ScaleByVector(const Vec3& a_vVector, const real a_rScale);
	};

	Vec3 operator+(const Vec3& a_vVector, const real& a_rValue);
	Vec3 operator+(const real& a_rValue, const Vec3& a_vVector);
	Vec3 operator+(const Vec3& a_vVector, const vec3& a_glmVec);
	Vec3 operator+(const vec3& a_glmVec, const Vec3& a_vVector);

	Vec3 operator-(const Vec3& a_vVector, const real& a_rValue);
	Vec3 operator-(const real& a_rValue, const Vec3& a_vVector);
	Vec3 operator-(const Vec3& a_vVector, const vec3& a_glmVec);
	Vec3 operator-(const vec3& a_glmVec, const Vec3& a_vVector);

	Vec3 operator*(const Vec3& a_vVector, const real& a_rValue);
	Vec3 operator*(const real& a_rValue, const Vec3& a_vVector);
	Vec3 operator*(const Vec3& a_vVector, const vec3& a_glmVec);
	Vec3 operator*(const vec3& a_glmVec, const Vec3& a_vVector);

	Vec3 operator/(const Vec3& a_vVector, const real& a_rValue);
	Vec3 operator/(const real& a_rValue, const Vec3& a_vVector);
	Vec3 operator/(const Vec3& a_vVector, const vec3& a_glmVec);
	Vec3 operator/(const vec3& a_glmVec, const Vec3& a_vVector);
}

#endif //!_COREMATH_H_