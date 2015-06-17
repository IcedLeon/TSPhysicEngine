#ifndef _SHAPEFACTORY_H_
#define _SHAPEFACTORY_H_
//Lib
#include "ConeShape.h"
#include "CubeShape.h"
#include "CylinderShape.h"
#include "SphereShape.h"
#include "DomeShape.h"
#include "GridPlaneShape.h"
#include "TorusShape.h"

class ShapeFactory
{
public:
	ShapeFactory();
	virtual ~ShapeFactory();

	ConeShape* CreateCone(float a_fHalfExtend, float a_fRadius, 
		std::uint32_t a_uiNumOfSlices, std::uint32_t a_uiNumOfStaks);

	CubeShape* CreateCube(float a_fHalfExtend);

	CylinderShape* CreateCylinder(float a_fHalfExtend, float a_fRadius, std::uint32_t a_uiNumOfSlices);

	DomeShape* CreateDome(float a_fRadius, std::uint32_t a_uiNumOfSlices);

	GridPlaneShape* CreateGridPlane(float a_fHorizontalExtend, float a_fVerticalExtend,
		std::uint32_t a_uiRow, std::uint32_t a_uiCol);

	SphereShape* CreateSphere(float a_fRadius, std::uint32_t a_uiNumOfSlices);

	TorusShape* CreateTorus(float a_fInnerRadius, float a_fOuterRadius,
		std::uint32_t a_uiNumOfSlices, std::uint32_t a_uiNumOfStacks);
};

#endif //_SHAPEFACTORY_H_