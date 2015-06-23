#include "CoreMath.h"
#include <cstddef>

namespace TSPx
{
	real m_rSleepEpsilon = static_cast<real>(0.3);

	void SetSleepEpsilon(real a_rSleepEpsilon)
	{
		m_rSleepEpsilon = a_rSleepEpsilon;
	}

	real GetSleepEpsilon()
	{
		return m_rSleepEpsilon;
	}

	/*			  VECTOR3				 */
	/*Physics Vec3 with 4 word alignement*/
	
	Vec3::Vec3() : _x(NULL), _y(NULL), _z(NULL), _pad(NULL)
	{
	}

	Vec3::Vec3(const Vec3& a_Other) :
		_x(a_Other._x), _y(a_Other._y), _z(a_Other._z), _pad(NULL)
	{
	}

	Vec3::Vec3(const real& a_rValue) :
		_x(a_rValue), _y(a_rValue), _z(a_rValue), _pad(NULL)
	{
	}
	
	Vec3::Vec3(const real& a_rX, const real& a_rY, const real& a_rZ) :
		_x(a_rX), _y(a_rY), _z(a_rZ), _pad(NULL)
	{
	}

	template<typename A, typename B, typename C>
	Vec3::Vec3(const A& a_X, const B& a_Y, const C& a_Z) :
		_x(static_cast<real>(a_X)), _x(static_cast<real>(a_Y)), _x(static_cast<real>(a_Z)), _pad(NULL)
	{
	}

	template<typename V>
	Vec3::Vec3(const V& a_Value) :
		_x(static_cast<real>(a_Value)), _y(static_cast<real>(a_Value)), _z(static_cast<real>(a_Value)), _pad(NULL)
	{
	}

	Vec3::Vec3(const vec3& a_glmVec) :
		_x(static_cast<real>(a_glmVec.x)), _y(static_cast<real>(a_glmVec.y)), _z(static_cast<real>(a_glmVec.z)), _pad(NULL)
	{
	}

	Vec3::~Vec3()
	{
	}

	const size_t Vec3::Size() const
	{
		return 3;
	}

	real& Vec3::operator[](size_t a_idx)
	{
		assert(a_idx >= 0 && a_idx >= Size());
		return (&_x)[a_idx];
	}

	const real& Vec3::operator[](size_t a_idx) const
	{
		assert(a_idx >= 0 && a_idx >= Size());
		return (&_x)[a_idx];
	}

	Vec3 Vec3::operator-() const
	{
		Vec3 _tmp(-this->_x,
				  -this->_y,
				  -this->_z);

		return _tmp;
	}

	Vec3 Vec3::operator+(const Vec3& a_vVector) const
	{
		return Vec3(this->_x + a_vVector._x, this->_y + a_vVector._y, this->_z + a_vVector._z);
	}

	Vec3 Vec3::operator-(const Vec3& a_vVector) const
	{
		return Vec3(this->_x - a_vVector._x, this->_y - a_vVector._y, this->_z - a_vVector._z);
	}

	Vec3 Vec3::operator*(const Vec3& a_vVector) const
	{
		return Vec3(this->_x * a_vVector._x, this->_y * a_vVector._y, this->_z * a_vVector._z);
	}

	Vec3 Vec3::operator/(const Vec3& a_vVector) const
	{
		return Vec3(this->_x / a_vVector._x, this->_y / a_vVector._y, this->_z / a_vVector._z);
	}

	Vec3& Vec3::operator=(const Vec3& a_vVector)
	{
		this->_x = a_vVector._x;
		this->_y = a_vVector._y;
		this->_z = a_vVector._z;
		return *this;
	}

	Vec3& Vec3::operator+=(real a_Value)
	{
		this->_x += a_Value;
		this->_y += a_Value;
		this->_z += a_Value;
		return *this;
	}

	Vec3& Vec3::operator+=(const Vec3& a_vVector)
	{
		this->_x += a_vVector._x;
		this->_y += a_vVector._y;
		this->_z += a_vVector._z;
		return *this;
	}

	Vec3& Vec3::operator+=(const vec3& a_glmVec)
	{
		this->_x += static_cast<real>(a_glmVec.x);
		this->_y += static_cast<real>(a_glmVec.y);
		this->_z += static_cast<real>(a_glmVec.z);
		return *this;
	}

