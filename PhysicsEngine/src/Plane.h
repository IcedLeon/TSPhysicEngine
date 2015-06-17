#ifndef _PLANE_H_
#define _PLANE_H_
/* Lib */
#define GLM_SWIZZLE
#include "glm\glm\glm.hpp"
#include "glm\glm\ext.hpp"

class Sphere;

class Plane
{
protected:
	glm::vec4 m_vPlane;

public:
	Plane();
	Plane(const glm::vec4& a_vPoint, const glm::vec3& a_vNormal);
	Plane(const glm::vec3& a_vNormal, float a_fD);
	Plane(const Plane& a_Rhs);
	~Plane();

	Plane& operator= (const Plane& a_Rhs);

	void SetPlane(const Plane& a_Rhs);
	void SetPlane(const glm::vec3 a_vNormal, float a_fD);

	const glm::vec4 GetPlane() const;

	float Distance(const glm::vec4& a_vPoint) const;
	float Distance(const Sphere& a_vShere) const;
};

#endif //!_PLANE_H_