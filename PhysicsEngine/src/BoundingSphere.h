/********************************************************************************/
/* [File]: BoundingSphere.h														*/
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
#ifndef _BOUNDINGSPHERE_H_
#define _BOUNDINGSPHERE_H_
//Lib
#include "Sphere.h"

class AxisAlignedBoundingBox;

class BoundingSphere : public Sphere
{
public:
	BoundingSphere();
	BoundingSphere(const glm::vec4& a_vCenter, float a_fRadius);
	virtual ~BoundingSphere();

	bool Intersect(const BoundingSphere& a_oBoundingSphere) const;

	bool Enclose(const BoundingSphere& a_oBoundingSphere) const;

	bool Enclose(const glm::vec4& a_vPoint) const;

	bool Enclose(const AxisAlignedBoundingBox& a_oAABB) const;

	bool Inside(const AxisAlignedBoundingBox& a_oAABB) const;
};

#endif //!_BOUNDINGSPHERE_H_