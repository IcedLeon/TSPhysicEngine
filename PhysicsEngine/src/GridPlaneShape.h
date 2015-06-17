#ifndef _GRIDPLANESHAPE_H_
#define _GRIDPLANESHAPE_H_
//Lib
#include "BaseShape.h"

class GridPlaneShape : public BaseShape
{
public:
	GridPlaneShape(float a_fHorizontalExtend, float a_fVerticalExtend, std::uint32_t a_uiRow, std::uint32_t a_uiCol);
	virtual ~GridPlaneShape();

};

inline GridPlaneShape::GridPlaneShape(float a_fHorizontalExtend, float a_fVerticalExtend, 
	std::uint32_t a_uiRow, std::uint32_t a_uiCol)
{
	CreateRectangularGridPlane(&m_oShape, a_fHorizontalExtend, a_fVerticalExtend, a_uiRow, a_uiCol, false);
}

inline GridPlaneShape::~GridPlaneShape()
{
}

#endif //!_GRIDPLANESHAPE_H_