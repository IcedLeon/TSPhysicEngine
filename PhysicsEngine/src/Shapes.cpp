#include "Shapes.h"

static void InitShape(TShapes* a_oShape)
{
	if (!a_oShape)
		return;

	memset(a_oShape, 0, sizeof(TShapes));

	a_oShape->m_eMode = GL_TRIANGLES;
}

static bool ShapeCheck(TShapes* a_oShape)
{
	if (!a_oShape)
		return false;

	return a_oShape->m_vVertices && a_oShape->m_vNormals && a_oShape->m_vTangent && a_oShape->m_vTexCoord && a_oShape->m_puiIndices;
}

void FloatCross(float* a_fOutput, const float* a_fFirst, const float* a_fSecond)
{
	unsigned int _i;

	float _temp[3];

	_temp[0] = a_fFirst[1] * a_fSecond[2] - a_fFirst[2] - a_fSecond[1];
	_temp[1] = a_fFirst[2] * a_fSecond[0] - a_fFirst[0] - a_fSecond[2];
	_temp[2] = a_fFirst[0] * a_fSecond[1] - a_fFirst[1] - a_fSecond[0];

	for (_i = 0; _i < 3; ++_i)
		a_fOutput[_i] = _temp[_i];
}

static bool ShapeFinalizer(TShapes* a_oShape)
{
	unsigned int _i;

						// V,  N,  T,  BT, TC
	unsigned int _stride = 4 + 3 + 3 + 3 + 2;

	if (!a_oShape)
		return false;

	a_oShape->m_vBitangent = (float*) malloc(3 * a_oShape->m_uiNumOfVert * sizeof(float));
	/* For readability only */
	glm::vec4 _btan = glm::vec4(a_oShape->m_vBitangent[0], a_oShape->m_vBitangent[1], a_oShape->m_vBitangent[2], a_oShape->m_vBitangent[3]);
	glm::vec4 _tan = glm::vec4(a_oShape->m_vTangent[0], a_oShape->m_vTangent[1], a_oShape->m_vTangent[2], a_oShape->m_vTangent[3]);
	glm::vec4 _norm = glm::vec4(a_oShape->m_vNormals[0], a_oShape->m_vNormals[1], a_oShape->m_vNormals[2], a_oShape->m_vNormals[3]);

	if (!a_oShape->m_vBitangent)
		return false;

	for (_i = 0; _i < a_oShape->m_uiNumOfVert; ++_i)
	{
		FloatCross(&(a_oShape->m_vBitangent[_i * 3]), &(a_oShape->m_vNormals[_i * 3]), &(a_oShape->m_vTangent[_i * 3]));
	}

	a_oShape->a_pfAllTheAttributes = (float*)malloc(3 * a_oShape->m_uiNumOfVert * sizeof(float));

	if (!a_oShape->a_pfAllTheAttributes)
		return false;

	for (_i = 0; _i < a_oShape->m_uiNumOfVert; ++_i)
	{
		a_oShape->a_pfAllTheAttributes[_i *_stride + 0] = a_oShape->m_vVertices[_i * 4 + 0];
		a_oShape->a_pfAllTheAttributes[_i *_stride + 1] = a_oShape->m_vVertices[_i * 4 + 1];
		a_oShape->a_pfAllTheAttributes[_i *_stride + 2] = a_oShape->m_vVertices[_i * 4 + 2];
		a_oShape->a_pfAllTheAttributes[_i *_stride + 3] = a_oShape->m_vVertices[_i * 4 + 3];

		a_oShape->a_pfAllTheAttributes[_i *_stride + 4] = a_oShape->m_vNormals[_i * 3 + 0];
		a_oShape->a_pfAllTheAttributes[_i *_stride + 5] = a_oShape->m_vNormals[_i * 3 + 1];
		a_oShape->a_pfAllTheAttributes[_i *_stride + 6] = a_oShape->m_vNormals[_i * 3 + 2];

		a_oShape->a_pfAllTheAttributes[_i *_stride + 7] = a_oShape->m_vTangent[_i * 3 + 0];
		a_oShape->a_pfAllTheAttributes[_i *_stride + 8] = a_oShape->m_vTangent[_i * 3 + 1];
		a_oShape->a_pfAllTheAttributes[_i *_stride + 9] = a_oShape->m_vTangent[_i * 3 + 2];

		a_oShape->a_pfAllTheAttributes[_i *_stride + 10] = a_oShape->m_vBitangent[_i * 3 + 0];
		a_oShape->a_pfAllTheAttributes[_i *_stride + 11] = a_oShape->m_vBitangent[_i * 3 + 1];
		a_oShape->a_pfAllTheAttributes[_i *_stride + 12] = a_oShape->m_vBitangent[_i * 3 + 2];

		a_oShape->a_pfAllTheAttributes[_i *_stride + 13] = a_oShape->m_vTexCoord[_i * 2 + 0];
		a_oShape->a_pfAllTheAttributes[_i *_stride + 14] = a_oShape->m_vTexCoord[_i * 2 + 1];
	}

	return true;
}

bool CreatePlane(TShapes* a_oShape, const float a_cfHalfExtend)
{
	unsigned int _i;

	unsigned int _nOfVert = 4;
	unsigned int _nOfInd = 6;

	float _xyVert[] = { -1.0f, -1.0f, 0.0f, +1.0f, 
						+1.0f, -1.0f, 0.0f, +1.0f, 
						-1.0f, +1.0f, 0.0f, +1.0f, 
						+1.0f, +1.0f, 0.0f, +1.0f };

	float _xyNorm[] = { 0.0f, 0.0f, 1.0f, 
						0.0f, 0.0f, 1.0f, 
						0.0f, 0.0f, 1.0f, 
						0.0f, 0.0f, 1.0f };

	float _xyTan[] = { 1.0f, 0.0f, 0.0f, 
						1.0f, 0.0f, 0.0f, 
						1.0f, 0.0f, 0.0f, 
						1.0f, 0.0f, 0.0f };

	float _xyTex[] = { 0.0f, 0.0f, 
					   1.0f, 0.0f, 
					   0.0f, 1.0f, 
					   1.0f, 1.0f };

	float _xyIndx[] = { 0, 1, 2,
						1, 3, 2};

	if (!a_oShape)
		return false;

	InitShape(a_oShape);

	a_oShape->m_uiNumOfVert = _nOfVert;
	a_oShape->m_uiNumOfIndices = _nOfInd;

	a_oShape->m_vVertices	= (float*)malloc(4 * _nOfVert * sizeof(float));
	a_oShape->m_vNormals	= (float*)malloc(3 * _nOfVert * sizeof(float));
	a_oShape->m_vTangent	= (float*)malloc(3 * _nOfVert * sizeof(float));
	a_oShape->m_vTexCoord	= (float*)malloc(2 * _nOfVert * sizeof(float));
	a_oShape->m_puiIndices = (unsigned int*)malloc(_nOfInd * sizeof(unsigned int));

	if (!ShapeCheck(a_oShape))
	{
		DestroyShape(a_oShape);

		return false;
	}

	memcpy(a_oShape->m_vVertices, _xyVert, sizeof(_xyVert));
	
	for (_i = 0; _i < _nOfVert; ++_i)
	{
		a_oShape->m_vVertices[_i * 4 + 0] *= a_cfHalfExtend;
		a_oShape->m_vVertices[_i * 4 + 1] *= a_cfHalfExtend;
	}

	memcpy(a_oShape->m_vNormals, _xyNorm, sizeof(_xyNorm));

	memcpy(a_oShape->m_vTangent, _xyTan, sizeof(_xyTan));

	memcpy(a_oShape->m_vTexCoord, _xyTex, sizeof(_xyTex));

	memcpy(a_oShape->m_puiIndices, _xyIndx, sizeof(_xyIndx));

	if (!ShapeFinalizer(a_oShape))
	{
		DestroyShape(a_oShape);

		return false;
	}

	return true;
}

bool CreateRectangularPlane(TShapes* a_oShape, const float a_cfHorizintalExtend, const float a_cfVerticalExtend)
{
	unsigned int _i;

	unsigned int _nOfVert = 4;
	unsigned int _nOfInd = 6;

	float _xyVert[] = { -1.0f, -1.0f, 0.0f, +1.0f,
		+1.0f, -1.0f, 0.0f, +1.0f,
		-1.0f, +1.0f, 0.0f, +1.0f,
		+1.0f, +1.0f, 0.0f, +1.0f };

	float _xyNorm[] = { 0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f };

	float _xyTan[] = { 1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f };

	float _xyTex[] = { 0.0f, 0.0f,
		1.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f };

	float _xyIndx[] = { 0, 1, 2,
		1, 3, 2 };

	if (!a_oShape)
		return false;

	InitShape(a_oShape);

	a_oShape->m_uiNumOfVert = _nOfVert;
	a_oShape->m_uiNumOfIndices = _nOfInd;

	a_oShape->m_vVertices = (float*)malloc(4 * _nOfVert * sizeof(float));
	a_oShape->m_vNormals = (float*)malloc(3 * _nOfVert * sizeof(float));
	a_oShape->m_vTangent = (float*)malloc(3 * _nOfVert * sizeof(float));
	a_oShape->m_vTexCoord = (float*)malloc(2 * _nOfVert * sizeof(float));
	a_oShape->m_puiIndices = (unsigned int*)malloc(_nOfInd * sizeof(unsigned int));

	if (!ShapeCheck(a_oShape))
	{
		DestroyShape(a_oShape);

		return false;
	}

	memcpy(a_oShape->m_vVertices, _xyVert, sizeof(_xyVert));

	for (_i = 0; _i < _nOfVert; ++_i)
	{
		a_oShape->m_vVertices[_i * 4 + 0] *= a_cfHorizintalExtend;
		a_oShape->m_vVertices[_i * 4 + 1] *= a_cfVerticalExtend;
	}

	memcpy(a_oShape->m_vNormals, _xyNorm, sizeof(_xyNorm));

	memcpy(a_oShape->m_vTangent, _xyTan, sizeof(_xyTan));

	memcpy(a_oShape->m_vTexCoord, _xyTex, sizeof(_xyTex));

	memcpy(a_oShape->m_puiIndices, _xyIndx, sizeof(_xyIndx));

	if (!ShapeFinalizer(a_oShape))
	{
		DestroyShape(a_oShape);

		return false;
	}

	return true;
}

