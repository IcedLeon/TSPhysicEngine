/********************************************************************************/
/* [File]: Sphere.h																*/
/* [Description]: */
/* */
/* [Author]: Tommaso Galatolo tommaso.galatolo@gmail.com						*/
/* [Date]: 5/6/2015																*/
/* [License]:																	*/
/* This program is free software: you can redistribute it and/or modify			*/
/* it under the terms of the GNU Lesser General Public License as published by	*/
/* the Free Software Foundation, either version 3 of the License, or			*/
/* (at your option) any later version.											*/
/*																				*/
/* This program is distributed in the hope that it will be useful,				*/
/* but WITHOUT ANY WARRANTY; without even the implied warranty of				*/
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the				*/
/* GNU Lesser General Public License for more details.							*/
/*																				*/
/* You should have received a copy of the GNU Lesser General Public License		*/
/* along with this program.  If not, see <http://www.gnu.org/licenses/>.		*/
/********************************************************************************/
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