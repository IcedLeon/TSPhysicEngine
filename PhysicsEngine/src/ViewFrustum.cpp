#include "ViewFrustum.h"
#include "Camera.h"
#include "QuatCamera.h"

Plane ViewFrustum::m_oSides_NDC[6] = 
{
	Plane(vec3(0.0f, 0.0f, 1.0f), 1.0f),
	Plane(vec3(0.0f, 0.0f, -1.0f), 1.0f),
	Plane(vec3(1.0f, 0.0f, 0.0f), 1.0f),
	Plane(vec3(-1.0f, 0.0f, 0.0f), 1.0f),
	Plane(vec3(0.0f, 1.0f, 0.0f), 1.0f),
	Plane(vec3(0.0f, -1.0f, -1.0f), 1.0f),
};

ViewFrustum::ViewFrustum() { SetNumOfSections(1); }

ViewFrustum::ViewFrustum(const ViewFrustum& a_oSrc)
{
	m_oSides[NEAR_PLANE]	= a_oSrc.m_oSides[NEAR_PLANE];
	m_oSides[FAR_PLANE]		= a_oSrc.m_oSides[FAR_PLANE];
	m_oSides[LEFT_PLANE]	= a_oSrc.m_oSides[LEFT_PLANE];
	m_oSides[RIGHT_PLANE]	= a_oSrc.m_oSides[RIGHT_PLANE];
	m_oSides[BOTTOM_PLANE]	= a_oSrc.m_oSides[BOTTOM_PLANE];
	m_oSides[TOP_PLANE]		= a_oSrc.m_oSides[TOP_PLANE];

	m_oFrustumPoints = a_oSrc.m_oFrustumPoints;

	m_iSections = a_oSrc.m_iSections;
}

ViewFrustum::~ViewFrustum()
{
	m_oFrustumPoints.clear();
}

