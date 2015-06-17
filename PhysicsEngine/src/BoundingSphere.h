#ifndef _BOUNDINGSPHERE_H_
#define _BOUNDINGSPHERE_H_
//Lib
#include "Sphere.h"

class AxisAlignedBoundingBox;

class BoundingSphere : public Sphere
{
public:
	BoundingSphere();
	BoundingSphere(const glm::vec4& a_vCenter, float a_fRadius);
	virtual ~BoundingSphere();

	bool Intersect(const BoundingSphere& a_oBoundingSphere) const;

	bool Enclose(const BoundingSphere& a_oBoundingSphere) const;

	bool Enclose(const glm::vec4& a_vPoint) const;

	bool Enclose(const AxisAlignedBoundingBox& a_oAABB) const;

	bool Inside(const AxisAlignedBoundingBox& a_oAABB) const;
};

#endif //!_BOUNDINGSPHERE_H_