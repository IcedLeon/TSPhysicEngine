/********************************************************************************/
/* [File]: QuatCamera.h															*/
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
#ifndef _QUATCAMERA_H_
#define _QUATCAMERA_H_
//Libs
#include "UsedLibs.h"
#include "ViewFrustum.h"

class ShaderProgram;

class QuatCamera
{
private:
	string m_sName;
	bool m_bDirty;

protected:
	mat4 m_mView;
	mat4 m_mProj;
	mat4 m_mBiasProj;
	mat4 m_mBiasMat;
	mat4 m_mTransitionMat;

	ViewFrustum m_oViewFrustum;
	
	quat m_qLastRot;

	vec4 m_vEye;
	vec4 m_vCenter;
	vec4 m_vLastPos;

	vec3 m_vUp;
	vec3 m_vDir;
	vec2 m_vViewport;
	
	float m_fZNear;
	float m_fZFar;

	float m_fWidth;
	float m_fHeight;
	/*Normalized device coordinates*/
	vector<float> m_oFrustumZs;

	void UpdateViewFrustum();

public:
	QuatCamera(const string& a_sName);
	QuatCamera(const QuatCamera& a_oSrc);
	virtual ~QuatCamera();

	static const float GetDebugRad();

	const string& GetName() const;

	void LookAt(const vec4& a_vEye, const vec4& a_vCenter, const vec3& a_vUp);

	virtual void UpdateProjection() = NULL;

	void UpdateViewport(const vec2& a_vViewport);

	void SetViewport(const vec2& a_vViewport);

	const vec4& GetEye() const;

	const vec3& GetDirection() const;

	const vec3& GetUp() const;

	void SetNearZ(float a_fZNear);
	float GetNearZ() const;

	void SetFarZ(float a_fZFar);
	float GetFarZ() const;

	const vec2& GetViewport() const;

	virtual float GetNearWidth() const = NULL;

	virtual float GetNearHeight() const = NULL;

	virtual float GetFarWidth() const = NULL;

	virtual float GetFarHeight() const = NULL;

	const mat4& GetView() const;

	const mat4& GetProjection() const;

	const mat4& GetBiasProjection() const;
	/*View frustum in world space*/
	const ViewFrustum& GetViewFrustum() const;

	const vector<float>& GetFrustumZs() const;

	void SetNumOfSections(std::int32_t a_iSections);

	float SetDistToCamera(const BoundingSphere& a_oBoundingSphere) const;

	void SetCameraProperties(ShaderProgram& a_oProgram, const vec4& a_vPos, const quat& a_qRot, bool a_bUseLocation);

	virtual void DebugDraw(const vec4& a_vPos, const quat& a_qRot, bool a_bUseLocation = false) const;
};

#endif //!_QUATCAMERA_H_