	Vec3& Vec3::operator-=(real a_Value)
	{
		this->_x -= a_Value;
		this->_y -= a_Value;
		this->_z -= a_Value;
		return *this;
	}

	Vec3& Vec3::operator-=(const Vec3& a_vVector)
	{
		this->_x -= a_vVector._x;
		this->_y -= a_vVector._y;
		this->_z -= a_vVector._z;
		return *this;
	}

	Vec3& Vec3::operator-=(const vec3& a_glmVec)
	{
		this->_x -= static_cast<real>(a_glmVec.x);
		this->_y -= static_cast<real>(a_glmVec.y);
		this->_z -= static_cast<real>(a_glmVec.z);
		return *this;
	}

	Vec3& Vec3::operator*=(real a_Value)
	{
		this->_x *= a_Value;
		this->_y *= a_Value;
		this->_z *= a_Value;
		return *this;
	}

	Vec3& Vec3::operator*=(const Vec3& a_vVector)
	{
		this->_x *= a_vVector._x;
		this->_y *= a_vVector._y;
		this->_z *= a_vVector._z;
		return *this;
	}

	Vec3& Vec3::operator*=(const vec3& a_glmVec)
	{
		this->_x *= static_cast<real>(a_glmVec.x);
		this->_y *= static_cast<real>(a_glmVec.y);
		this->_z *= static_cast<real>(a_glmVec.z);
		return *this;
	}

	Vec3& Vec3::operator/=(real a_Value)
	{
		this->_x /= a_Value;
		this->_y /= a_Value;
		this->_z /= a_Value;
		return *this;
	}

	Vec3& Vec3::operator/=(const Vec3& a_vVector)
	{
		this->_x /= a_vVector._x;
		this->_y /= a_vVector._y;
		this->_z /= a_vVector._z;
		return *this;
	}

	Vec3& Vec3::operator/=(const vec3& a_glmVec)
	{
		this->_x /= static_cast<real>(a_glmVec.x);
		this->_y /= static_cast<real>(a_glmVec.y);
		this->_z /= static_cast<real>(a_glmVec.z);
		return *this;
	}

	bool Vec3::operator==(const Vec3& a_vVector)
	{
		return (this->_x == a_vVector._x) && (this->_y == a_vVector._y) && (this->_z == a_vVector._z);
	}

	bool Vec3::operator!=(const Vec3& a_vVector)
	{
		return (this->_x != a_vVector._x) && (this->_y != a_vVector._y) && (this->_z != a_vVector._z);
	}

	bool Vec3::operator<(const Vec3& a_vVector)
	{
		return (this->_x < a_vVector._x) && (this->_y < a_vVector._y) && (this->_z < a_vVector._z);
	}

	bool Vec3::operator>(const Vec3& a_vVector)
	{
		return (this->_x > a_vVector._x) && (this->_y > a_vVector._y) && (this->_z > a_vVector._z);
	}

	bool Vec3::operator<=(const Vec3& a_vVector)
	{
		return (this->_x <= a_vVector._x) && (this->_y <= a_vVector._y) && (this->_z <= a_vVector._z);
	}

	bool Vec3::operator>=(const Vec3& a_vVector)
	{
		return (this->_x >= a_vVector._x) && (this->_y >= a_vVector._y) && (this->_z >= a_vVector._z);
	}

	Vec3& Vec3::operator++()
	{
		++this->_x;
		++this->_y;
		++this->_z;
		return *this;
	}

	Vec3& Vec3::operator++()
	{
		--this->_x;
		--this->_y;
		--this->_z;
		return *this;
	}

	void Vec3::Zero()
	{
		this->_x = this->_y = this->_z = NULL;
	}
	
	void Vec3::Normalise()
	{
		*this * real_inv_sqrt(Dot(this));
	}

	real Vec3::Magnitude() const
	{
		return real_sqrt(Dot(this));
	}

	real Vec3::SqrMagnitude() const
	{
		return Dot(this);
	}

	real Vec3::Distance(const Vec3& a_vVector) const
	{
		return real_sqrt(Dot(-a_vVector));
	}

	real Vec3::Dot(const Vec3& a_vVector) const
	{
		Vec3 _tmp(*this * a_vVector);
		return _tmp._x + _tmp._y + _tmp._z;
	}

