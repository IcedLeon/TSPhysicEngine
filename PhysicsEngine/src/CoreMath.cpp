#include "CoreMath.h"
#include <cstddef>

namespace TSPx
{
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
		assert(a_idx >= 0);
		return (&_x)[a_idx];
	}
}