bool CreateRectangularGridPlane(TShapes* a_oShape,
								const float a_cfHorizintalExtend,
								const float a_cfVerticalExtend,
								const unsigned int a_cuiRow, const unsigned int a_cuiColumns,
								const bool a_cbTriangleStrip)
{
	unsigned int _i, _currRow, _currCol;

	unsigned int _nOfVert = (a_cuiRow + 1) * (a_cuiColumns + 1);
	unsigned int _nOfInd;

	float _x, _y, _s, _t;

	if (a_cbTriangleStrip)
		_nOfInd = a_cuiRow * 2 * (a_cuiColumns + 1);
	else
		_nOfInd = a_cuiRow * 6 * a_cuiColumns;

	if (a_cuiRow < 1 || a_cuiColumns < 1 || _nOfVert > MAX_VERTICES || _nOfInd > MAX_INDICES)
		return false;

	if (!a_oShape)
		return false;

	InitShape(a_oShape);

	if (a_cbTriangleStrip)
		a_oShape->m_eMode = GL_TRIANGLE_STRIP;
	else
		a_oShape->m_eMode = GL_TRIANGLES;

	a_oShape->m_uiNumOfVert = _nOfVert;
	a_oShape->m_uiNumOfIndices = _nOfInd;

	a_oShape->m_vVertices = (float*)malloc(4 * _nOfVert * sizeof(float));
	a_oShape->m_vNormals = (float*)malloc(3 * _nOfVert * sizeof(float));
	a_oShape->m_vTangent = (float*)malloc(3 * _nOfVert * sizeof(float));
	a_oShape->m_vTexCoord = (float*)malloc(2 * _nOfVert * sizeof(float));
	a_oShape->m_puiIndices = (unsigned int*)malloc(_nOfInd * sizeof(unsigned int));

	if (!ShapeCheck(a_oShape))
	{
		DestroyShape(a_oShape);
		return false;
	}

	for (_i = 0; _i < _nOfVert; ++_i)
	{
		_x = (float)(_i % (a_cuiColumns + 1)) / (float)a_cuiColumns;
		_y = 1.0f - (float)(_i / (a_cuiColumns + 1)) / (float)a_cuiRow;

		_s = _x;
		_t = _y;

		a_oShape->m_vVertices[_i * 4 + 0] = a_cfHorizintalExtend * (_x - 0.5f);
		a_oShape->m_vVertices[_i * 4 + 1] = a_cfVerticalExtend * (_y - 0.5f);
		a_oShape->m_vVertices[_i * 4 + 2] = 0.0f;
		a_oShape->m_vVertices[_i * 4 + 3] = 1.0f;

		a_oShape->m_vNormals[_i * 3 + 0] = 0.0f;
		a_oShape->m_vNormals[_i * 3 + 1] = 0.0f;
		a_oShape->m_vNormals[_i * 3 + 2] = 1.0f;

		a_oShape->m_vTangent[_i * 3 + 0] = 1.0f;
		a_oShape->m_vTangent[_i * 3 + 1] = 0.0f;
		a_oShape->m_vTangent[_i * 3 + 2] = 0.0f;

		a_oShape->m_vVertices[_i * 2 + 0] = _s;
		a_oShape->m_vVertices[_i * 2 + 1] = _t;
	}

	if (a_cbTriangleStrip)
	{
		for (_i = 0; _i < a_cuiRow * (a_cuiColumns + 1); ++_i)
		{
			_currCol = _i % (a_cuiColumns + 1);
			_currRow = _i / (a_cuiColumns + 1);

			if (_currRow == 0)
			{
				//Left to right, top to bottom
				a_oShape->m_puiIndices[_i * 2] = _currCol + _currRow * (a_cuiColumns + 1);
				a_oShape->m_puiIndices[_i * 2 + 1] = _currCol + (_currRow + 1) * (a_cuiColumns + 1);
			}
			else
			{
				//Right to left, bottom to top.
				a_oShape->m_puiIndices[_i * 2] = (a_cuiColumns - _currCol) + _currRow * (a_cuiColumns + 1);
				a_oShape->m_puiIndices[_i * 2 + 1] = (a_cuiColumns - _currCol) + _currRow * (a_cuiColumns + 1);
			}
		}
	}
	else
	{
		for (_i = 0; _i < a_cuiRow * a_cuiColumns; ++_i)
		{
			_currCol = _i % a_cuiColumns;
			_currRow = _i / a_cuiColumns;

			a_oShape->m_puiIndices[_i * 6 + 0] = _currCol + _currRow * (a_cuiColumns + 1);
			a_oShape->m_puiIndices[_i * 6 + 1] = _currCol + (_currRow + 1) * (a_cuiColumns + 1);
			a_oShape->m_puiIndices[_i * 6 + 2] = (_currCol + 1) + (_currRow + 1) * (a_cuiColumns + 1);

			a_oShape->m_puiIndices[_i * 6 + 3] = (_currCol + 1) + (_currRow + 1) * (a_cuiColumns + 1);
			a_oShape->m_puiIndices[_i * 6 + 4] = (_currCol + 1) + _currRow * (a_cuiColumns + 1);
			a_oShape->m_puiIndices[_i * 6 + 5] = _currCol + _currRow * (a_cuiColumns + 1);
		}
	}

	if (!ShapeFinalizer(a_oShape))
	{
		DestroyShape(a_oShape);
		return false;
	}

	return true;
}

bool CreateDisc(TShapes* a_oShape, const float a_cfRadius, const unsigned int a_cuiNumOfSector)
{
	unsigned int _i;

	unsigned int _numberVertices = a_cuiNumOfSector + 2;
	unsigned int _numberIndices = a_cuiNumOfSector * 3;

	float _angleStep = (2.0f * glm::pi<float>()) / ((float)a_cuiNumOfSector);

	unsigned int _indexIndices;
	unsigned int _indexCounter;

	unsigned int _vertexCounter = 0;

	if (a_cuiNumOfSector < 3 || _numberVertices > MAX_VERTICES || _numberIndices > MAX_INDICES)
	{
		return false;
	}

	if (!a_oShape)
	{
		return false;
	}

	InitShape(a_oShape);

	a_oShape->m_uiNumOfVert		= _numberVertices;
	a_oShape->m_uiNumOfIndices	= _numberIndices;

	a_oShape->m_vVertices = (float*)malloc(4 * _numberVertices * sizeof(float));
	a_oShape->m_vNormals = (float*)malloc(3 * _numberVertices * sizeof(float));
	a_oShape->m_vTangent = (float*)malloc(3 * _numberVertices * sizeof(float));
	a_oShape->m_vTexCoord = (float*)malloc(2 * _numberVertices * sizeof(float));
	a_oShape->m_puiIndices = (unsigned int*)malloc(_numberIndices * sizeof(unsigned int));

	if (!ShapeCheck(a_oShape))
	{
		DestroyShape(a_oShape);

		return false;
	}

	// Center
	a_oShape->m_vVertices[_vertexCounter * 4 + 0]	= 0.0f;
	a_oShape->m_vVertices[_vertexCounter * 4 + 1]	= 0.0f;
	a_oShape->m_vVertices[_vertexCounter * 4 + 2]	= 0.0f;
	a_oShape->m_vVertices[_vertexCounter * 4 + 3]	= 1.0f;

	a_oShape->m_vNormals[_vertexCounter * 3 + 0]	= 0.0f;
	a_oShape->m_vNormals[_vertexCounter * 3 + 1]	= 0.0f;
	a_oShape->m_vNormals[_vertexCounter * 3 + 2]	= 1.0f;

	a_oShape->m_vTangent[_vertexCounter * 3 + 0]	= 1.0f;
	a_oShape->m_vTangent[_vertexCounter * 3 + 1]	= 0.0f;
	a_oShape->m_vTangent[_vertexCounter * 3 + 2]	= 0.0f;

	a_oShape->m_vTexCoord[_vertexCounter * 2 + 0]	= 0.5f;
	a_oShape->m_vTexCoord[_vertexCounter * 2 + 1]	= 0.5f;

	_vertexCounter++;

	for (_i = 0; _i < a_cuiNumOfSector + 1; ++_i)
	{
		float _currentAngle = _angleStep * (float)_i;

		a_oShape->m_vVertices[_vertexCounter * 4 + 0] = cosf(_currentAngle) * a_cfRadius;
		a_oShape->m_vVertices[_vertexCounter * 4 + 1] = sinf(_currentAngle) * a_cfRadius;
		a_oShape->m_vVertices[_vertexCounter * 4 + 2] = 0.0f;
		a_oShape->m_vVertices[_vertexCounter * 4 + 3] = 1.0f;

		a_oShape->m_vNormals[_vertexCounter * 3 + 0] = 0.0f;
		a_oShape->m_vNormals[_vertexCounter * 3 + 1] = 0.0f;
		a_oShape->m_vNormals[_vertexCounter * 3 + 2] = 1.0f;

		a_oShape->m_vTangent[_vertexCounter * 3 + 0] = 1.0f;
		a_oShape->m_vTangent[_vertexCounter * 3 + 1] = 0.0f;
		a_oShape->m_vTangent[_vertexCounter * 3 + 2] = 0.0f;

		a_oShape->m_vTexCoord[_vertexCounter * 2 + 0] = 0.5f * cosf(_currentAngle) * 0.5f;
		a_oShape->m_vTexCoord[_vertexCounter * 2 + 1] = 0.5f * sinf(_currentAngle) * 0.5f;

		_vertexCounter++;
	}

	_indexIndices = 0;

	// Bottom
	_indexCounter = 1;

	for (_i = 0; _i < a_cuiNumOfSector; ++_i)
	{
		a_oShape->m_puiIndices[_indexIndices++] = 0;
		a_oShape->m_puiIndices[_indexIndices++] = _indexCounter;
		a_oShape->m_puiIndices[_indexIndices++] = _indexCounter + 1;

		_indexCounter++;
	}

	if (!ShapeFinalizer(a_oShape))
	{
		DestroyShape(a_oShape);

		return false;
	}

	return true;
}

