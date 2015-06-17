/********************************************************************************/
/* [File]: ViewFrustum.h														*/
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
#ifndef _VIEWFRUSTUM_H_
#define _VIEWFRUSTUM_H_
//Libs
#include "UsedLibs.h"
#include "Plane.h"
#include "BoundingSphere.h"

class Camera;
class QuatCamera;

typedef enum frustum_sides
{
	NEAR_PLANE,
	FAR_PLANE,
	LEFT_PLANE,
	RIGHT_PLANE,
	BOTTOM_PLANE,
	TOP_PLANE
} FrustumSides;

class ViewFrustum
{
private:
	static Plane m_oSides_NDC[6];
	Plane m_oSides[6];
	vector<vec4> m_oFrustumPoints;
	std::int32_t m_iSections;

public:
	ViewFrustum();
	ViewFrustum(const ViewFrustum& a_oSrc);
	virtual ~ViewFrustum();

	void TransformToWorldSpace(const Camera& a_oCurrCamera);
	void TransformToWorldSpace(const QuatCamera& a_oCurrCamera);

	bool IsVisible(const BoundingSphere& a_oBoundingSphere) const;

	void SetNumOfSections(std::int32_t a_iSections);

	std::int32_t GetNumberOfSections() const;

	const vector<vec4>& GetFrustumPoints() const;

};

#endif //!_VIEWFRUSTUM_H_