void ViewFrustum::TransformToWorldSpace(const Camera& a_oCurrCamera)
{
	mat4 _transViewProj = a_oCurrCamera.GetProjection() * a_oCurrCamera.GetView();
	glm::transpose(_transViewProj);

	vec4 _temp;
	/*Near*/
	_temp = _transViewProj * m_oSides_NDC[NEAR_PLANE].GetPlane();
	m_oSides[NEAR_PLANE].SetPlane(_temp.xyz, _temp.w);
	/*Far*/
	_temp = _transViewProj * m_oSides_NDC[FAR_PLANE].GetPlane();
	m_oSides[FAR_PLANE].SetPlane(_temp.xyz, _temp.w);
	/*Left*/
	_temp = _transViewProj * m_oSides_NDC[LEFT_PLANE].GetPlane();
	m_oSides[LEFT_PLANE].SetPlane(_temp.xyz, _temp.w);
	/*Right*/
	_temp = _transViewProj * m_oSides_NDC[RIGHT_PLANE].GetPlane();
	m_oSides[RIGHT_PLANE].SetPlane(_temp.xyz, _temp.w);
	/*Bottom*/
	_temp = _transViewProj * m_oSides_NDC[BOTTOM_PLANE].GetPlane();
	m_oSides[BOTTOM_PLANE].SetPlane(_temp.xyz, _temp.w);
	/*Top*/
	_temp = _transViewProj * m_oSides_NDC[TOP_PLANE].GetPlane();
	m_oSides[TOP_PLANE].SetPlane(_temp.xyz, _temp.w);

	//vec3 _right = glm::cross(a_oCurrCamera.GetDirection(), a_oCurrCamera.GetUp());
	//
	//vec3 _nearRight = _right * (a_oCurrCamera.GetNearWidth() / 2.0f);
	//vec3 _nearUp = a_oCurrCamera.GetUp() * (a_oCurrCamera.GetNearHeight() / 2.0f);
	//vec4 _nearCenter = a_oCurrCamera.GetEye() + vec4(a_oCurrCamera.GetDirection(), 0.0f) * a_oCurrCamera.GetNearZ();
	//
	//vec3 _farRight = _right * (a_oCurrCamera.GetFarWidth() / 2.0f);
	//vec3 _farUp = a_oCurrCamera.GetUp() * (a_oCurrCamera.GetFarHeight() / 2.0f);
	//vec4 _farCenter = a_oCurrCamera.GetEye() + vec4(a_oCurrCamera.GetDirection(), 0.0f) * a_oCurrCamera.GetFarZ();
	//
	//vec4 _nearTopLeft = _nearCenter + vec4(_nearUp, 0.0f) - vec4(_nearRight, 0.0f);
	//vec4 _nearTopRight = _nearCenter + vec4(_nearUp, 0.0f) + vec4(_nearRight, 0.0f);
	//
	//vec4 _nearBottomLeft = _nearCenter - vec4(_nearUp, 0.0f) - vec4(_nearRight, 0.0f);
	//vec4 _nearBottomRight = _nearCenter - vec4(_nearUp, 0.0f) + vec4(_nearRight, 0.0f);
	//
	//vec4 _farTopLeft = _farCenter + vec4(_farUp, 0.0f) - vec4(_farRight, 0.0f);
	//vec4 _farTopRight = _farCenter + vec4(_farUp, 0.0f) + vec4(_farRight, 0.0f);
	//
	//vec4 _farBottomLeft = _farCenter - vec4(_farUp, 0.0f) - vec4(_farRight, 0.0f);
	//vec4 _farBottomRight = _nearCenter - vec4(_farUp, 0.0f) + vec4(_farRight, 0.0f);
	//
	//float _sectionDepth = 1.0f / static_cast<float>(m_iSections);
	//float _currSectionDepth;
	//
	//for (std::int32_t i = 0; i < GetNumberOfSections(); ++i)
	//{
	//	_currSectionDepth = _sectionDepth * static_cast<float>(i);
	//
	//	m_oFrustumPoints[i * 4 + 0] = _nearTopLeft + (_farTopLeft - _nearTopLeft) * _currSectionDepth;
	//	m_oFrustumPoints[i * 4 + 1] = _nearTopRight + (_farTopRight - _nearTopRight) * _currSectionDepth;
	//	m_oFrustumPoints[i * 4 + 2] = _nearBottomLeft + (_farBottomLeft - _nearBottomLeft) * _currSectionDepth;
	//	m_oFrustumPoints[i * 4 + 3] = _nearBottomRight + (_farBottomRight - _nearBottomRight) * _currSectionDepth;
	//}
}

