#include "AxisAlignedBoundingBox.h"
#include "BoundingSphere.h"

AxisAlignedBoundingBox::AxisAlignedBoundingBox() : AxisAlignedBox()
{

}

AxisAlignedBoundingBox::AxisAlignedBoundingBox(const glm::vec4& a_vCenter, float a_fHalfWidth, 
	float a_fHalfHeight, float a_fHalfDepth) : AxisAlignedBox(a_vCenter, 
															  a_fHalfWidth,
															  a_fHalfHeight,
															  a_fHalfDepth)

{

}

AxisAlignedBoundingBox::~AxisAlignedBoundingBox()
{

}

bool AxisAlignedBoundingBox::Intersect(const AxisAlignedBoundingBox& a_oAABB) const
{
	float _xDist = fabs(m_vCenter.x - a_oAABB.m_vCenter.x) - m_fHalfWidth - a_oAABB.m_fHalfWidth;
	if (_xDist > 0.0f)
		return false;

	float _yDist = fabs(m_vCenter.y - a_oAABB.m_vCenter.y) - m_fHalfHeight - a_oAABB.m_fHalfHeight;
	if (_yDist > 0.0f)
		return false;

	float _zDist = fabs(m_vCenter.z - a_oAABB.m_vCenter.z) - m_fHalfDepth - a_oAABB.m_fHalfDepth;
	if (_zDist > 0.0f)
		return false;

	return true;
}

bool AxisAlignedBoundingBox::Enclose(const AxisAlignedBoundingBox& a_oAABB) const
{
	float _xDist = m_fHalfWidth - (fabs(m_vCenter.x - a_oAABB.m_vCenter.x))
		+ a_oAABB.m_fHalfWidth;
	if (_xDist < 0.0f)
		return false;

	float _yDist = m_fHalfHeight - (fabs(m_vCenter.y - a_oAABB.m_vCenter.y))
		+ a_oAABB.m_fHalfHeight;
	if (_yDist < 0.0f)
		return false;

	float _zDist = m_fHalfDepth - (fabs(m_vCenter.z - a_oAABB.m_vCenter.z))
		+ a_oAABB.m_fHalfDepth;
	if (_zDist < 0.0f)
		return false;

	return true;
}

bool AxisAlignedBoundingBox::Enclose(const glm::vec4& a_vPoint) const
{
	return (a_vPoint.x <= m_vCenter.x + m_fHalfWidth)	&&
		   (a_vPoint.x >= m_vCenter.x - m_fHalfWidth)	&&
		   (a_vPoint.y <= m_vCenter.y + m_fHalfHeight)	&&
		   (a_vPoint.y >= m_vCenter.y - m_fHalfHeight)	&&
		   (a_vPoint.z <= m_vCenter.z + m_fHalfDepth)	&&
		   (a_vPoint.z >= m_vCenter.z - m_fHalfDepth);
}

bool AxisAlignedBoundingBox::Enclose(const BoundingSphere& a_oBoundingShere) const
{
	return (a_oBoundingShere.GetCenter().x + a_oBoundingShere.GetRadius() <= m_vCenter.x + m_fHalfWidth)	&&
		   (a_oBoundingShere.GetCenter().x - a_oBoundingShere.GetRadius() >= m_vCenter.x - m_fHalfWidth)	&&

		   (a_oBoundingShere.GetCenter().y + a_oBoundingShere.GetRadius() <= m_vCenter.y + m_fHalfHeight)	&&
		   (a_oBoundingShere.GetCenter().y - a_oBoundingShere.GetRadius() >= m_vCenter.y - m_fHalfHeight)	&&

		   (a_oBoundingShere.GetCenter().z + a_oBoundingShere.GetRadius() <= m_vCenter.z + m_fHalfDepth)	&&
		   (a_oBoundingShere.GetCenter().z - a_oBoundingShere.GetRadius() >= m_vCenter.z - m_fHalfDepth);
}

bool AxisAlignedBoundingBox::Inside(const BoundingSphere& a_oBoundingShere) const
{
	return a_oBoundingShere.Enclose(*this);
}