#ifndef _CONESHAPE_H_
#define _CONESHAPE_H_
//Lib
#include "BaseShape.h"
#include <cstdint>

class ConeShape : public BaseShape
{
public:
	ConeShape(float a_fHalfExtend, float a_fRadius, std::uint32_t a_uiNumOfSlices, std::uint32_t a_uiNumOfStaks);
	virtual ~ConeShape();

};

inline ConeShape::ConeShape(float a_fHalfExtend, float a_fRadius,
	std::uint32_t a_uiNumOfSlices, std::uint32_t a_uiNumOfStaks)
{
	CreateCone(&m_oShape, a_fHalfExtend, a_fRadius, a_uiNumOfSlices, a_uiNumOfStaks);
}

inline ConeShape::~ConeShape()
{

}

#endif //!_CONESHAPE_H_