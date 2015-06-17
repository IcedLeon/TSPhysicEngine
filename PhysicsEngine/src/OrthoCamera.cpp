#include "OrthoCamera.h"

OrthoCamera::OrthoCamera(const string& a_sName) : QuatCamera(a_sName)
{
}

OrthoCamera::OrthoCamera(const OrthoCamera& a_oSrc) : QuatCamera(a_oSrc)
{
}

OrthoCamera::~OrthoCamera()
{
}

void OrthoCamera::UpdateProjection()
{
	Orthografic(m_vViewport, m_fZNear, m_fZFar);
}

float OrthoCamera::GetNearWidth() const
{
	return this->m_fWidth;
}

float OrthoCamera::GetNearHeight() const
{
	return this->m_fHeight;
}

float OrthoCamera::GetFarWidth() const
{
	return this->m_fWidth;
}

float OrthoCamera::GetFarHeight() const
{
	return this->m_fHeight;
}

void OrthoCamera::Orthografic(const vec2& a_vViewport, float a_fZNear, float a_fZFar)
{
	this->m_vViewport	= a_vViewport;
	this->m_fZNear		= a_fZNear;
	this->m_fZFar		= a_fZFar;
	this->m_fWidth		= a_vViewport.x;
	this->m_fHeight		= a_vViewport.y;

	m_mProj = glm::ortho(-m_fWidth / 2.0f, m_fWidth / 2.0f, -m_fHeight / 2.0f, m_fHeight / 2.0f, m_fZNear, m_fZFar);
	
	m_mBiasProj = m_mBiasMat * m_mProj;

	UpdateViewFrustum();
}

void OrthoCamera::Orthografic(float a_fWidth, float a_fHeight, float a_fZNear, float a_fZFar)
{
	this->m_fZNear	= a_fZNear;
	this->m_fZFar	= a_fZFar;
	this->m_fWidth	= a_fWidth;
	this->m_fHeight = a_fHeight;

	m_mProj = glm::ortho(-m_fWidth / 2.0f, m_fWidth / 2.0f, -m_fHeight / 2.0f, m_fHeight / 2.0f, m_fZNear, m_fZFar);

	m_mBiasProj = m_mBiasMat * m_mProj;

	UpdateViewFrustum();
}

void OrthoCamera::AdjustFrustum(const ViewFrustum& a_oViewFrustum, std::int32_t a_iSections, const vec4& a_vLightPos, const quat& a_qLightRot)
{
	const vector<vec4>& _frustumPoint = m_oViewFrustum.GetFrustumPoints();

	vec3 _lightForward = a_qLightRot * vec3(1.0f, 0.0f, 0.0f);
	vec3 _lightRight = a_qLightRot * vec3(0.0f, 0.0f, 1.0f);
	vec3 _lightUp = a_qLightRot * vec3(0.0f, -1.0f, 0.0f);

	vec3 min;
	vec3 max;

	for (std::int32_t i = a_iSections * 4; i < a_iSections * 4 + 8; ++i)
	{
		//Here
	}
}