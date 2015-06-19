/********************************************************************************/
/* [File]: Plane.h																*/
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

	//Plane& operator= (const Plane& a_Rhs);

	void SetPlane(const Plane& a_Rhs);
	void SetPlane(const glm::vec3 a_vNormal, float a_fD);

	const glm::vec4 GetPlane() const;

	float Distance(const glm::vec4& a_vPoint) const;
	float Distance(const Sphere& a_vShere) const;
};

#endif //!_PLANE_H_