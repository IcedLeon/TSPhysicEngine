#ifndef _BASESHAPE_H_
#define _BASESHAPE_H_
//Lib
#include "Shapes.h"

class BaseShape
{
protected:
	TShapes m_oShape;

public:
	BaseShape();
	BaseShape(const TShapes& a_oShape);
	virtual ~BaseShape();

	BaseShape& operator= (const BaseShape& a_oRhs);

	const TShapes& GetShape() const;
};

#endif //!_BASESHAPE_H_