#ifndef _CUBESHAPE_H_
#define _CUBESHAPE_H_
//Lib
#include "BaseShape.h"

class CubeShape : public BaseShape
{
public:
	CubeShape(float a_fHalfExtend);
	virtual ~CubeShape();

};

inline CubeShape::CubeShape(float a_fHalfExtend)
{
	CreateCube(&m_oShape, a_fHalfExtend);
}

inline CubeShape::~CubeShape()
{
}

#endif //!_CUBESHAPE_H_