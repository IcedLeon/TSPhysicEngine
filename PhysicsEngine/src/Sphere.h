#ifndef _SPHERE_H_
#define _SPHERE_H_
//Lib
#define GLM_SWIZZLE
#include "glm\glm\glm.hpp"
#include "glm\glm\ext.hpp"

class Plane;

class Sphere
{
protected:
	glm::vec4 m_vCenter;
	float m_fRadius;

public:
	Sphere();
	Sphere(const glm::vec4& a_vCenter, float a_fRadius);
	virtual ~Sphere();

	const glm::vec4& GetCenter() const;
	void SetCenter(const glm::vec4& a_fCenter);

	float GetRadius() const;
	void SetRadius(float a_fRadius);

	float Distance(const glm::vec4& a_vPoint) const;

	float Distance(const Sphere& a_oSphere) const;

	float Distance(const Plane& a_oPlane) const;
};

#endif /* SPHERE_H_ */