	Vec3 Vec3::Cross(const Vec3& a_vVector) const
	{
		return Vec3(
			this->_y * a_vVector._z - a_vVector._y * this->_z,
			this->_z * a_vVector._x - a_vVector._z * this->_x,
			this->_x * a_vVector._y - a_vVector._x * this->_y);
	}

	void Vec3::Trim(real a_rTrimmer)
	{
		if (SqrMagnitude() > a_rTrimmer * a_rTrimmer)
		{
			Normalise();
			this->_x *= a_rTrimmer;
			this->_y *= a_rTrimmer;
			this->_z *= a_rTrimmer;
		}
	}

	void Vec3::ScaleByVector(const Vec3& a_vVector, const real a_rScale)
	{
		this->_x += a_vVector._x * a_rScale;
		this->_y += a_vVector._y * a_rScale;
		this->_z += a_vVector._z * a_rScale;
	}

	Vec3 operator+(const Vec3& a_vVector, const real& a_rValue)
	{
		return Vec3(a_vVector._x + a_rValue, a_vVector._y + a_rValue, a_vVector._z + a_rValue);
	}

	Vec3 operator+(const real& a_rValue, const Vec3& a_vVector)
	{
		return Vec3(a_rValue + a_vVector._x, a_rValue + a_vVector._y, a_rValue + a_vVector._z);
	}

	Vec3 operator+(const Vec3& a_vVector, const vec3& a_glmVec)
	{
		return Vec3(a_vVector._x + static_cast<real>(a_glmVec.x),
					a_vVector._y + static_cast<real>(a_glmVec.y),
					a_vVector._z + static_cast<real>(a_glmVec.z));
	}

	Vec3 operator+(const vec3& a_glmVec, const Vec3& a_vVector)
	{
		return Vec3(static_cast<real>(a_glmVec.x) + a_vVector._x,
					static_cast<real>(a_glmVec.y) + a_vVector._y,
					static_cast<real>(a_glmVec.z) + a_vVector._z);
	}

	Vec3 operator-(const Vec3& a_vVector, const real& a_rValue)
	{
		return Vec3(a_vVector._x - a_rValue, a_vVector._y - a_rValue, a_vVector._z - a_rValue);
	}

	Vec3 operator-(const real& a_rValue, const Vec3& a_vVector)
	{
		return Vec3(a_rValue - a_vVector._x, a_rValue - a_vVector._y, a_rValue - a_vVector._z);
	}

	Vec3 operator-(const Vec3& a_vVector, const vec3& a_glmVec)
	{
		return Vec3(a_vVector._x - static_cast<real>(a_glmVec.x),
					a_vVector._y - static_cast<real>(a_glmVec.y),
					a_vVector._z - static_cast<real>(a_glmVec.z));
	}

	Vec3 operator-(const vec3& a_glmVec, const Vec3& a_vVector)
	{
		return Vec3(static_cast<real>(a_glmVec.x) - a_vVector._x,
					static_cast<real>(a_glmVec.y) - a_vVector._y,
					static_cast<real>(a_glmVec.z) - a_vVector._z);
	}

	Vec3 operator*(const Vec3& a_vVector, const real& a_rValue)
	{
		return Vec3(a_vVector._x * a_rValue, a_vVector._y * a_rValue, a_vVector._z * a_rValue);
	}

	Vec3 operator*(const real& a_rValue, const Vec3& a_vVector)
	{
		return Vec3(a_rValue * a_vVector._x, a_rValue * a_vVector._y, a_rValue * a_vVector._z);
	}

	Vec3 operator*(const Vec3& a_vVector, const vec3& a_glmVec)
	{
		return Vec3(a_vVector._x * static_cast<real>(a_glmVec.x),
					a_vVector._y * static_cast<real>(a_glmVec.y),
					a_vVector._z * static_cast<real>(a_glmVec.z));
	}

	Vec3 operator*(const vec3& a_glmVec, const Vec3& a_vVector)
	{
		return Vec3(static_cast<real>(a_glmVec.x) * a_vVector._x,
					static_cast<real>(a_glmVec.y) * a_vVector._y,
					static_cast<real>(a_glmVec.z) * a_vVector._z);
	}

	Vec3 operator/(const Vec3& a_vVector, const real& a_rValue)
	{
		return Vec3(a_vVector._x / a_rValue, a_vVector._y / a_rValue, a_vVector._z / a_rValue);
	}

