#include "Plane.h"
#include "Sphere.h"
#include "Shapes.h"

Plane::Plane() : m_vPlane(0.0, 1.0, 0.0, 0.0)
{
}

Plane::Plane(const glm::vec4& a_vPoint, const glm::vec3& a_vNormal)
{
	glm::vec3 _normalized =	a_vNormal;
	_normalized = glm::normalize(_normalized);

	m_vPlane.xyz = _normalized;
	
	//D = -N * P
	m_vPlane.w = -glm::dot(_normalized, a_vPoint.xyz());
}

Plane::Plane(const glm::vec3& a_vNormal, float a_fD)
{
	SetPlane(a_vNormal, a_fD);
}

Plane::Plane(const Plane& a_Rhs)
{
	SetPlane(a_Rhs);
}

Plane::~Plane()
{

}

void Plane::SetPlane(const Plane& a_Rhs)
{
	m_vPlane = a_Rhs.m_vPlane;

	float _length = glm::length(m_vPlane.xyz());

	if (_length != 0.0f)
	{
		m_vPlane.x /= _length;
		m_vPlane.y /= _length;
		m_vPlane.z /= _length;
		m_vPlane.w /= _length;
	}
}

void Plane::SetPlane(const glm::vec3 a_vNormal, float a_fD)
{
	m_vPlane.xyz	= a_vNormal;
	m_vPlane.w		= a_fD;

	float _length = glm::length(m_vPlane.xyz());

	if (_length != 0.0f)
	{
		m_vPlane.x /= _length;
		m_vPlane.y /= _length;
		m_vPlane.z /= _length;
		m_vPlane.w /= _length;
	}
}

const glm::vec4 Plane::GetPlane() const
{
	return m_vPlane;
}

float Plane::Distance(const glm::vec4& a_vPoint) const
{
	return glm::dot(m_vPlane.xyz(), m_vPlane.xyz()) + m_vPlane.w;
}

float Plane::Distance(const Sphere& a_vShere) const
{
	return Distance(a_vShere.GetCenter());
}