#ifndef _DOMESHAPE_H_
#define _DOMESHAPE_H_
//Lib
#include "BaseShape.h"

class DomeShape : public BaseShape
{
public:
	DomeShape(float a_fRadius, std::uint32_t a_uiNumOfSlices);
	virtual ~DomeShape();

};

inline DomeShape::DomeShape(float a_fRadius, std::uint32_t a_uiNumOfSlices)
{
	CreateDome(&m_oShape, a_fRadius, a_uiNumOfSlices);
}

inline DomeShape::~DomeShape()
{
}

#endif //!_DOMESHAPE_H_