	Vec3 operator/(const real& a_rValue, const Vec3& a_vVector)
	{
		return Vec3(a_rValue / a_vVector._x, a_rValue / a_vVector._y, a_rValue / a_vVector._z);
	}

	Vec3 operator/(const Vec3& a_vVector, const vec3& a_glmVec)
	{
		return Vec3(a_vVector._x / static_cast<real>(a_glmVec.x),
					a_vVector._y / static_cast<real>(a_glmVec.y),
					a_vVector._z / static_cast<real>(a_glmVec.z));
	}

	Vec3 operator/(const vec3& a_glmVec, const Vec3& a_vVector)
	{
		return Vec3(static_cast<real>(a_glmVec.x) / a_vVector._x,
					static_cast<real>(a_glmVec.y) / a_vVector._y,
					static_cast<real>(a_glmVec.z) / a_vVector._z);
	}

	Vec3 Refract(const Vec3& a_vIncVector, const Vec3& a_vSurfNorm, real a_rEta)
	{
		real const _dotVal = a_vSurfNorm.Dot(a_vIncVector);
		real const _k(static_cast<real>(1) - a_rEta * a_rEta *(static_cast<real>(1) - _dotVal * _dotVal));

		return (a_rEta * a_vIncVector - (a_rEta * _dotVal + real_sqrt(_k)) * a_vSurfNorm) * static_cast<real>(_k >= static_cast<real>(0));
	}

	/*Matrix*/
	Matrix3::Matrix3()
	{
		for (size_t i = 0; i < 9; ++i)
			this->_m[i] = static_cast<real>(NULL);

		this->_m[0] = static_cast<real>(1);
		this->_m[4] = static_cast<real>(1);
		this->_m[8] = static_cast<real>(1);
	}

	Matrix3::Matrix3(const Matrix3& a_mMat)
	{
		for (size_t i = 0; i < 9; ++i)
			this->_m[i] = a_mMat._m[i];
	}

	Matrix3::Matrix3(const real& a_rValue)
	{
		for (size_t i = 0; i < 9; ++i)
			this->_m[i] = static_cast<real>(NULL);

		this->_m[0] = a_rValue;
		this->_m[4] = a_rValue;
		this->_m[8] = a_rValue;
	}
	
	Matrix3::Matrix3(const real& a_rX0, const real& a_rY0, const real& a_rZ0,
					 const real& a_rX1, const real& a_rY1, const real& a_rZ1,
					 const real& a_rX2, const real& a_rY2, const real& a_rZ2)
	{
		this->_m[0] = a_rX0; this->_m[1] = a_rY0; this->_m[2] = a_rZ0;
		this->_m[3] = a_rX1; this->_m[4] = a_rY1; this->_m[5] = a_rZ1;
		this->_m[6] = a_rX2; this->_m[7] = a_rY2; this->_m[8] = a_rZ2;
	}

	template<typename A>
	Matrix3::Matrix3(const A& a_rX0, const A& a_rY0, const A& a_rZ0,
					 const A& a_rX1, const A& a_rY1, const A& a_rZ1,
					 const A& a_rX2, const A& a_rY2, const A& a_rZ2)
	{
		this->_m[0] = static_cast<real>(a_rX0); 
		this->_m[3] = static_cast<real>(a_rX1); 
		this->_m[6] = static_cast<real>(a_rX2);

		this->_m[1] = static_cast<real>(a_rY0);
		this->_m[4] = static_cast<real>(a_rY1);
		this->_m[7] = static_cast<real>(a_rY2);
		
		this->_m[2] = static_cast<real>(a_rZ0);
		this->_m[5] = static_cast<real>(a_rZ1);
		this->_m[8] = static_cast<real>(a_rZ2);
	}

	template<typename A, typename B, typename C>
	Matrix3::Matrix3(const A& a_rX0, const B& a_rY0, const C& a_rZ0,
					 const A& a_rX1, const B& a_rY1, const C& a_rZ1,
					 const A& a_rX2, const B& a_rY2, const C& a_rZ2)
	{
		this->_m[0] = static_cast<real>(a_rX0);
		this->_m[3] = static_cast<real>(a_rX1);
		this->_m[6] = static_cast<real>(a_rX2);

		this->_m[1] = static_cast<real>(a_rY0);
		this->_m[4] = static_cast<real>(a_rY1);
		this->_m[7] = static_cast<real>(a_rY2);

		this->_m[2] = static_cast<real>(a_rZ0);
		this->_m[5] = static_cast<real>(a_rZ1);
		this->_m[8] = static_cast<real>(a_rZ2);
	}
	
