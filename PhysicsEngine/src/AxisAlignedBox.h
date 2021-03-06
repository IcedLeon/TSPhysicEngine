/********************************************************************************/
/* [File]: AxisAlignedBox.h														*/
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
#ifndef _AXISALIGNEDBOX_H_
#define _AXISALIGNEDBOX_H_
//Lib
#define GLM_SWIZZLE
#include "glm\glm\glm.hpp"
#include "glm\glm\ext.hpp"

class AxisAlignedBox
{
protected:
	glm::vec4 m_vCenter;
	float m_fHalfWidth;
	float m_fHalfHeight;
	float m_fHalfDepth;
	
public:
	AxisAlignedBox();
	AxisAlignedBox(const glm::vec4& a_vCenter, float a_fHalfWidth, float a_fHalfHeight, float a_fHalfDepth);
	virtual	~AxisAlignedBox();

	const glm::vec4& GetCenter() const;
	void SetCenter(const glm::vec4& a_vCenter);
	float GetHalfWidth() const;
	void SetHalfWidth(float a_fHalfWidth);
	float GetHalfHeight() const;
	void SetHalfHeight(float a_fHalfHeight);
	float GetHalfDepth() const;
	void SetHalfDepth(float a_fHalfDepth);
};

#endif //!_AXISALIGNEDBOX_H_