bool CreateCube(TShapes* a_oShape, const float a_cfHalfExtend)
{
	unsigned int _i;

	unsigned int _numberVertices	= 24;
	unsigned int _numberIndices		= 36;

	float _cubeVertices[] = { 
		-1.0f, -1.0f, -1.0f, +1.0f, -1.0f, -1.0f, +1.0f, +1.0f, +1.0f, -1.0f, +1.0f, +1.0f, +1.0f, -1.0f, -1.0f, +1.0f,

		-1.0f, +1.0f, -1.0f, +1.0f, -1.0f, +1.0f, +1.0f, +1.0f, +1.0f, +1.0f, +1.0f, +1.0f, +1.0f, +1.0f, -1.0f, +1.0f,

		-1.0f, -1.0f, -1.0f, +1.0f, -1.0f, +1.0f, -1.0f, +1.0f, +1.0f, +1.0f, -1.0f, +1.0f, +1.0f, -1.0f, -1.0f, +1.0f,

		-1.0f, -1.0f, +1.0f, +1.0f, -1.0f, +1.0f, +1.0f, +1.0f, +1.0f, +1.0f, +1.0f, +1.0f, +1.0f, -1.0f, +1.0f, +1.0f,

		-1.0f, -1.0f, -1.0f, +1.0f, -1.0f, -1.0f, +1.0f, +1.0f, -1.0f, +1.0f, +1.0f, +1.0f, -1.0f, +1.0f, -1.0f, +1.0f,

		+1.0f, -1.0f, -1.0f, +1.0f, +1.0f, -1.0f, +1.0f, +1.0f, +1.0f, +1.0f, +1.0f, +1.0f, +1.0f, +1.0f, -1.0f, +1.0f };

	float _cubeNormals[] = { 
		0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f,

		0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f,

		0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f,

		0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f,

		-1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

		+1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f };

	float _cubeTangents[] = { 
		+1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f,

		+1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f,

		-1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

		+1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f,

		0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f, 0.0f, 0.0f, +1.0f,

		0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -1.0f };

	float _cubeTexCoords[] =
	{ 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f,

	0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f };

	unsigned int _cubeIndices[] = { 
		0, 2, 1, 0, 3, 2,
		4, 5, 6, 4, 6, 7, 
		8, 9, 10, 8, 10, 11, 
		12, 15, 14, 12, 14, 13,
		16, 17, 18, 16, 18, 19, 
		20, 23, 22, 20, 22, 21 };

	if (!a_oShape)
		return false;

	InitShape(a_oShape);

	a_oShape->m_uiNumOfVert = _numberVertices;
	a_oShape->m_uiNumOfIndices = _numberIndices;

	a_oShape->m_vVertices = (float*)malloc(4 * _numberVertices * sizeof(float));
	a_oShape->m_vNormals = (float*)malloc(3 * _numberVertices * sizeof(float));
	a_oShape->m_vTangent = (float*)malloc(3 * _numberVertices * sizeof(float));
	a_oShape->m_vTexCoord = (float*)malloc(2 * _numberVertices * sizeof(float));
	a_oShape->m_puiIndices = (unsigned int*)malloc(_numberIndices * sizeof(unsigned int));

	if (ShapeCheck(a_oShape))
	{
		DestroyShape(a_oShape);
		return false;
	}

	memcpy(a_oShape->m_vVertices, _cubeVertices, sizeof(_cubeVertices));

	for (_i = 0; _i < _numberVertices; ++_i)
	{
		a_oShape->m_vVertices[_i * 4 + 0] *= a_cfHalfExtend;
		a_oShape->m_vVertices[_i * 4 + 1] *= a_cfHalfExtend;
		a_oShape->m_vVertices[_i * 4 + 2] *= a_cfHalfExtend;
	}

	memcpy(a_oShape->m_vNormals, _cubeNormals, sizeof(_cubeNormals));
	memcpy(a_oShape->m_vTangent, _cubeTangents, sizeof(_cubeTangents));
	memcpy(a_oShape->m_vTexCoord, _cubeTexCoords, sizeof(_cubeTexCoords));
	memcpy(a_oShape->m_puiIndices, _cubeIndices, sizeof(_cubeIndices));

	if (!ShapeFinalizer(a_oShape))
	{
		DestroyShape(a_oShape);
		return false;
	}

	return true;
}

void RotateQuatOnY(glm::quat a_oQuaternion, const float a_cfAngle)
{
	float _halfAngleRad = glm::radians(a_cfAngle) * 0.5f;

	a_oQuaternion.x = 0.0f;
	a_oQuaternion.y = sinf(_halfAngleRad);
	a_oQuaternion.z = 0.0f;
	a_oQuaternion.w = cosf(_halfAngleRad);
}

void QuaternionToMatrix4(glm::mat4 a_oMatrix, glm::quat a_oQuaternion)
{
	float _x, _y, _z, _w;
	_x = a_oQuaternion.x;
	_y = a_oQuaternion.y;
	_z = a_oQuaternion.z;
	_w = a_oQuaternion.w;

	a_oMatrix[0][0] = 1.0f - 2.0f * _y * _y - 2.0f * _z * _z;
	a_oMatrix[0][1] = 2.0f * _x * _y + 2.0f * _w * _z;
	a_oMatrix[0][2] = 2.0f * _x * _z - 2.0f * _w * _y;
	a_oMatrix[0][3] = 0.0f;

	a_oMatrix[1][0] = 2.0f * _x * _y - 2.0f * _w * _z;
	a_oMatrix[1][1] = 1.0f - 2.0f * _x * _x - 2.0f * _z * _z;
	a_oMatrix[1][2] = 2.0f * _y * _z - 2.0f * _w * _y;
	a_oMatrix[1][3] = 0.0f;

	a_oMatrix[0][0] = 2.0f * _x * _z - 2.0f * _w * _y;
	a_oMatrix[0][1] = 2.0f * _y * _z + 2.0f * _w * _x;
	a_oMatrix[0][2] = 1.0f - 2.0f * _x * _x - 2.0f * _y * _y;
	a_oMatrix[0][3] = 0.0f;

	a_oMatrix[0][0] = 0.0f;
	a_oMatrix[0][1] = 0.0f;
	a_oMatrix[0][2] = 0.0f;
	a_oMatrix[0][3] = 1.0f;
}

void Mat4TimesVec3(float* a_fOutput, glm::mat4 a_fFirst, glm::vec3 a_fSecond)
{
	unsigned int _i;

	float _temp[3];

	for (_i = 0; _i < 3; ++_i)
			_temp[_i] = a_fFirst[0][_i] * a_fSecond.x + a_fFirst[1][_i] * a_fSecond.y + a_fFirst[2][_i] * a_fSecond.z;

	for (_i = 0; _i < 3; ++_i)
		a_fOutput[_i] = _temp[_i];
}