		template<typename A0, typename B0, typename C0,
				 typename A1, typename B1, typename C1,
				 typename A2, typename B2, typename C2>
		Matrix3::Matrix3(const A0& a_rX0, const B0& a_rY0, const C0& a_rZ0,
						 const A1& a_rX1, const B1& a_rY1, const C1& a_rZ1,
						 const A2& a_rX2, const B2& a_rY2, const C2& a_rZ2)
		{
			this->_m[0] = static_cast<real>(a_rX0);
			this->_m[3] = static_cast<real>(a_rX1);
			this->_m[6] = static_cast<real>(a_rX2);

			this->_m[1] = static_cast<real>(a_rY0);
			this->_m[4] = static_cast<real>(a_rY1);
			this->_m[7] = static_cast<real>(a_rY2);

			this->_m[2] = static_cast<real>(a_rZ0);
			this->_m[5] = static_cast<real>(a_rZ1);
			this->_m[8] = static_cast<real>(a_rZ2);
		}

		Matrix3::Matrix3(const Vec3& a_vVector0, const Vec3& a_vVector1, const Vec3& a_vVector2)
		{
			this->_m[0] = a_vVector0._x; this->_m[1] = a_vVector0._y; this->_m[2] = a_vVector0._z;
			this->_m[3] = a_vVector1._x; this->_m[4] = a_vVector1._y; this->_m[5] = a_vVector1._z;
			this->_m[6] = a_vVector2._x; this->_m[7] = a_vVector2._y; this->_m[8] = a_vVector2._z;
		}

		Matrix3::Matrix3(const vec3& a_glmVec0, const vec3& a_glmVec1, const vec3& a_glmVec2)
		{
			Vec3 _tmp0(a_glmVec0);
			Vec3 _tmp1(a_glmVec1);
			Vec3 _tmp2(a_glmVec2);

			*this = Matrix3(_tmp0, _tmp1, _tmp2);
		}

		Matrix3::~Matrix3()
		{
		}

		size_t Matrix3::Size() const
		{
			return 9;
		}

		Matrix3::mat_type& Matrix3::operator[](size_t a_idx)
		{
			assert(a_idx < this->Size());
			return this->_m[a_idx];
		}

		const Matrix3::mat_type& Matrix3::operator[](size_t a_idx) const
		{
			assert(a_idx < this->Size());
			return this->_m[a_idx];
		}

		Matrix3& Matrix3::operator=(const Matrix3& a_mMat)
		{
			for (size_t i = 0; i < 9; ++i)
				this->_m[i] = a_mMat._m[i];

			return *this;
		}
				 
		Matrix3& Matrix3::operator+=(const Matrix3& a_mMat)
		{
			for (size_t i = 0; i < 9; ++i)
				this->_m[i] += a_mMat._m[i];

			return *this;
		}

		Matrix3& Matrix3::operator+=(real a_Value)
		{
			for (size_t i = 0; i < 9; ++i)
				this->_m[i] += a_Value;

			return *this;
		}
				 
		Matrix3& Matrix3::operator-=(const Matrix3& a_mMat)
		{
			for (size_t i = 0; i < 9; ++i)
				this->_m[i] -= a_mMat._m[i];

			return *this;
		}

		Matrix3& Matrix3::operator-=(real a_Value)
		{
			for (size_t i = 0; i < 9; ++i)
				this->_m[i] -= a_Value;

			return *this;
		}
				 
		Matrix3& Matrix3::operator*=(const Matrix3& a_mMat)
		{
			return (*this = *this * a_mMat);
		}

		Matrix3& Matrix3::operator*=(real a_Value)
		{
			for (size_t i = 0; i < 9; ++i)
				this->_m[i] *= a_Value;

			return *this;
		}
		
		Matrix3& Matrix3::operator/=(const Matrix3& a_mMat)
		{
			return (*this = *this * ComputeInverse(a_mMat));
		}

		Matrix3& Matrix3::operator/=(real a_Value)
		{
			for (size_t i = 0; i < 9; ++i)
				this->_m[i] /= a_Value;

			return *this;
		}

		Matrix3& Matrix3::operator++()
		{
			for (size_t i = 0; i < 9; ++i)
				++this->_m[i];

			return *this;
		}

