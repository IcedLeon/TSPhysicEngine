#ifndef _CYLINDERSHAPE_H_
#define _CYLINDERSHAPE_H_
//Lib
#include "BaseShape.h"

class CylinderShape : public BaseShape
{
public:
	CylinderShape(float a_fHalfExtend, float a_fRadius, std::uint32_t a_uiNumOfSlices);
	virtual ~CylinderShape();

};

inline CylinderShape::CylinderShape(float a_fHalfExtend, float a_fRadius, std::uint32_t a_uiNumOfSlices)
{
	CreateCylinder(&m_oShape, a_fHalfExtend, a_fRadius, a_uiNumOfSlices);
}

inline CylinderShape::~CylinderShape()
{
}

#endif //!_CYLINDERSHAPE_H_