bool CreateSphere(TShapes* a_oShape, const float a_cfRadius, const unsigned int a_cuiNumOfSlice)
{
	unsigned int _i, _j;

	unsigned int _numOfParallels = a_cuiNumOfSlice / 2;
	unsigned int _numOfVertices = (_numOfParallels + 1) * (a_cuiNumOfSlice + 1);
	unsigned int _numOfIndices = _numOfParallels * a_cuiNumOfSlice * 6;

	float _angleStep = (2.0f * glm::pi<float>()) / ((float)a_cuiNumOfSlice);

	unsigned int _indxIndices;

	glm::quat _helpQuat;
	glm::vec3 _helpVec(1.0f, 0.0f, 0.0f);
	glm::mat4 _helpMat;

	if (a_cuiNumOfSlice < 3 || _numOfVertices > MAX_VERTICES || _numOfIndices > MAX_INDICES)
		return false;

	if (!a_oShape)
		return false;

	InitShape(a_oShape);

	a_oShape->m_uiNumOfVert = _numOfVertices;
	a_oShape->m_uiNumOfIndices = _numOfIndices;

	a_oShape->m_vVertices = (float*)malloc(4 * _numOfVertices * sizeof(float));
	a_oShape->m_vNormals = (float*)malloc(3 * _numOfVertices * sizeof(float));
	a_oShape->m_vTangent = (float*)malloc(3 * _numOfVertices * sizeof(float));
	a_oShape->m_vTexCoord = (float*)malloc(2 * _numOfVertices * sizeof(float));
	a_oShape->m_puiIndices = (unsigned int*)malloc(_numOfIndices * sizeof(unsigned int));
	
	if (!ShapeCheck(a_oShape))
	{
		DestroyShape(a_oShape);
		return false;
	}

	for (_i = 0; _i < _numOfParallels + 1; ++_i)
	{
		for (_j = 0; _j < a_cuiNumOfSlice + 1; ++_j)
		{
			unsigned int _vertIdx		= (_i * (a_cuiNumOfSlice + 1) + _j) * 4;
			unsigned int _normIdx		= (_i * (a_cuiNumOfSlice + 1) + _j) * 3;
			unsigned int _tanIdx		= (_i * (a_cuiNumOfSlice + 1) + _j) * 3;
			unsigned int _texCoordIdx	= (_i * (a_cuiNumOfSlice + 1) + _j) * 2;

			a_oShape->m_vVertices[_vertIdx + 0] = a_cfRadius * sinf(_angleStep * (float)_i)
				* sinf(_angleStep * (float)_j);
			a_oShape->m_vVertices[_vertIdx + 1] = a_cfRadius * cosf(_angleStep * (float)_i);
			a_oShape->m_vVertices[_vertIdx + 2] = a_cfRadius * sinf(_angleStep * (float)_i)
				* cosf(_angleStep * (float)_j);
			a_oShape->m_vVertices[_vertIdx + 3] = 1.0f;

			a_oShape->m_vNormals[_normIdx + 0] = a_oShape->m_vVertices[_vertIdx + 0] / a_cfRadius;
			a_oShape->m_vNormals[_normIdx + 1] = a_oShape->m_vVertices[_vertIdx + 1] / a_cfRadius;
			a_oShape->m_vNormals[_normIdx + 2] = a_oShape->m_vVertices[_vertIdx + 2] / a_cfRadius;

			a_oShape->m_vTexCoord[_texCoordIdx + 0] = (float)_j / (float)a_cuiNumOfSlice;
			a_oShape->m_vTexCoord[_texCoordIdx + 1] = 1.0f - (float)_i / (float)a_cuiNumOfSlice;

			//Get the tangent vector out of a quaternion.
			RotateQuatOnY(_helpQuat, 360.0f * a_oShape->m_vTexCoord[_texCoordIdx + 0]);
			QuaternionToMatrix4(_helpMat, _helpQuat);

			Mat4TimesVec3(&a_oShape->m_vTangent[_tanIdx], _helpMat, _helpVec);
		}
	}

	_indxIndices = 0;
	for (_i = 0; _i < _numOfParallels; ++_i)
	{
		for (_j = 0; _j < a_cuiNumOfSlice; ++_j)
		{
			a_oShape->m_puiIndices[_indxIndices++] = _i *(a_cuiNumOfSlice + 1) + _j;
			a_oShape->m_puiIndices[_indxIndices++] = (_i  + 1) * (a_cuiNumOfSlice + 1) + _j;
			a_oShape->m_puiIndices[_indxIndices++] = (_i + 1) * (a_cuiNumOfSlice + 1) + (_j + 1);

			a_oShape->m_puiIndices[_indxIndices++] = _i * (a_cuiNumOfSlice + 1) + _j;
			a_oShape->m_puiIndices[_indxIndices++] = (_i + 1) * (a_cuiNumOfSlice + 1) + (_j + 1);
			a_oShape->m_puiIndices[_indxIndices++] = _i * (a_cuiNumOfSlice + 1) + (_j + 1);
		}
	}

	if (!ShapeFinalizer(a_oShape))
	{
		DestroyShape(a_oShape);

		return false;
	}

	return true;
}

bool CreateDome(TShapes* a_oShape, const float a_cfRadius, const unsigned int a_cuiNumOfSlice)
{
	unsigned int _i, _j;

	unsigned int _numOfParallels = a_cuiNumOfSlice / 4;
	unsigned int _numOfVertices = (_numOfParallels + 1) * (a_cuiNumOfSlice + 1);
	unsigned int _numOfIndices = _numOfParallels * a_cuiNumOfSlice * 6;

	float _angleStep = (2.0f * glm::pi<float>()) / ((float)a_cuiNumOfSlice);

	unsigned int _indxIndices;

	glm::quat _helpQuat;
	glm::vec3 _helpVec(1.0f, 0.0f, 0.0f);
	glm::mat4 _helpMat;

	if (a_cuiNumOfSlice < 3 || _numOfVertices > MAX_VERTICES || _numOfIndices > MAX_INDICES)
		return false;

	if (!a_oShape)
		return false;

	InitShape(a_oShape);

	a_oShape->m_uiNumOfVert		= _numOfVertices;
	a_oShape->m_uiNumOfIndices	= _numOfIndices;

	a_oShape->m_vVertices = (float*)malloc(4 * _numOfVertices * sizeof(float));
	a_oShape->m_vNormals = (float*)malloc(3 * _numOfVertices * sizeof(float));
	a_oShape->m_vTangent = (float*)malloc(3 * _numOfVertices * sizeof(float));
	a_oShape->m_vTexCoord = (float*)malloc(2 * _numOfVertices * sizeof(float));
	a_oShape->m_puiIndices = (unsigned int*)malloc(_numOfIndices * sizeof(unsigned int));

	if (!ShapeCheck(a_oShape))
	{
		DestroyShape(a_oShape);
		return false;
	}

	for (_i = 0; _i < _numOfParallels + 1; ++_i)
	{
		for (_j = 0; _j < a_cuiNumOfSlice + 1; ++_j)
		{
			unsigned int _vertIdx		= (_i * (a_cuiNumOfSlice + 1) + _j) * 4;
			unsigned int _normIdx		= (_i * (a_cuiNumOfSlice + 1) + _j) * 3;
			unsigned int _tanIdx		= (_i * (a_cuiNumOfSlice + 1) + _j) * 3;
			unsigned int _texCoordIdx	= (_i * (a_cuiNumOfSlice + 1) + _j) * 2;

			a_oShape->m_vVertices[_vertIdx + 0] = a_cfRadius * sinf(_angleStep * (float)_i)
				* sinf(_angleStep * (float)_j);
			a_oShape->m_vVertices[_vertIdx + 1] = a_cfRadius * cosf(_angleStep * (float)_i);
			a_oShape->m_vVertices[_vertIdx + 2] = a_cfRadius * sinf(_angleStep * (float)_i)
				* cosf(_angleStep * (float)_j);
			a_oShape->m_vVertices[_vertIdx + 3] = 1.0f;

			a_oShape->m_vNormals[_normIdx + 0] = a_oShape->m_vVertices[_vertIdx + 0] / a_cfRadius;
			a_oShape->m_vNormals[_normIdx + 1] = a_oShape->m_vVertices[_vertIdx + 1] / a_cfRadius;
			a_oShape->m_vNormals[_normIdx + 2] = a_oShape->m_vVertices[_vertIdx + 2] / a_cfRadius;

			a_oShape->m_vTexCoord[_texCoordIdx + 0] = (float)_j / (float)a_cuiNumOfSlice;
			a_oShape->m_vTexCoord[_texCoordIdx + 1] = 1.0f - (float)_i / (float)a_cuiNumOfSlice;

			//Get the tangent vector out of a quaternion.
			RotateQuatOnY(_helpQuat, 360.0f * a_oShape->m_vTexCoord[_texCoordIdx + 0]);
			QuaternionToMatrix4(_helpMat, _helpQuat);

			Mat4TimesVec3(&a_oShape->m_vTangent[_tanIdx], _helpMat, _helpVec);
		}
	}

	_indxIndices = 0;
	for (_i = 0; _i < _numOfParallels; ++_i)
	{
		for (_j = 0; _j < a_cuiNumOfSlice; ++_j)
		{
			a_oShape->m_puiIndices[_indxIndices++] = _i * (a_cuiNumOfSlice + 1) + _j;
			a_oShape->m_puiIndices[_indxIndices++] = (_i + 1) * (a_cuiNumOfSlice + 1) + _j;
			a_oShape->m_puiIndices[_indxIndices++] = (_i + 1) * (a_cuiNumOfSlice + 1) + (_j + 1);

			a_oShape->m_puiIndices[_indxIndices++] = _i * (a_cuiNumOfSlice + 1) + _j;
			a_oShape->m_puiIndices[_indxIndices++] = (_i + 1) * (a_cuiNumOfSlice + 1) + (_j + 1);
			a_oShape->m_puiIndices[_indxIndices++] = _i * (a_cuiNumOfSlice + 1) + (_j + 1);
		}
	}

	if (!ShapeFinalizer(a_oShape))
	{
		DestroyShape(a_oShape);

		return false;
	}

	return true;
}

void RotateQuatOnZ(glm::quat a_oQuaternion, const float a_cfAngle)
{
	float _halfAngleRad = glm::radians(a_cfAngle) * 0.5f;

	a_oQuaternion.x = 0.0f;
	a_oQuaternion.y = 0.0f;
	a_oQuaternion.z = sinf(_halfAngleRad);
	a_oQuaternion.w = cosf(_halfAngleRad);
}

