#include "ShapeFactory.h"

ShapeFactory::ShapeFactory()
{
}

ShapeFactory::~ShapeFactory()
{
}

ConeShape* ShapeFactory::CreateCone(float a_fHalfExtend, float a_fRadius,
	std::uint32_t a_uiNumOfSlices, std::uint32_t a_uiNumOfStaks)
{
	return new ConeShape(a_fHalfExtend, a_fRadius, a_uiNumOfSlices, a_uiNumOfStaks);
}

CubeShape* ShapeFactory::CreateCube(float a_fHalfExtend)
{
	return new CubeShape(a_fHalfExtend);
}

CylinderShape* ShapeFactory::CreateCylinder(float a_fHalfExtend, float a_fRadius, std::uint32_t a_uiNumOfSlices)
{
	return new CylinderShape(a_fHalfExtend, a_fRadius, a_uiNumOfSlices);
}

DomeShape* ShapeFactory::CreateDome(float a_fRadius, std::uint32_t a_uiNumOfSlices)
{
	return new DomeShape(a_fRadius, a_uiNumOfSlices);
}

GridPlaneShape* ShapeFactory::CreateGridPlane(float a_fHorizontalExtend, float a_fVerticalExtend,
	std::uint32_t a_uiRow, std::uint32_t a_uiCol)
{
	return new GridPlaneShape(a_fHorizontalExtend, a_fVerticalExtend, a_uiRow, a_uiCol);
}

SphereShape* ShapeFactory::CreateSphere(float a_fRadius, std::uint32_t a_uiNumOfSlices)
{
	return new SphereShape(a_fRadius, a_uiNumOfSlices);
}

TorusShape* ShapeFactory::CreateTorus(float a_fInnerRadius, float a_fOuterRadius,
	std::uint32_t a_uiNumOfSlices, std::uint32_t a_uiNumOfStacks)
{
	return new TorusShape(a_fInnerRadius, a_fOuterRadius, a_uiNumOfSlices, a_uiNumOfStacks);
}