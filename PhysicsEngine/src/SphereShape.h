#ifndef _SPHERESHAPE_H_
#define _SPHERESHAPE_H_
//Lib
#include "BaseShape.h"

class SphereShape : public BaseShape
{
public:
	SphereShape(float a_fRadius, std::uint32_t a_uiNumOfSlices);
	virtual ~SphereShape();

};

inline SphereShape::SphereShape(float a_fRadius, std::uint32_t a_uiNumOfSlices)
{
	CreateSphere(&m_oShape, a_fRadius, a_uiNumOfSlices);
}

inline SphereShape::~SphereShape()
{
}

#endif //!_SPHERESHAPE_H_