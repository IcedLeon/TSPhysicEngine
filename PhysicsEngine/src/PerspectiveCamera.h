/********************************************************************************/
/* [File]: PerspectiveCamera.h													*/
/* [Description]: */
/* */
/* [Author]: Tommaso Galatolo tommaso.galatolo@gmail.com						*/
/* [Date]: 18/6/2015															*/
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
#ifndef _PERSPECTIVECAMERA_H_
#define _PERSPECTIVECAMERA_H_
//Libs
#include "QuatCamera.h"

class PerspectiveCamera : public QuatCamera
{
private:
	float	m_fFovX;
	float	m_fFovY;
	bool	m_bFovXDirty;
	bool	m_bFovYDirty;

public:
	PerspectiveCamera(const string& a_sName);
	PerspectiveCamera(const PerspectiveCamera& a_oSrc);
	virtual ~PerspectiveCamera();

	virtual void UpdateProjection();

	virtual float GetNearWidth() const;

	virtual float GetNearHeight() const;

	virtual float GetFarWidth() const;

	virtual float GetFarHeight() const;

	void Perspective(float a_fFovy, const vec2& a_vViewport, float a_fZNear, float a_fZFar);

	void Perspective(float a_fFovy, float a_fWidth, float a_fHeight, float a_fZNear, float a_fZFar);

	void SetFovX(float a_fFovX);

	void SetFovY(float a_fFovY);
};

#endif