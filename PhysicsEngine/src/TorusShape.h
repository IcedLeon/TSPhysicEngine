#ifndef _TORUSSHAPE_H_
#define _TORUSSHAPE_H_
//Lib
#include "BaseShape.h"

class TorusShape : public BaseShape
{
public:
	TorusShape(float a_fInnerRadius, float a_fOuterRadius, std::uint32_t a_uiNumOfSlices, std::uint32_t a_uiNumOfStacks);
	virtual ~TorusShape();

};

inline TorusShape::TorusShape(float a_fInnerRadius, float a_fOuterRadius, 
	std::uint32_t a_uiNumOfSlices, std::uint32_t a_uiNumOfStacks)
{
	CreateTorus(&m_oShape, a_fInnerRadius, a_fOuterRadius, a_uiNumOfSlices, a_uiNumOfStacks);
}

inline TorusShape::~TorusShape()
{
}

#endif //!_TORUSSHAPE_H_