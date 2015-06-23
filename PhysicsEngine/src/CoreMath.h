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

		Vec3 operator-() const;
		Vec3 operator+(const Vec3& a_vVector) const;
		Vec3 operator-(const Vec3& a_vVector) const;
		Vec3 operator*(const Vec3& a_vVector) const;
		Vec3 operator/(const Vec3& a_vVector) const;

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
		/*Vec3 operator++(int a_iVal);
		Vec3 operator--(int a_iVal);*/

		/*
		Set the current vector to NULL
		*/
		void Zero();
		/*
		*/
		void Normalise();
		/*
		Return the magnitude of this vector.
		*/
		real Magnitude() const;
		/*
		Return the squared magnitude of this vector.
		*/
		real SqrMagnitude() const;
		/*
		Return the distance from this vector the given one.
		*/
		real Distance(const Vec3& a_vVector) const;
		/*
		Dot product.
		*/
		real Dot(const Vec3& a_vVector) const;
		/*
		Cross product.
		*/
		Vec3 Cross(const Vec3& a_vVector) const;
		/*
		Limitis the size of the vector components to a given maximum ammount.
		*/
		void Trim(real a_rTrimmer);
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

	/*Other useful geometric functions*/
	
	/*
	Return the refracted vector from the incident vector V and normal of the surface
	that is refracting from, and the indives of refraction eta.
	*/
	Vec3 Refract(const Vec3& a_vIncVector, const Vec3& a_vSurfNorm, real a_rEta);

	class Matrix3
	{
		typedef real mat_type;

	public:
		mat_type _m[9];

		/*Ctors*/

		Matrix3();

		Matrix3(const Matrix3& a_mMat);

		Matrix3(const real& a_rValue);

		Matrix3(const real& a_rX0, const real& a_rY0, const real& a_rZ0,
				const real& a_rX1, const real& a_rY1, const real& a_rZ1,
				const real& a_rX2, const real& a_rY2, const real& a_rZ2);
		
		/*Conversion*/

		template<typename A>
		Matrix3(const A& a_rX0, const A& a_rY0, const A& a_rZ0,
				const A& a_rX1, const A& a_rY1, const A& a_rZ1,
				const A& a_rX2, const A& a_rY2, const A& a_rZ2);

		template<typename A, typename B, typename C>
		Matrix3(const A& a_rX0, const B& a_rY0, const C& a_rZ0,
				const A& a_rX1, const B& a_rY1, const C& a_rZ1,
				const A& a_rX2, const B& a_rY2, const C& a_rZ2);

		template<typename A0, typename B0, typename C0,
				 typename A1, typename B1, typename C1,
				 typename A2, typename B2, typename C2>
		Matrix3(const A0& a_rX0, const B0& a_rY0, const C0& a_rZ0,
				const A1& a_rX1, const B1& a_rY1, const C1& a_rZ1,
				const A2& a_rX2, const B2& a_rY2, const C2& a_rZ2);

		Matrix3(const Vec3& a_vVector0, const Vec3& a_vVector1, const Vec3& a_vVector2);

		Matrix3(const vec3& a_glmVec0, const vec3& a_glmVec1, const vec3& a_glmVec2);

		~Matrix3();

		/*Accesses*/

		size_t Size() const;

		mat_type& operator[](size_t a_idx);

		const mat_type& operator[](size_t a_idx) const;

		/*Unary arithmetic operators*/

		Matrix3& operator=(const Matrix3& a_mMat);

		Matrix3& operator+=(const Matrix3& a_mMat);
		Matrix3& operator+=(real a_Value);

		Matrix3& operator-=(const Matrix3& a_mMat);
		Matrix3& operator-=(real a_Value);

		Matrix3& operator*=(const Matrix3& a_mMat);
		Matrix3& operator*=(real a_Value);

		Matrix3& operator/=(const Matrix3& a_mMat);
		Matrix3& operator/=(real a_Value);

		/*Increment and decrement operators*/
		Matrix3& operator++();
		Matrix3& operator--();

		/*Arithmetic operators*/

		Matrix3 operator+(const Matrix3& a_mMat) const;
		Matrix3 operator-(const Matrix3& a_mMat) const;
		Matrix3 operator*(const Matrix3& a_mMat) const;
		Matrix3 operator/(const Matrix3& a_mMat) const;

		/*Other Matrix3 functions*/

		/*
		This function would initialise the matrix with the 
		inertia tensor value.
		*/
		void SetInertiaTensorCoeff(real a_rIX0, real a_rIY0, real a_rIZ0,
								   real a_rIX1 = static_cast<real>(0), 
								   real a_rIY1 = static_cast<real>(0), 
								   real a_rIZ1 = static_cast<real>(0));

		/*
		Set the value of this matrix as an inertia tensor of a rectangual block aligned with 
		the body's coordinate system, with the given axis being half-sizes and mass.
		*/
		void SetBlockInertiaTensor(const Vec3& a_vHalfSize, real a_rMass);

		/*
		This function propouse is to set this matrix to be a skew symmetric matrix based on the given
		vector. The skew symmetric matrix is the equivalent of the dot product of a vector.
		Therefore, if the value of x, y, are vectors -> a x * y = A_s y, where A_s is the
		skew symmetric form of a.
		*/
		void SetSkewSymmetric(const Vec3& a_vVector);
		/*
		Return a vector rappresenting one of the row of this matrix
		*/
		Vec3 GetRowInVec3(size_t a_idx) const;
		/*
		Invert the current matrix.
		*/
		void Invert();
		/*
		Set this matrix to be transposed to the given one.
		*/
		void SetTranspose(const Matrix3& a_mMat);
		/*
		Returns a new transposed matrix containing the transposed of this matrix.
		*/
		Matrix3 Transpose() const;
		/*
		*/
		real GetDeterminant() const;
	};

	Matrix3 operator+(const Matrix3& a_vVector, const real& a_rValue);
	Matrix3 operator+(const real& a_rValue, const Matrix3& a_vVector);

	Matrix3 operator-(const Matrix3& a_vVector, const real& a_rValue);
	Matrix3 operator-(const real& a_rValue, const Matrix3& a_vVector);

	Matrix3 operator*(const Matrix3& a_vVector, const real& a_rValue);
	Matrix3 operator*(const real& a_rValue, const Matrix3& a_vVector);

	Vec3 operator*(const Matrix3& a_vVector, const Vec3& a_glmVec);
	Vec3 operator*(const Vec3& a_vVector, const Matrix3& a_glmVec);

	vec3 operator*(const Matrix3& a_glmVec, const vec3& a_vVector);
	vec3 operator*(const vec3& a_glmVec, const Matrix3& a_vVector);

	Matrix3 operator/(const Matrix3& a_vVector, const real& a_rValue);
	Matrix3 operator/(const real& a_rValue, const Matrix3& a_vVector);

	Vec3 operator/(const Matrix3& a_vVector, const Vec3& a_glmVec);
	Vec3 operator/(const Vec3& a_vVector, const Matrix3& a_glmVec);

	vec3 operator/(const Matrix3& a_glmVec, const vec3& a_vVector);
	vec3 operator/(const vec3& a_glmVec, const Matrix3& a_vVector);

	/*
	Returns a new matrix set to the inverse of the given one.
	*/
	Matrix3 ComputeInverse(const Matrix3& a_mMat);

	static Matrix3 LinearInterpolation(const Matrix3& a_mMat0, const Matrix3& a_mMat1, real a_rProp);
}

#endif //!_COREMATH_H_