bool CreateTorus(TShapes* a_oShape, const float a_cfInnerRadius, const float a_cfOuterRadius,
	const unsigned int a_cuiNumOfSlice, const unsigned int a_cuiNumOfStacks)
{
	/*The parameter S and T, are parametric values of the equations, its range [0, 1].*/
	float _s = 0;
	float _t = 0;
	/*The parameter sIncr and tIncr are incremented values applied to the S and T on each
	loop to generate thetorus.*/
	float _sIncr;
	float _tIncr;
	/*Temporary storage for the precomputed sin and cos of the values.*/
	float _cos2PIs, _sin2PIs, 
		  _cos2PIt, _sin2PIt;

	unsigned int _numOfVertices;
	unsigned int _numOfIndices;

	/*To be used later in calculating tangent vectors.*/
	glm::vec3 _helpVec(0.0f, 1.0f, 0.0f);
	glm::mat4 _helpMat;
	glm::quat _helpQuat;

	/*Indices for each of the buffer type.*/
	unsigned int _vertIdx;
	unsigned int _indiIdx;
	unsigned int _normIdx;
	unsigned int _tanIdx;
	unsigned int _texCoordIdx;
	/*Loop counters*/
	unsigned int _sideCount,
				 _faceCount;

	/*Vertices Indices generation.*/
	unsigned int _v0,
				 _v1,
				 _v2,
				 _v3;

	float _torusRad = (a_cfOuterRadius - a_cfInnerRadius) / 2.0f;
	float _centerRad = a_cfOuterRadius - _torusRad;

	_numOfVertices = (a_cuiNumOfStacks + 1) * (a_cuiNumOfSlice + 1);
	_numOfIndices = a_cuiNumOfStacks * a_cuiNumOfSlice * 2 * 3; //2 triangles per face * 3 Indices per triangle.

	if (a_cuiNumOfSlice < 3 || a_cuiNumOfStacks < 3 || _numOfVertices > MAX_VERTICES || _numOfIndices > MAX_INDICES)
		return false;

	if (!a_oShape)
		return false;

	InitShape(a_oShape);

	a_oShape->m_uiNumOfVert = _numOfVertices;
	a_oShape->m_uiNumOfIndices = _numOfIndices;

	a_oShape->m_vVertices = (float*)malloc(4 * _numOfVertices * sizeof(float));
	a_oShape->m_vNormals = (float*)malloc(3 * _numOfVertices * sizeof(float));
	a_oShape->m_vTangent = (float*)malloc(3 * _numOfVertices * sizeof(float));
	a_oShape->m_vTexCoord = (float*)malloc(2 * _numOfVertices * sizeof(float));
	a_oShape->m_puiIndices = (unsigned int*)malloc(_numOfIndices * sizeof(unsigned int));

	if (!ShapeCheck(a_oShape))
	{
		DestroyShape(a_oShape);

		return false;
	}

	_sIncr = 1.0f / (float)a_cuiNumOfSlice;
	_tIncr = 1.0f / (float)a_cuiNumOfStacks;

	for (_sideCount = 0; _sideCount <= a_cuiNumOfSlice; ++_sideCount, _s += _sIncr)
	{
		/*Precompute values for S.*/
		_cos2PIs = (float)cosf(2.0f * glm::pi<float>() * _s);
		_sin2PIs = (float)sinf(2.0f * glm::pi<float>() * _s);

		_t = 0.0f;
		for (_faceCount = 0; _faceCount <= a_cuiNumOfStacks; ++_faceCount, _t += _tIncr)
		{
			/*Precompute values again for T.*/
			_cos2PIt = (float)cosf(2.0f * glm::pi<float>() * _t);
			_sin2PIt = (float)sinf(2.0f * glm::pi<float>() * _t);

			/*Vertex generation and storing them in the right position.*/
			_vertIdx = ((_sideCount * (a_cuiNumOfStacks + 1)) + _faceCount) * 4;
			a_oShape->m_vVertices[_vertIdx + 0] = (_centerRad + _torusRad * _cos2PIt) * _cos2PIs;
			a_oShape->m_vVertices[_vertIdx + 1] = (_centerRad + _torusRad * _cos2PIt) * _cos2PIs;
			a_oShape->m_vVertices[_vertIdx + 2] = _torusRad * _cos2PIt;
			a_oShape->m_vVertices[_vertIdx + 3] = 1.0f;
			/*Normal generation.
			NOTE: cos(2PIx) = cos(x) and sin(2PIx) = sin(x) so, I can use the formula
						x					y					z
			N = { cos(2PIs) cos(2PIt), sin(2PIs) cos(2PIt), sin(2PIt) }. */
			_normIdx = ((_sideCount * (a_cuiNumOfStacks + 1)) + _faceCount) * 3;
			a_oShape->m_vNormals[_normIdx + 0] = _cos2PIs * _cos2PIt;
			a_oShape->m_vNormals[_normIdx + 1] = _sin2PIs * _sin2PIt;
			a_oShape->m_vNormals[_normIdx + 2] = _sin2PIt;

			/*Texture coordinates generation.*/
			_texCoordIdx = ((_sideCount * (a_cuiNumOfStacks + 1)) + _faceCount) * 2;
			a_oShape->m_vTexCoord[_texCoordIdx + 0] = _s;
			a_oShape->m_vTexCoord[_texCoordIdx + 1] = _t;

			RotateQuatOnZ(_helpQuat, 360.0f * _s);
			QuaternionToMatrix4(_helpMat, _helpQuat);

			_tanIdx = ((_sideCount * (a_cuiNumOfStacks + 1)) + _faceCount) * 3;
			Mat4TimesVec3(&a_oShape->m_vTangent[_tanIdx], _helpMat, _helpVec);
		}
	}

	_indiIdx = 0;
	for (_sideCount = 0; _sideCount <= a_cuiNumOfSlice; ++_sideCount)
	{
		for (_faceCount = 0; _faceCount <= a_cuiNumOfStacks; ++_faceCount)
		{
			/*Get the number of the vertices for a face of the torus. They must be < numVertices.*/
			_v0 = ((_sideCount * (a_cuiNumOfStacks + 1)) + _faceCount);
			_v1 = (((_sideCount + 1) * (a_cuiNumOfStacks + 1)) + _faceCount);
			_v2 = (((_sideCount + 1) * (a_cuiNumOfStacks + 1)) + (_faceCount + 1));
			_v3 = ((_sideCount * (a_cuiNumOfStacks + 1)) + (_faceCount + 1));
			/*First triangle of the face, counter clock wise winding.*/
			a_oShape->m_puiIndices[_indiIdx++] = _v0;
			a_oShape->m_puiIndices[_indiIdx++] = _v1;
			a_oShape->m_puiIndices[_indiIdx++] = _v2;
			/*Second triangle of the face, counter clock wise winding.*/
			a_oShape->m_puiIndices[_indiIdx++] = _v0;
			a_oShape->m_puiIndices[_indiIdx++] = _v2;
			a_oShape->m_puiIndices[_indiIdx++] = _v3;
		}
	}

	if (!ShapeFinalizer(a_oShape))
	{
		DestroyShape(a_oShape);

		return false;
	}

	return true;
}