void ViewFrustum::TransformToWorldSpace(const QuatCamera& a_oCurrCamera)
{
	mat4 _transViewProj = a_oCurrCamera.GetProjection() * a_oCurrCamera.GetView();
	glm::transpose(_transViewProj);

	vec4 _temp;
	/*Near*/
	_temp = _transViewProj * m_oSides_NDC[NEAR_PLANE].GetPlane();
	m_oSides[NEAR_PLANE].SetPlane(_temp.xyz, _temp.w);
	/*Far*/
	_temp = _transViewProj * m_oSides_NDC[FAR_PLANE].GetPlane();
	m_oSides[FAR_PLANE].SetPlane(_temp.xyz, _temp.w);
	/*Left*/
	_temp = _transViewProj * m_oSides_NDC[LEFT_PLANE].GetPlane();
	m_oSides[LEFT_PLANE].SetPlane(_temp.xyz, _temp.w);
	/*Right*/
	_temp = _transViewProj * m_oSides_NDC[RIGHT_PLANE].GetPlane();
	m_oSides[RIGHT_PLANE].SetPlane(_temp.xyz, _temp.w);
	/*Bottom*/
	_temp = _transViewProj * m_oSides_NDC[BOTTOM_PLANE].GetPlane();
	m_oSides[BOTTOM_PLANE].SetPlane(_temp.xyz, _temp.w);
	/*Top*/
	_temp = _transViewProj * m_oSides_NDC[TOP_PLANE].GetPlane();
	m_oSides[TOP_PLANE].SetPlane(_temp.xyz, _temp.w);
	
	vec3 _right = glm::cross(a_oCurrCamera.GetDirection(), a_oCurrCamera.GetUp());

	vec3 _nearRight = _right * (a_oCurrCamera.GetNearWidth() / 2.0f);
	vec3 _nearUp = a_oCurrCamera.GetUp() * (a_oCurrCamera.GetNearHeight() / 2.0f);
	vec4 _nearCenter = a_oCurrCamera.GetEye() + vec4(a_oCurrCamera.GetDirection(), 1.0f) * a_oCurrCamera.GetNearZ();

	vec3 _farRight = _right * (a_oCurrCamera.GetFarWidth() / 2.0f);
	vec3 _farUp = a_oCurrCamera.GetUp() * (a_oCurrCamera.GetFarHeight() / 2.0f);
	vec4 _farCenter = a_oCurrCamera.GetEye() + vec4(a_oCurrCamera.GetDirection(), 1.0f) * a_oCurrCamera.GetFarZ();

	vec4 _nearTopLeft	= _nearCenter + vec4(_nearUp, 0.0f) - vec4(_nearRight, 0.0f);
	vec4 _nearTopRight	= _nearCenter + vec4(_nearUp, 0.0f) + vec4(_nearRight, 0.0f);

	vec4 _nearBottomLeft  = _nearCenter - vec4(_nearUp, 0.0f) - vec4(_nearRight, 0.0f);
	vec4 _nearBottomRight = _nearCenter - vec4(_nearUp, 0.0f) + vec4(_nearRight, 0.0f);
	
	vec4 _farTopLeft	= _farCenter + vec4(_farUp, 0.0f) - vec4(_farRight, 0.0f);
	vec4 _farTopRight	= _farCenter + vec4(_farUp, 0.0f) + vec4(_farRight, 0.0f);
	
	vec4 _farBottomLeft  = _farCenter - vec4(_farUp, 0.0f) - vec4(_farRight, 0.0f);
	vec4 _farBottomRight = _nearCenter - vec4(_farUp, 0.0f) + vec4(_farRight, 0.0f);

	float _sectionDepth = 1.0f / static_cast<float>(m_iSections);
	float _currSectionDepth;

	for (std::int32_t i = 0; i < GetNumberOfSections(); ++i)
	{
		_currSectionDepth = _sectionDepth * static_cast<float>(i);

		m_oFrustumPoints[i * 4 + 0] = _nearTopLeft + (_farTopLeft - _nearTopLeft) * _currSectionDepth;
		m_oFrustumPoints[i * 4 + 1] = _nearTopRight + (_farTopRight - _nearTopRight) * _currSectionDepth;
		m_oFrustumPoints[i * 4 + 2] = _nearBottomLeft + (_farBottomLeft - _nearBottomLeft) * _currSectionDepth;
		m_oFrustumPoints[i * 4 + 3] = _nearBottomRight + (_farBottomRight - _nearBottomRight) * _currSectionDepth;
	}
}

bool ViewFrustum::IsVisible(const BoundingSphere& a_oBoundingSphere) const
{
	float _dist;

	for (std::int32_t i = 0; i < 6; ++i)
	{
		_dist = m_oSides[i].Distance(a_oBoundingSphere);

		if (_dist + a_oBoundingSphere.GetRadius() < 0.0f)
		{
			return false;
		}
	}

	return true;
}

void ViewFrustum::SetNumOfSections(std::int32_t a_iSections)
{
	if (m_iSections <= 0)
	{
		return;
	}

	this->m_iSections = a_iSections;

	m_oFrustumPoints.clear();

	for (std::int32_t i = 0; i < (a_iSections + 1) * 4; ++i)
		m_oFrustumPoints.push_back(vec4());
}

std::int32_t ViewFrustum::GetNumberOfSections() const
{
	return m_iSections;
}

const vector<vec4>& ViewFrustum::GetFrustumPoints() const
{
	return m_oFrustumPoints;
}