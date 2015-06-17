#include "Sphere.h"
#include "Plane.h"

Sphere::Sphere() : m_vCenter(0.0f),
				   m_fRadius(NULL)
{

}

Sphere::Sphere(const glm::vec4& a_vCenter, float a_fRadius) : m_vCenter(a_vCenter),
															 m_fRadius(a_fRadius)
{

}

Sphere::~Sphere()
{

}

const glm::vec4& Sphere::GetCenter() const
{
	return m_vCenter;
}

void Sphere::SetCenter(const glm::vec4& a_vCenter)
{
	this->m_vCenter = a_vCenter;
}

float Sphere::GetRadius() const
{
	return m_fRadius;
}

void Sphere::SetRadius(float a_fRadius)
{
	this->m_fRadius = a_fRadius;
}

float Sphere::Distance(const glm::vec4& a_vPoint) const
{
	return glm::fastDistance(m_vCenter, a_vPoint);
}

float Sphere::Distance(const Sphere& a_oSphere) const
{
	return glm::fastDistance(m_vCenter, a_oSphere.m_vCenter);
}

float Sphere::Distance(const Plane& a_vPlane) const
{
	return a_vPlane.Distance(*this);
}