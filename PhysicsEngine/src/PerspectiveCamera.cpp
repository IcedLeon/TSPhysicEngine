#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(const string& a_sName) : QuatCamera(a_sName),
															  m_fFovX(40.0f),
															  m_fFovY(40.0f),
															  m_bFovXDirty(false),
															  m_bFovYDirty(false)
{
}

PerspectiveCamera::PerspectiveCamera(const PerspectiveCamera& a_oSrc) : QuatCamera(a_oSrc),
																		m_fFovX(a_oSrc.m_fFovX),
																		m_fFovY(a_oSrc.m_fFovY),
																		m_bFovXDirty(a_oSrc.m_bFovXDirty),
																		m_bFovYDirty(a_oSrc.m_bFovYDirty)
{
}

PerspectiveCamera::~PerspectiveCamera()
{
}

void PerspectiveCamera::UpdateProjection()
{
	if (m_bFovXDirty)
	{
		float _dist = m_vViewport.y / std::tanf(glm::radians(m_fFovY / 2.0f));

		m_fFovX = glm::radians(std::atanf(m_vViewport.x) / _dist) * 2.0f;

		m_bFovXDirty = false;
	}
	else if (m_bFovYDirty)
	{
		float _dist = m_vViewport.x / std::tanf(glm::radians(m_fFovX / 2.0f));

		m_fFovY = glm::radians(std::atanf(m_vViewport.y) / _dist) * 2.0f;

		m_bFovYDirty = false;
	}

	Perspective(m_fFovY, m_vViewport, m_fZNear, m_fZFar);
}

float PerspectiveCamera::GetNearWidth() const
{
	return m_fWidth / m_fHeight * GetNearHeight();
}

float PerspectiveCamera::GetNearHeight() const
{
	return 2.0f * std::tanf(m_fFovY * glm::pi<float>() / 360.0f) * m_fZNear;
}

float PerspectiveCamera::GetFarWidth() const
{
	return m_fWidth / m_fHeight * GetFarHeight();
}

float PerspectiveCamera::GetFarHeight() const
{
	return 2.0f * std::tanf(m_fFovY * glm::pi<float>() / 360.0f) * m_fZFar;
}

void PerspectiveCamera::Perspective(float a_fFovy, const vec2& a_vViewport, float a_fZNear, float a_fZFar)
{
	this->m_fFovY		= a_fFovy;
	this->m_vViewport	= a_vViewport;
	this->m_fZNear		= a_fZNear;
	this->m_fZFar		= a_fZFar;
	this->m_fWidth		= a_vViewport.x;
	this->m_fHeight		= a_vViewport.y;
	
	float _aspRat = m_fWidth / m_fHeight;

	m_mProj = glm::perspective(m_fFovY, _aspRat, m_fZNear, m_fZFar);

	m_mBiasProj = m_mBiasMat * m_mProj;

	UpdateViewFrustum();
}

void PerspectiveCamera::Perspective(float a_fFovy, float a_fWidth, float a_fHeight, float a_fZNear, float a_fZFar)
{
	this->m_fFovY	= a_fFovy;
	this->m_fZNear	= a_fZNear;
	this->m_fZFar	= a_fZFar;
	this->m_fWidth	= a_fWidth;
	this->m_fHeight = a_fHeight;

	float _aspRat = m_fWidth / m_fHeight;

	m_mProj = glm::perspective(m_fFovY, _aspRat, m_fZNear, m_fZFar);

	m_mBiasProj = m_mBiasMat * m_mProj;

	UpdateViewFrustum();
}

void PerspectiveCamera::SetFovX(float a_fFovX)
{
	this->m_fFovX = a_fFovX;

	m_bFovXDirty = false;
	m_bFovYDirty = true;
}

void PerspectiveCamera::SetFovY(float a_fFovY)
{
	this->m_fFovY = a_fFovY;

	m_bFovXDirty = true;
	m_bFovYDirty = false;
}