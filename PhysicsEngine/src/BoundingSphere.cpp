#include "BoundingSphere.h"
#include "AxisAlignedBoundingBox.h"

BoundingSphere::BoundingSphere() : Sphere()
{

}

BoundingSphere::BoundingSphere(const glm::vec4& a_vCenter, float a_fRadius) : Sphere(a_vCenter, 
																					 a_fRadius)
{

}

BoundingSphere::~BoundingSphere()
{

}

bool BoundingSphere::Intersect(const BoundingSphere& a_oBoundingSphere) const
{
	return glm::fastDistance(m_vCenter, a_oBoundingSphere.m_vCenter) <= m_fRadius + a_oBoundingSphere.m_fRadius;
}

bool BoundingSphere::Enclose(const BoundingSphere& a_oBoundingSphere) const
{
	return glm::fastDistance(m_vCenter, a_oBoundingSphere.m_vCenter) + a_oBoundingSphere.m_fRadius <= m_fRadius;
}

bool BoundingSphere::Enclose(const glm::vec4& a_vPoint) const
{
	return glm::fastDistance(m_vCenter, a_vPoint) <= m_fRadius;
}

bool BoundingSphere::Enclose(const AxisAlignedBoundingBox& a_oAABB) const
{
	float _halfDiag = sqrt(a_oAABB.GetHalfWidth() * a_oAABB.GetHalfWidth() +
						   a_oAABB.GetHalfHeight() * a_oAABB.GetHalfHeight() +
						   a_oAABB.GetHalfDepth() * a_oAABB.GetHalfDepth());

	float _dist = glm::fastDistance(m_vCenter, a_oAABB.GetCenter());

	return _dist + _halfDiag <= m_fRadius;
}

bool BoundingSphere::Inside(const AxisAlignedBoundingBox& a_oAABB) const
{
	return a_oAABB.Enclose(*this);
}