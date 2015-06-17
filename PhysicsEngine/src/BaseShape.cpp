#include "BaseShape.h"

BaseShape::BaseShape()
{
	memset(&m_oShape, 0, sizeof(TShapes));
}

BaseShape::BaseShape(const TShapes& a_oShape) : m_oShape(a_oShape)
{

}

BaseShape::~BaseShape()
{
	DestroyShape(&m_oShape);
}

BaseShape& BaseShape::operator= (const BaseShape& a_oRhs)
{
	if (this == &a_oRhs)
		return *this;

	DestroyShape(&m_oShape);

	CopyShape(&m_oShape, &a_oRhs.m_oShape);

	return *this;
}

const TShapes& BaseShape::GetShape() const
{
	return m_oShape;
}