/********************************************************************************/
/* [File]: OrthoCamera.h														*/
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
#ifndef _ORTHOCAMERA_H_
#define _ORTHOCAMERA_H_
//Libs
#include "QuatCamera.h"

class OrthoCamera : public QuatCamera
{
public:
	OrthoCamera(const string& a_sName);
	OrthoCamera(const OrthoCamera& a_oSrc);
	virtual ~OrthoCamera();

	virtual void UpdateProjection();

	virtual float GetNearWidth() const;

	virtual float GetNearHeight() const;

	virtual float GetFarWidth() const;

	virtual float GetFarHeight() const;

	void Orthografic(const vec2& a_vViewport, float a_fZNear, float a_fZFar);

	void Orthografic(float a_fWidth, float a_fHeight, float a_fZNear, float a_fZFar);

	void AdjustFrustum(const ViewFrustum& a_oViewFrustum, std::int32_t a_iSections, const vec4& a_vLightPos, const quat& a_qLightRot);
};

#endif //!_ORTHOCAMERA_H_