bool CreateCylinder(TShapes* a_oShape, const float a_cfHalfExtend, const float a_cfRadius, const unsigned int a_cuiNumOfSlice)
{
	unsigned int _i, _j;

	unsigned int _numOfVertices = (a_cuiNumOfSlice + 2) * 2 + (a_cuiNumOfSlice + 1) * 2;
	unsigned int _numOfIndices = a_cuiNumOfSlice * 3 * 2 + a_cuiNumOfSlice * 6;

	float _angleStep = (2.0f * glm::pi<float>()) / (float)a_cuiNumOfSlice;

	unsigned int _indexIndices;
	unsigned int _indexCenter;
	unsigned int _indexCounter;

	unsigned int _vertexCounter = 0;

	if (a_cuiNumOfSlice < 3 || _numOfVertices > MAX_VERTICES || _numOfIndices > MAX_INDICES)
		return false;

	if (!a_oShape)
		return false;

	InitShape(a_oShape);

	a_oShape->m_uiNumOfVert = _numOfVertices;
	a_oShape->m_uiNumOfIndices = _numOfIndices;

	a_oShape->m_vVertices = (float*)malloc(4 * _numOfVertices * sizeof(float));
	a_oShape->m_vNormals = (float*)malloc(3 * _numOfVertices * sizeof(float));
	a_oShape->m_vTangent = (float*)malloc(3 * _numOfVertices * sizeof(float));
	a_oShape->m_vTexCoord = (float*)malloc(2 * _numOfVertices * sizeof(float));
	a_oShape->m_puiIndices = (unsigned int*)malloc(_numOfIndices * sizeof(unsigned int));

	if (!ShapeCheck(a_oShape))
	{
		DestroyShape(a_oShape);

		return false;
	}

	/*Center bottom*/
	a_oShape->m_vVertices[_vertexCounter * 4 + 0] = 0.0f;
	a_oShape->m_vVertices[_vertexCounter * 4 + 1] = -a_cfHalfExtend;
	a_oShape->m_vVertices[_vertexCounter * 4 + 2] = 0.0f;
	a_oShape->m_vVertices[_vertexCounter * 4 + 3] = 1.0f;

	a_oShape->m_vNormals[_vertexCounter * 3 + 0] = 0.0f;
	a_oShape->m_vNormals[_vertexCounter * 3 + 1] = -1.0f;
	a_oShape->m_vNormals[_vertexCounter * 3 + 2] = 0.0f;

	a_oShape->m_vTangent[_vertexCounter * 3 + 0] = 0.0f;
	a_oShape->m_vTangent[_vertexCounter * 3 + 1] = 0.0f;
	a_oShape->m_vTangent[_vertexCounter * 3 + 2] = 1.0f;

	a_oShape->m_vVertices[_vertexCounter * 2 + 0] = 0.0f;
	a_oShape->m_vVertices[_vertexCounter * 2 + 1] = 0.0f;

	_vertexCounter++;
	
	/*bottom*/
	for (_i = 0; _i < a_cuiNumOfSlice + 1; ++_i)
	{
		float _currTheta = _angleStep * (float)_i;

		a_oShape->m_vVertices[_vertexCounter * 4 + 0] = cosf(_currTheta) * a_cfRadius;
		a_oShape->m_vVertices[_vertexCounter * 4 + 1] = -a_cfHalfExtend;
		a_oShape->m_vVertices[_vertexCounter * 4 + 2] = -sinf(_currTheta) * a_cfRadius;
		a_oShape->m_vVertices[_vertexCounter * 4 + 3] = 1.0f;

		a_oShape->m_vNormals[_vertexCounter * 3 + 0] = 0.0f;
		a_oShape->m_vNormals[_vertexCounter * 3 + 1] = -1.0f;
		a_oShape->m_vNormals[_vertexCounter * 3 + 2] = 0.0f;

		a_oShape->m_vTangent[_vertexCounter * 3 + 0] = sinf(_currTheta);
		a_oShape->m_vTangent[_vertexCounter * 3 + 1] = 0.0f;
		a_oShape->m_vTangent[_vertexCounter * 3 + 2] = cosf(_currTheta);

		a_oShape->m_vVertices[_vertexCounter * 2 + 0] = 0.0f;
		a_oShape->m_vVertices[_vertexCounter * 2 + 1] = 0.0f;

		_vertexCounter++;
	}

	/*center top*/
	a_oShape->m_vVertices[_vertexCounter * 4 + 0] = 0.0f;
	a_oShape->m_vVertices[_vertexCounter * 4 + 1] = a_cfHalfExtend;
	a_oShape->m_vVertices[_vertexCounter * 4 + 2] = 0.0f;
	a_oShape->m_vVertices[_vertexCounter * 4 + 3] = 1.0f;

	a_oShape->m_vNormals[_vertexCounter * 3 + 0] = 0.0f;
	a_oShape->m_vNormals[_vertexCounter * 3 + 1] = 1.0f;
	a_oShape->m_vNormals[_vertexCounter * 3 + 2] = 0.0f;

	a_oShape->m_vTangent[_vertexCounter * 3 + 0] = 0.0f;
	a_oShape->m_vTangent[_vertexCounter * 3 + 1] = 0.0f;
	a_oShape->m_vTangent[_vertexCounter * 3 + 2] = -1.0f;

	a_oShape->m_vVertices[_vertexCounter * 2 + 0] = 1.0f;
	a_oShape->m_vVertices[_vertexCounter * 2 + 1] = 1.0f;

	_vertexCounter++;

	/*top*/
	for (_i = 0; _i < a_cuiNumOfSlice + 1; ++_i)
	{
		float _currTheta = _angleStep * (float)_i;

		a_oShape->m_vVertices[_vertexCounter * 4 + 0] = cosf(_currTheta) * a_cfRadius;
		a_oShape->m_vVertices[_vertexCounter * 4 + 1] = a_cfHalfExtend;
		a_oShape->m_vVertices[_vertexCounter * 4 + 2] = -sinf(_currTheta) * a_cfRadius;
		a_oShape->m_vVertices[_vertexCounter * 4 + 3] = 1.0f;

		a_oShape->m_vNormals[_vertexCounter * 3 + 0] = 0.0f;
		a_oShape->m_vNormals[_vertexCounter * 3 + 1] = 1.0f;
		a_oShape->m_vNormals[_vertexCounter * 3 + 2] = 0.0f;

		a_oShape->m_vTangent[_vertexCounter * 3 + 0] = -sinf(_currTheta);
		a_oShape->m_vTangent[_vertexCounter * 3 + 1] = 0.0f;
		a_oShape->m_vTangent[_vertexCounter * 3 + 2] = -cosf(_currTheta);

		a_oShape->m_vVertices[_vertexCounter * 2 + 0] = 1.0f;
		a_oShape->m_vVertices[_vertexCounter * 2 + 1] = 1.0f;

		_vertexCounter++;
	}

	for (_i = 0; _i < a_cuiNumOfSlice + 1; ++_i)
	{
		float _currTheta = _angleStep * (float)_i;

		float _sign = -1.0f;
		
		for (_j = 0; _j < 2; ++_j)
		{

			a_oShape->m_vVertices[_vertexCounter * 4 + 0] = cosf(_currTheta) * a_cfRadius;
			a_oShape->m_vVertices[_vertexCounter * 4 + 1] = a_cfHalfExtend * _sign;
			a_oShape->m_vVertices[_vertexCounter * 4 + 2] = -sinf(_currTheta) * a_cfRadius;
			a_oShape->m_vVertices[_vertexCounter * 4 + 3] = 1.0f;

			a_oShape->m_vNormals[_vertexCounter * 3 + 0] = cosf(_currTheta);
			a_oShape->m_vNormals[_vertexCounter * 3 + 1] = 1.0f;
			a_oShape->m_vNormals[_vertexCounter * 3 + 2] = -sinf(_currTheta);

			a_oShape->m_vTangent[_vertexCounter * 3 + 0] = -sinf(_currTheta);
			a_oShape->m_vTangent[_vertexCounter * 3 + 1] = 0.0f;
			a_oShape->m_vTangent[_vertexCounter * 3 + 2] = -cosf(_currTheta);

			a_oShape->m_vVertices[_vertexCounter * 2 + 0] = (float)_i / (float)a_cuiNumOfSlice;
			a_oShape->m_vVertices[_vertexCounter * 2 + 1] = (_sign + 1.0f) / 2.0f;

			_vertexCounter++;

			_sign = 1.0f;
		}
	}

	_indexIndices = 0;

	_indexCenter = 0;
	_indexCounter = 1;

	for (_i = 0; _i < a_cuiNumOfSlice; ++_i)
	{
		a_oShape->m_puiIndices[_indexIndices++] = _indexCenter;
		a_oShape->m_puiIndices[_indexIndices++] = _indexCounter + 1;
		a_oShape->m_puiIndices[_indexIndices++] = _indexCounter;

		_indexIndices++;
	}
	_indexCounter++;

	/*top*/
	_indexCenter = _indexCounter;
	_indexCounter++;

	for (_i = 0; _i < a_cuiNumOfSlice; ++_i)
	{
		a_oShape->m_puiIndices[_indexIndices++] = _indexCenter;
		a_oShape->m_puiIndices[_indexIndices++] = _indexCounter;
		a_oShape->m_puiIndices[_indexIndices++] = _indexCounter + 1;

		_indexCounter++;
	}
	_indexCounter++;

	/*Sides*/
	for (_i = 0; _i < a_cuiNumOfSlice; ++_i)
	{
		a_oShape->m_puiIndices[_indexIndices++] = _indexCounter;
		a_oShape->m_puiIndices[_indexIndices++] = _indexCounter + 2;
		a_oShape->m_puiIndices[_indexIndices++] = _indexCounter + 1;

		a_oShape->m_puiIndices[_indexIndices++] = _indexCounter + 2;
		a_oShape->m_puiIndices[_indexIndices++] = _indexCounter + 3;
		a_oShape->m_puiIndices[_indexIndices++] = _indexCounter + 1;

		_indexCounter += 2;
	}

	if (!ShapeFinalizer(a_oShape))
	{
		DestroyShape(a_oShape);

		return false;
	}

	return true;
}

