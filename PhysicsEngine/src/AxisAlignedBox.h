#ifndef _AXISALIGNEDBOX_H_
#define _AXISALIGNEDBOX_H_
//Lib
#define GLM_SWIZZLE
#include "glm\glm\glm.hpp"
#include "glm\glm\ext.hpp"


class AxisAlignedBox
{
protected:
	glm::vec4 m_vCenter;
	float m_fHalfWidth;
	float m_fHalfHeight;
	float m_fHalfDepth;
	
public:
	AxisAlignedBox();
	AxisAlignedBox(const glm::vec4& a_vCenter, float a_fHalfWidth, float a_fHalfHeight, float a_fHalfDepth);
	virtual	~AxisAlignedBox();

	const glm::vec4& GetCenter() const;
	void SetCenter(const glm::vec4& a_vCenter);
	float GetHalfWidth() const;
	void SetHalfWidth(float a_fHalfWidth);
	float GetHalfHeight() const;
	void SetHalfHeight(float a_fHalfHeight);
	float GetHalfDepth() const;
	void SetHalfDepth(float a_fHalfDepth);
};

#endif //!_AXISALIGNEDBOX_H_