		Matrix3& Matrix3::operator--()
		{
			for (size_t i = 0; i < 9; ++i)
				--this->_m[i];

			return *this;
		}
		

		Matrix3 Matrix3::operator+(const Matrix3& a_mMat) const
		{
			Matrix3 _toReturn(0);

			for (size_t i = 0; i < 9; ++i)
				_toReturn._m[i] = this->_m[i] + a_mMat._m[i];

			return _toReturn;
		}

		Matrix3 Matrix3::operator-(const Matrix3& a_mMat) const
		{
			Matrix3 _toReturn(0);

			for (size_t i = 0; i < 9; ++i)
				_toReturn._m[i] = this->_m[i] - a_mMat._m[i];

			return _toReturn;
		}

		Matrix3 Matrix3::operator*(const Matrix3& a_mMat) const
		{
			real const SrcA00 = this->_m[0];
			real const SrcA01 = this->_m[1];
			real const SrcA02 = this->_m[2];
			real const SrcA10 = this->_m[3];
			real const SrcA11 = this->_m[4];
			real const SrcA12 = this->_m[5];
			real const SrcA20 = this->_m[6];
			real const SrcA21 = this->_m[7];
			real const SrcA22 = this->_m[8];

			real const SrcB00 = a_mMat._m[0];
			real const SrcB01 = a_mMat._m[1];
			real const SrcB02 = a_mMat._m[2];
			real const SrcB10 = a_mMat._m[3];
			real const SrcB11 = a_mMat._m[4];
			real const SrcB12 = a_mMat._m[5];
			real const SrcB20 = a_mMat._m[6];
			real const SrcB21 = a_mMat._m[7];
			real const SrcB22 = a_mMat._m[8];

			Matrix3 _toReturn(0);
			_toReturn._m[0] = SrcA00 * SrcB00 + SrcA10 * SrcB01 + SrcA20 * SrcB02;
			_toReturn._m[1] = SrcA01 * SrcB00 + SrcA11 * SrcB01 + SrcA21 * SrcB02;
			_toReturn._m[2] = SrcA02 * SrcB00 + SrcA12 * SrcB01 + SrcA22 * SrcB02;
			_toReturn._m[3] = SrcA00 * SrcB10 + SrcA10 * SrcB11 + SrcA20 * SrcB12;
			_toReturn._m[4] = SrcA01 * SrcB10 + SrcA11 * SrcB11 + SrcA21 * SrcB12;
			_toReturn._m[5] = SrcA02 * SrcB10 + SrcA12 * SrcB11 + SrcA22 * SrcB12;
			_toReturn._m[6] = SrcA00 * SrcB20 + SrcA10 * SrcB21 + SrcA20 * SrcB22;
			_toReturn._m[7] = SrcA01 * SrcB20 + SrcA11 * SrcB21 + SrcA21 * SrcB22;
			_toReturn._m[8] = SrcA02 * SrcB20 + SrcA12 * SrcB21 + SrcA22 * SrcB22;
			
			return _toReturn;
		}

		Matrix3 Matrix3::operator/(const Matrix3& a_mMat) const
		{
			Matrix3 _tmp(*this);

			return _tmp /= a_mMat;
		}

		void Matrix3::SetInertiaTensorCoeff(real a_rIX0, real a_rIY0, real a_rIZ0,
			real a_rIX1 /*=0*/,	real a_rIY1 /*=0*/,	real a_rIZ1 /*=0*/)
		{
			this->_m[0] = a_rIX0;
			this->_m[1] = this->_m[3] = -a_rIX1;
			this->_m[2] = this->_m[6] = -a_rIY1;
			this->_m[4] = a_rIY0;
			this->_m[5] = this->_m[7] = -a_rIZ1;
			this->_m[8] = a_rIZ0;
		}

		void Matrix3::SetBlockInertiaTensor(const Vec3& a_vHalfSize, real a_rMass)
		{
			//Simply a component product.
			Vec3 _squares(a_vHalfSize._x * a_vHalfSize._x, 
						  a_vHalfSize._y * a_vHalfSize._y, 
						  a_vHalfSize._z * a_vHalfSize._z);

			real _eta = static_cast<real>(0.3f);

			SetInertiaTensorCoeff(_eta * a_rMass * (_squares._y + _squares._z),
								  _eta * a_rMass * (_squares._x + _squares._z),
								  _eta * a_rMass * (_squares._y + _squares._y));
		}