bool CreateCone(TShapes* a_oShape, const float a_cfHalfExtend, const float a_cfRadius, const unsigned int a_cuiNumOfSlice, const unsigned int a_cuiNumOfStacks)
{
	unsigned int _i, _j;

	unsigned int _numOfVertices = (a_cuiNumOfSlice + 2) + (a_cuiNumOfSlice + 1) * (a_cuiNumOfStacks + 1);
	unsigned int _numOfIndices = a_cuiNumOfSlice * 3 + a_cuiNumOfSlice * 6 * a_cuiNumOfStacks;

	float _angleStep = (2.0f * glm::pi<float>()) / (float)a_cuiNumOfSlice;

	unsigned int _indexIndices;
	unsigned int _indexCenter;
	unsigned int _indexCounter;

	unsigned int _vertexCounter = 0;

	float _h = 2.0f * a_cfHalfExtend;
	float _r = a_cfRadius;
	float _l = sqrtf(_h * _h + _r * _r);

	if (a_cuiNumOfSlice < 3 || _numOfVertices > MAX_VERTICES || _numOfIndices > MAX_INDICES)
		return false;

	if (!a_oShape)
		return false;

	InitShape(a_oShape);

	a_oShape->m_uiNumOfVert = _numOfVertices;
	a_oShape->m_uiNumOfIndices = _numOfIndices;

	a_oShape->m_vVertices = (float*)malloc(4 * _numOfVertices * sizeof(float));
	a_oShape->m_vNormals = (float*)malloc(3 * _numOfVertices * sizeof(float));
	a_oShape->m_vTangent = (float*)malloc(3 * _numOfVertices * sizeof(float));
	a_oShape->m_vTexCoord = (float*)malloc(2 * _numOfVertices * sizeof(float));
	a_oShape->m_puiIndices = (unsigned int*)malloc(_numOfIndices * sizeof(unsigned int));

	if (!ShapeCheck(a_oShape))
	{
		DestroyShape(a_oShape);

		return false;
	}

	/* Center bottom.*/
	a_oShape->m_vVertices[_vertexCounter * 4 + 0] = 0.0f;
	a_oShape->m_vVertices[_vertexCounter * 4 + 1] = -a_cfHalfExtend;
	a_oShape->m_vVertices[_vertexCounter * 4 + 2] = 0.0f;
	a_oShape->m_vVertices[_vertexCounter * 4 + 3] = 1.0f;

	a_oShape->m_vNormals[_vertexCounter * 3 + 0] = 0.0f;
	a_oShape->m_vNormals[_vertexCounter * 3 + 1] = -1.0f;
	a_oShape->m_vNormals[_vertexCounter * 3 + 2] = 0.0f;

	a_oShape->m_vVertices[_vertexCounter * 3 + 0] = 0.0f;
	a_oShape->m_vVertices[_vertexCounter * 3 + 1] = 0.0f;
	a_oShape->m_vVertices[_vertexCounter * 3 + 2] = 1.0f;

	a_oShape->m_vVertices[_vertexCounter * 2 + 0] = 0.0f;
	a_oShape->m_vVertices[_vertexCounter * 2 + 1] = 0.0f;

	_vertexCounter++;

	/*bottom*/
	for (_i = 0; _i < a_cuiNumOfSlice + 1; ++_i)
	{
		float _currTheta = _angleStep * (float)_i;

		/* Center bottom.*/
		a_oShape->m_vVertices[_vertexCounter * 4 + 0] = cosf(_currTheta) * a_cfRadius;
		a_oShape->m_vVertices[_vertexCounter * 4 + 1] = -a_cfHalfExtend;
		a_oShape->m_vVertices[_vertexCounter * 4 + 2] = -sinf(_currTheta) * a_cfRadius;
		a_oShape->m_vVertices[_vertexCounter * 4 + 3] = 1.0f;

		a_oShape->m_vNormals[_vertexCounter * 3 + 0] = 0.0f;
		a_oShape->m_vNormals[_vertexCounter * 3 + 1] = -1.0f;
		a_oShape->m_vNormals[_vertexCounter * 3 + 2] = 0.0f;

		a_oShape->m_vVertices[_vertexCounter * 3 + 0] = sinf(_currTheta);
		a_oShape->m_vVertices[_vertexCounter * 3 + 1] = 0.0f;
		a_oShape->m_vVertices[_vertexCounter * 3 + 2] = cosf(_currTheta);

		a_oShape->m_vVertices[_vertexCounter * 2 + 0] = 0.0f;
		a_oShape->m_vVertices[_vertexCounter * 2 + 1] = 0.0f;

		_vertexCounter++;
	}

	for (_j = 0; _j < a_cuiNumOfStacks; ++_j)
	{
		float _lvl = (float)_j / (float)a_cuiNumOfStacks;
		for (_i = 0; _i < a_cuiNumOfSlice + 1; ++_i)
		{
			float _currTheta = _angleStep * (float)_i;

			a_oShape->m_vVertices[_vertexCounter * 4 + 0] = cosf(_currTheta) * a_cfRadius * (1.0f - _lvl);
			a_oShape->m_vVertices[_vertexCounter * 4 + 1] = -a_cfHalfExtend + 2.0f * a_cfHalfExtend * _lvl;
			a_oShape->m_vVertices[_vertexCounter * 4 + 2] = -sinf(_currTheta) * a_cfRadius * (1.0f - _lvl);
			a_oShape->m_vVertices[_vertexCounter * 4 + 3] = 1.0f;

			a_oShape->m_vNormals[_vertexCounter * 3 + 0] = _h / _l * cosf(_currTheta);
			a_oShape->m_vNormals[_vertexCounter * 3 + 1] = _h / _l;
			a_oShape->m_vNormals[_vertexCounter * 3 + 2] = _h / _l * -sinf(_currTheta);

			a_oShape->m_vVertices[_vertexCounter * 3 + 0] = -sinf(_currTheta);
			a_oShape->m_vVertices[_vertexCounter * 3 + 1] = 0.0f;
			a_oShape->m_vVertices[_vertexCounter * 3 + 2] = -cosf(_currTheta);

			a_oShape->m_vVertices[_vertexCounter * 2 + 0] = (float)_i / (float)a_cuiNumOfSlice;
			a_oShape->m_vVertices[_vertexCounter * 2 + 1] = _lvl;

			_vertexCounter++;
		}
	}

	_indexIndices = 0;
	/*bottom*/
	_indexCenter = 0;
	_indexCounter = 1;

	for (_i = 0; _i < a_cuiNumOfSlice; ++_i)
	{ 
		a_oShape->m_puiIndices[_indexIndices++] = _indexCenter;
		a_oShape->m_puiIndices[_indexIndices++] = _indexCounter + 1;
		a_oShape->m_puiIndices[_indexIndices++] = _indexCenter;

		_indexCounter++;
	}
	_indexCounter++;

	/*Sides*/
	for (_j = 0; _j < a_cuiNumOfStacks; ++_j)
	{
		for (_i = 0; _i < a_cuiNumOfSlice; ++_i)
		{
			a_oShape->m_puiIndices[_indexIndices++] = _indexCounter;
			a_oShape->m_puiIndices[_indexIndices++] = _indexCounter + 1;
			a_oShape->m_puiIndices[_indexIndices++] = _indexCenter + a_cuiNumOfSlice + 1;

			a_oShape->m_puiIndices[_indexIndices++] = _indexCounter + 1;
			a_oShape->m_puiIndices[_indexIndices++] = _indexCenter + a_cuiNumOfSlice + 2;
			a_oShape->m_puiIndices[_indexIndices++] = _indexCenter + a_cuiNumOfSlice + 1;

			_indexCounter++;
		}
		_indexCounter++;
	}

	if (!ShapeFinalizer(a_oShape))
	{
		DestroyShape(a_oShape);

		return false;
	}

	return true;
}

void Vec4SubVec4(float* a_fResult, const float* a_cfPoint0, const float* a_cfPoint1)
{
	a_fResult[0] = a_cfPoint0[0] - a_cfPoint1[0];
	a_fResult[1] = a_cfPoint0[1] - a_cfPoint1[1];
	a_fResult[2] = a_cfPoint0[2] - a_cfPoint1[2];
}

bool NormalizeVec3f(float* a_pfVector)
{
	unsigned int _i;

	float _length = sqrtf(a_pfVector[0] * a_pfVector[0] + a_pfVector[1] * a_pfVector[1] + a_pfVector[2] * a_pfVector[2]);

	if (_length == 0.0f)
		return false;

	for (_i = 0; _i < 3; ++_i)
		a_pfVector[_i] /= _length;

	return true;
}

bool CalculateTangentBitangent(TShapes* a_oShape)
{
	unsigned int _i;

	if (!a_oShape || !a_oShape->m_vVertices || !a_oShape->m_vTexCoord || a_oShape->m_eMode != GL_TRIANGLES)
	{
		return false;
	}

	if (!a_oShape->m_vTangent)
	{
		a_oShape->m_vTangent = (float*)malloc(3 * a_oShape->m_uiNumOfVert * sizeof(float));

		if (!a_oShape->m_vTangent)
			return false;
	}

	if (!a_oShape->m_vBitangent)
	{
		a_oShape->m_vBitangent = (float*)malloc(3 * a_oShape->m_uiNumOfVert * sizeof(float));

		if (!a_oShape->m_vBitangent)
			return false;
	}

	/*Resetting all the tangents to be Null*/
	for (_i = 0; _i < a_oShape->m_uiNumOfVert; ++_i)
	{
		a_oShape->m_vTangent[_i * 3] = 0.0f;
		a_oShape->m_vTangent[_i * 3 + 1] = 0.0f;
		a_oShape->m_vTangent[_i * 3 + 2] = 0.0f;

		a_oShape->m_vBitangent[_i * 3] = 0.0f;
		a_oShape->m_vBitangent[_i * 3 + 1] = 0.0f;
		a_oShape->m_vBitangent[_i * 3 + 2] = 0.0f;
	}

	if (a_oShape->m_uiNumOfIndices > 0)
	{
		float _s1,
			  _t1,
			  _s2,
			  _t2;

		float _q1[4];
		float _q2[4];

		float _tangent[3];
		float _bitangent[3];
		float _scalar;

		for (_i = 0; _i < a_oShape->m_uiNumOfIndices; _i += 3)
		{
			_s1 = a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i + 1]] 
				- a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i]];
			_t1 = a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i + 1] + 1]
				- a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i] + 1];
			_s2 = a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i + 2]]
				- a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i]];
			_t2 = a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i + 2] + 1]
				- a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i] + 1];

			_scalar = 1.0f / (_s1 * _t2 - _s2 * _t1);

			Vec4SubVec4(_q1, &a_oShape->m_vVertices[4 * a_oShape->m_puiIndices[_i + 1]], &a_oShape->m_vVertices[4 * a_oShape->m_puiIndices[_i]]);
			_q1[3] = 1.0f;

			Vec4SubVec4(_q2, &a_oShape->m_vVertices[4 * a_oShape->m_puiIndices[_i + 2]], &a_oShape->m_vVertices[4 * a_oShape->m_puiIndices[_i]]);
			_q2[3] = 1.0f;

			_tangent[0] = _scalar * (_t2 * _q1[0] - _t1 * _q2[0]);
			_tangent[1] = _scalar * (_t2 * _q1[1] - _t1 * _q2[1]);
			_tangent[2] = _scalar * (_t2 * _q1[2] - _t1 * _q2[2]);

			_bitangent[0] = _scalar * (-_s2 * _q1[0] + _s1 * _q2[0]);
			_bitangent[1] = _scalar * (-_s2 * _q1[1] + _s1 * _q2[1]);
			_bitangent[2] = _scalar * (-_s2 * _q1[2] + _s1 * _q2[2]);

			glm::normalize(glm::vec3(_tangent[0], _tangent[1], _tangent[2]));
			glm::normalize(glm::vec3(_bitangent[0], _bitangent[1], _bitangent[2]));

			a_oShape->m_vTangent[3 * a_oShape->m_puiIndices[_i]]			+= _tangent[0];
			a_oShape->m_vTangent[3 * a_oShape->m_puiIndices[_i + 1] + 1]	+= _tangent[1];
			a_oShape->m_vTangent[3 * a_oShape->m_puiIndices[_i + 2] + 2]	+= _tangent[2];

			a_oShape->m_vTangent[3 * a_oShape->m_puiIndices[_i + 1]]		+= _tangent[0];
			a_oShape->m_vTangent[3 * a_oShape->m_puiIndices[_i + 1] + 1]	+= _tangent[1];
			a_oShape->m_vTangent[3 * a_oShape->m_puiIndices[_i + 1] + 2]	+= _tangent[2];

			a_oShape->m_vTangent[3 * a_oShape->m_puiIndices[_i + 2]]		+= _tangent[0];
			a_oShape->m_vTangent[3 * a_oShape->m_puiIndices[_i + 2] + 1]	+= _tangent[1];
			a_oShape->m_vTangent[3 * a_oShape->m_puiIndices[_i + 2] + 2]	+= _tangent[2];

			a_oShape->m_vBitangent[3 * a_oShape->m_puiIndices[_i]]			+= _bitangent[0];
			a_oShape->m_vBitangent[3 * a_oShape->m_puiIndices[_i] + 1]		+= _bitangent[1];
			a_oShape->m_vBitangent[3 * a_oShape->m_puiIndices[_i] + 2]		+= _bitangent[2];

			a_oShape->m_vBitangent[3 * a_oShape->m_puiIndices[_i + 1]]		+= _bitangent[0];
			a_oShape->m_vBitangent[3 * a_oShape->m_puiIndices[_i + 1] + 1]	+= _bitangent[1];
			a_oShape->m_vBitangent[3 * a_oShape->m_puiIndices[_i + 1] + 2]	+= _bitangent[2];

			a_oShape->m_vBitangent[3 * a_oShape->m_puiIndices[_i + 2]]		+= _bitangent[0];
			a_oShape->m_vBitangent[3 * a_oShape->m_puiIndices[_i + 2] + 1]	+= _bitangent[1];
			a_oShape->m_vBitangent[3 * a_oShape->m_puiIndices[_i + 2] + 2]	+= _bitangent[2];
		}
	}
	else
	{
		float _s1,
			  _t1,
			  _s2,
			  _t2;

		float _q1[4];
		float _q2[4];

		float _tangent[3];
		float _bitangent[3];
		float _scalar;

		for (_i = 0; _i < a_oShape->m_uiNumOfVert; _i += 3)
		{
			_s1 = a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i + 1]] 
				- a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i]];

			_t1 = a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i + 1] + 1] 
				- a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i] + 1];

			_s2 = a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i + 2]] 
				- a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i]];

			_t2 = a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i + 2] + 1] 
				- a_oShape->m_vTexCoord[2 * a_oShape->m_puiIndices[_i] + 1];

			_scalar = 1.0f / (_s1 * _t2 - _s2 * _t1);

			Vec4SubVec4(_q1, &a_oShape->m_vVertices[4 * (_i + 1)], &a_oShape->m_vVertices[4 * _i]);
			_q1[3] = 1.0f;
			Vec4SubVec4(_q2, &a_oShape->m_vVertices[4 * (_i + 2)], &a_oShape->m_vVertices[4 * _i]);
			_q2[3] = 1.0f;

			_tangent[0] = _scalar * (_t2 * _q1[0] - _t1 * _q2[0]);
			_tangent[1] = _scalar * (_t2 * _q1[1] - _t1 * _q2[1]);
			_tangent[2] = _scalar * (_t2 * _q1[2] - _t1 * _q2[2]);

			_bitangent[0] = _scalar * (-_s2 * _q1[0] + _s1 * _q2[0]);
			_bitangent[1] = _scalar * (-_s2 * _q1[1] + _s1 * _q2[1]);
			_bitangent[2] = _scalar * (-_s2 * _q1[2] + _s1 * _q2[2]);

			glm::normalize(glm::vec3(_tangent[0], _tangent[1], _tangent[2]));
			glm::normalize(glm::vec3(_bitangent[0], _bitangent[1], _bitangent[2]));

			a_oShape->m_vTangent[3 * _i]	 += _tangent[0];
			a_oShape->m_vTangent[3 * _i + 1] += _tangent[1];
			a_oShape->m_vTangent[3 * _i + 2] += _tangent[2];

			a_oShape->m_vTangent[3 * (_i + 1)]	   += _tangent[0];
			a_oShape->m_vTangent[3 * (_i + 1) + 1] += _tangent[1];
			a_oShape->m_vTangent[3 * (_i + 1) + 2] += _tangent[2];

			a_oShape->m_vTangent[3 * (_i + 2)]	   += _tangent[0];
			a_oShape->m_vTangent[3 * (_i + 2) + 1] += _tangent[1];
			a_oShape->m_vTangent[3 * (_i + 2) + 2] += _tangent[2];

			a_oShape->m_vBitangent[3 * _i]		+= _bitangent[0];
			a_oShape->m_vBitangent[3 * _i + 1]	+= _bitangent[1];
			a_oShape->m_vBitangent[3 * _i + 2]	+= _bitangent[2];

			a_oShape->m_vBitangent[3 * (_i + 1)]	 += _bitangent[0];
			a_oShape->m_vBitangent[3 * (_i + 1) + 1] += _bitangent[1];
			a_oShape->m_vBitangent[3 * (_i + 1) + 2] += _bitangent[2];

			a_oShape->m_vBitangent[3 * (_i + 2)]	 += _bitangent[0];
			a_oShape->m_vBitangent[3 * (_i + 2) + 1] += _bitangent[1];
			a_oShape->m_vBitangent[3 * (_i + 2) + 2] += _bitangent[2];

		}
	}
	/*Normalize, as several triangles have added a vector.*/
	for (_i = 0; _i < a_oShape->m_uiNumOfVert; ++_i)
	{
		NormalizeVec3f(&(a_oShape->m_vTangent[_i * 3]));
		NormalizeVec3f(&(a_oShape->m_vBitangent[_i * 3]));
	}

	return true;
}

