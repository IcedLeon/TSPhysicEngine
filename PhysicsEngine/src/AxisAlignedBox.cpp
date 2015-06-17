#include "AxisAlignedBox.h"

AxisAlignedBox::AxisAlignedBox() : m_vCenter(0.0f),
								   m_fHalfWidth(NULL),
								   m_fHalfHeight(NULL),
								   m_fHalfDepth(NULL)
{

}

AxisAlignedBox::AxisAlignedBox(const glm::vec4& a_vCenter, float a_fHalfWidth, 
	float a_fHalfHeight, float a_fHalfDepth) : m_vCenter(a_vCenter),
											   m_fHalfWidth(a_fHalfWidth),
											   m_fHalfHeight(a_fHalfHeight),
											   m_fHalfDepth(a_fHalfDepth)
{

}

AxisAlignedBox::~AxisAlignedBox()
{
	
}

const glm::vec4& AxisAlignedBox::GetCenter() const
{
	return m_vCenter;
}

void AxisAlignedBox::SetCenter(const glm::vec4& a_vCenter)
{
	this->m_vCenter = a_vCenter;
}

float AxisAlignedBox::GetHalfWidth() const
{
	return m_fHalfWidth;
}

void AxisAlignedBox::SetHalfWidth(float a_fHalfWidth)
{
	this->m_fHalfWidth = a_fHalfWidth;
}

float AxisAlignedBox::GetHalfHeight() const
{
	return m_fHalfHeight;
}

void AxisAlignedBox::SetHalfHeight(float a_fHalfHeight)
{
	this->m_fHalfHeight = a_fHalfHeight;
}

float AxisAlignedBox::GetHalfDepth() const
{
	return m_fHalfDepth;
}

void AxisAlignedBox::SetHalfDepth(float a_fHalfDepth)
{
	this->m_fHalfDepth = a_fHalfDepth;
}