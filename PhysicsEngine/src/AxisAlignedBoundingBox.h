#ifndef _AXISALIGNEDBOUNDINGBOX_H_
#define _AXISALIGNEDBOUNDINGBOX_H_
//Lib
#include "AxisAlignedBox.h"

class BoundingSphere;

class AxisAlignedBoundingBox : public AxisAlignedBox
{
public:
	AxisAlignedBoundingBox();
	AxisAlignedBoundingBox(const glm::vec4& a_vCenter, float a_fHalfWidth, float a_fHalfHeight, float a_fHalfDepth);
	virtual ~AxisAlignedBoundingBox();
	
	bool Intersect(const AxisAlignedBoundingBox& a_oAABB) const;
	bool Enclose(const AxisAlignedBoundingBox& a_vPoint) const;
	bool Enclose(const glm::vec4& a_vPoint) const;
	bool Enclose(const BoundingSphere& a_oBoundingSphere) const;
	bool Inside(const BoundingSphere& a_oBoundingSphere) const;
};

#endif //!_AXISALIGNEDBOUNDINGBOX_H_