bool CopyShape(TShapes* a_oShape, const TShapes* a_oSource)
{
	unsigned int _stride = 4 + 3 + 3 + 3 + 2;

	if (!a_oShape || !a_oSource)
		return false;

	InitShape(a_oShape);

	a_oShape->m_uiNumOfVert = a_oSource->m_uiNumOfVert;
	a_oShape->m_uiNumOfIndices = a_oSource->m_uiNumOfIndices;
	a_oShape->m_eMode = a_oSource->m_eMode;

	if (a_oSource->m_vVertices)
	{
		a_oShape->m_vVertices = (float*)malloc(4 * a_oSource->m_uiNumOfVert * sizeof(float));

		if (!a_oShape->m_vVertices)
		{
			DestroyShape(a_oShape);

			return false;
		}

		memcpy(a_oShape->m_vVertices, a_oSource->m_vVertices, 4 * a_oSource->m_uiNumOfVert * sizeof(float));
	}

	if (a_oSource->m_vNormals)
	{
		a_oShape->m_vNormals = (float*)malloc(3 * a_oSource->m_uiNumOfVert * sizeof(float));

		if (!a_oShape->m_vNormals)
		{
			DestroyShape(a_oShape);

			return false;
		}

		memcpy(a_oShape->m_vNormals, a_oSource->m_vNormals, 3 * a_oSource->m_uiNumOfVert * sizeof(float));
	}

	if (a_oSource->m_vTangent)
	{
		a_oShape->m_vTangent = (float*)malloc(3 * a_oSource->m_uiNumOfVert * sizeof(float));

		if (!a_oShape->m_vTangent)
		{
			DestroyShape(a_oShape);

			return false;
		}

		memcpy(a_oShape->m_vTangent, a_oSource->m_vTangent, 3 * a_oSource->m_uiNumOfVert * sizeof(float));
	}

	if (a_oSource->m_vBitangent)
	{
		a_oShape->m_vBitangent = (float*)malloc(3 * a_oSource->m_uiNumOfVert * sizeof(float));

		if (!a_oShape->m_vBitangent)
		{
			DestroyShape(a_oShape);

			return false;
		}

		memcpy(a_oShape->m_vBitangent, a_oSource->m_vBitangent, 3 * a_oSource->m_uiNumOfVert * sizeof(float));
	}

	if (a_oSource->m_vTexCoord)
	{
		a_oShape->m_vTexCoord = (float*)malloc(2 * a_oSource->m_uiNumOfVert * sizeof(float));

		if (!a_oShape->m_vTexCoord)
		{
			DestroyShape(a_oShape);

			return false;
		}

		memcpy(a_oShape->m_vTexCoord, a_oSource->m_vTexCoord, 2 * a_oSource->m_uiNumOfVert * sizeof(float));
	}

	if (a_oSource->a_pfAllTheAttributes)
	{
		a_oShape->a_pfAllTheAttributes = (float*)malloc(_stride * a_oSource->m_uiNumOfVert * sizeof(float));

		if (!a_oShape->a_pfAllTheAttributes)
		{
			DestroyShape(a_oShape);

			return false;
		}

		memcpy(a_oShape->a_pfAllTheAttributes, a_oSource->a_pfAllTheAttributes, _stride * a_oSource->m_uiNumOfVert * sizeof(float));
	}

	if (a_oSource->m_puiIndices)
	{
		a_oShape->m_puiIndices = (unsigned int*)malloc(a_oSource->m_uiNumOfIndices * sizeof(unsigned int));

		if (!a_oShape->a_pfAllTheAttributes)
		{
			DestroyShape(a_oShape);

			return false;
		}

		memcpy(a_oShape->m_puiIndices, a_oSource->m_puiIndices, a_oSource->m_uiNumOfIndices * sizeof(unsigned int));
	}

	return true;
}

void DestroyShape(TShapes* a_oShape)
{
	if (!a_oShape)
		return;

	if (a_oShape->m_vVertices)
	{
		free(a_oShape->m_vVertices);
		
		a_oShape->m_vVertices = nullptr;
	}

	if (a_oShape->m_vNormals)
	{
		free(a_oShape->m_vNormals);

		a_oShape->m_vNormals = nullptr;
	}

	if (a_oShape->m_vTangent)
	{
		free(a_oShape->m_vTangent);

		a_oShape->m_vTangent = nullptr;
	}

	if (a_oShape->m_vBitangent)
	{
		free(a_oShape->m_vBitangent);

		a_oShape->m_vBitangent = nullptr;
	}

	if (a_oShape->m_vTexCoord)
	{
		free(a_oShape->m_vTexCoord);

		a_oShape->m_vTexCoord = nullptr;
	}

	if (a_oShape->a_pfAllTheAttributes)
	{
		free(a_oShape->a_pfAllTheAttributes);

		a_oShape->a_pfAllTheAttributes = nullptr;
	}

	if (a_oShape->m_puiIndices)
	{
		free(a_oShape->m_puiIndices);

		a_oShape->m_puiIndices = nullptr;
	}

	a_oShape->m_uiNumOfVert = NULL;
	a_oShape->m_uiNumOfIndices = NULL;
	a_oShape->m_eMode = NULL;
}