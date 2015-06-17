#ifndef _SHAPES_H_
#define _SHAPES_H_
//Lib
#include "gl_core_4_4.h"
#define GLM_SWIZZLE
#include "glm\glm\glm.hpp"
#include "glm\glm\gtc\matrix_transform.hpp"
#include "glm\glm\ext.hpp"

#define MAX_VERTICES 1048576
#define MAX_INDICES_FACT 4
#define MAX_INDICES (MAX_VERTICES * MAX_INDICES_FACT)

/*
*Simple data structure for holding the foundamental
* geometry data.
*/
typedef struct Shape
{
	/* The vertices in homogenous coordinates */
	float* m_vVertices;
	/* The normals of this geometry.*/
	float* m_vNormals;
	/* The tangents of this geometry.*/
	float* m_vTangent;
	/* The bitangents of this geometry.*/
	float* m_vBitangent;
	/* Texture coordinates. */
	float* m_vTexCoord;
	/* All the above values in one array */
	float* a_pfAllTheAttributes;
	/* Indeces. */
	unsigned int* m_puiIndices;
	/* The total number of the current geometry vertices. */
	unsigned int m_uiNumOfVert;
	/* The total number of the current geometry Indeces. */
	unsigned int m_uiNumOfIndices;
	/*
	*Current render mode:
	*GL_TRIANGLES,
	*GL_TRIANGLE_STRIP,
	*GL_POINTS.
	*TD:RL most common rendering mode.
	*/
	GLenum m_eMode;
} TShapes;

/*
*Create a quadratic plane.
* @param a_oShape: Is the data stored into the TShape data structure.
* @param a_fHalfExtend: Is the length from the center point to any border of the plane.
* Return true if the creation has succeeded.
*/
bool CreatePlane(TShapes* a_oShape, const float a_cfHalfExtend);

bool CreateRectangularPlane(TShapes* a_oShape, const float a_cfHorizintalExtend, const float a_cfVerticalExtend);

bool CreateRectangularGridPlane(TShapes* a_oShape,
	const float a_cfHorizintalExtend,
	const float a_cfVerticalExtend,
	const unsigned int a_cuiRow, const unsigned int a_cuiColumns,
	const bool a_cbTriangleStrip);

bool CreateDisc(TShapes* a_oShape, const float a_cfRadius, const unsigned int a_cuiNumOfSector);

bool CreateCube(TShapes* a_oShape, const float a_cfHalfExtend);

bool CreateSphere(TShapes* a_oShape, const float a_cfRadius, const unsigned int a_cuiNumOfSlice);

bool CreateDome(TShapes* a_oShape, const float a_cfRadius, const unsigned int a_cuiNumOfSlice);

bool CreateTorus(TShapes* a_oShape, const float a_cfInnerRadius, const float a_cfOuterRadius, const unsigned int a_cuiNumOfSlice, const unsigned int a_cuiNumOfStacks);

bool CreateCylinder(TShapes* a_oShape, const float a_cfHalfExtend, const float a_cfRadius, const unsigned int a_cuiNumOfSlice);

bool CreateCone(TShapes* a_oShape, const float a_cfHalfExtend, const float a_cfRadius, const unsigned int a_cuiNumOfSlice, const unsigned int a_cuiNumOfStacks);

bool CalculateTangentBitangent(TShapes* a_oShape);

bool CopyShape(TShapes* a_oShape, const TShapes* a_oSource);

void DestroyShape(TShapes* a_oShape);

#endif //!_SHAPES_H_