		void Matrix3::SetSkewSymmetric(const Vec3& a_vVector)
		{
			this->_m[0] = this->_m[4] = this->_m[8] = static_cast<real>(0);
			this->_m[1] = -a_vVector._z;
			this->_m[2] =  a_vVector._y; 
			this->_m[3] =  a_vVector._z;
			this->_m[5] = -a_vVector._x;
			this->_m[6] = -a_vVector._y; 
			this->_m[7] =  a_vVector._x;
		}

		Vec3 Matrix3::GetRowInVec3(size_t a_idx) const
		{
			assert(a_idx < 0 && a_idx > 2);
			return Vec3(this->_m[a_idx * 3], this->_m[a_idx * 3 + 1], this->_m[a_idx * 3 + 2]);
		}
		
		void Matrix3::Invert()
		{
			ComputeInverse(*this);
		}

		void Matrix3::SetTranspose(const Matrix3& a_mMat)
		{
			this->_m[0]	= a_mMat._m[0];
			this->_m[1]	= a_mMat._m[3];
			this->_m[2]	= a_mMat._m[6];
			this->_m[3]	= a_mMat._m[1];
			this->_m[4] = a_mMat._m[4];
			this->_m[5]	= a_mMat._m[7];
			this->_m[6]	= a_mMat._m[1];
			this->_m[7] = a_mMat._m[5];
			this->_m[8] = a_mMat._m[8];
		}
				
		Matrix3 Matrix3::Transpose() const
		{
			Matrix3 _toReturn(0);
			_toReturn.SetTranspose(*this);
			return _toReturn;
		}

		real Matrix3::GetDeterminant() const
		{
			real _t4  = this->_m[0] * this->_m[4];
			real _t6  = this->_m[0] * this->_m[5];
			real _t8  = this->_m[1] * this->_m[3];
			real _t10 = this->_m[2] * this->_m[3];
			real _t12 = this->_m[1] * this->_m[6];
			real _t14 = this->_m[2] * this->_m[6];

			real _t16 = _t4  * this->_m[8] - 
						_t6  * this->_m[7] -
						_t8  * this->_m[8] + 
						_t10 * this->_m[7] + 
						_t12 * this->_m[5] -
						_t14 * this->_m[4];

			return _t16;
		}

		Matrix3 operator+(const Matrix3& a_vVector, const real& a_rValue)
		{
			//here
		}

		Matrix3 operator+(const real& a_rValue, const Matrix3& a_vVector)
		{

		}

		Matrix3 ComputeInverse(const Matrix3& a_mMat)
		{
			real _oneOverDeterminant = static_cast<real>(1) / a_mMat.GetDeterminant();

			Matrix3 _inverse(0);

			_inverse._m[0] = +(a_mMat._m[4] * a_mMat._m[8] - a_mMat._m[7] * a_mMat[5]) * _oneOverDeterminant;
			_inverse._m[1] = -(a_mMat._m[3] * a_mMat._m[8] - a_mMat._m[6] * a_mMat[5]) * _oneOverDeterminant;
			_inverse._m[2] = +(a_mMat._m[3] * a_mMat._m[7] - a_mMat._m[6] * a_mMat[4]) * _oneOverDeterminant;
			_inverse._m[3] = -(a_mMat._m[1] * a_mMat._m[8] - a_mMat._m[7] * a_mMat[3]) * _oneOverDeterminant;
			_inverse._m[4] = +(a_mMat._m[0] * a_mMat._m[8] - a_mMat._m[6] * a_mMat[3]) * _oneOverDeterminant;
			_inverse._m[5] = -(a_mMat._m[0] * a_mMat._m[7] - a_mMat._m[6] * a_mMat[1]) * _oneOverDeterminant;
			_inverse._m[6] = +(a_mMat._m[1] * a_mMat._m[5] - a_mMat._m[4] * a_mMat[3]) * _oneOverDeterminant;
			_inverse._m[7] = -(a_mMat._m[0] * a_mMat._m[5] - a_mMat._m[3] * a_mMat[3]) * _oneOverDeterminant;
			_inverse._m[8] = +(a_mMat._m[0] * a_mMat._m[4] - a_mMat._m[3] * a_mMat[1]) * _oneOverDeterminant;

			return _inverse;
		}
}