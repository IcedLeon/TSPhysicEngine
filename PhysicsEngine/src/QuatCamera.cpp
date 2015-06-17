#include "QuatCamera.h"
#include "ShaderProgram.h"

const float QuatCamera::GetDebugRad()
{
	return 2.0f;
}

QuatCamera::QuatCamera(const string& a_sName) : m_sName(a_sName),
												m_bDirty(true),
												m_vEye(0.0f, 0.0f, 0.0f, 1.0f),
												m_vCenter(1.0f, 0.0f, 0.0f, 1.0f),
												m_vUp(0.0f, 1.0f, 0.0f),
												m_vDir(1.0f, 0.0f, 0.0f),
												m_vViewport(0.0f),
												m_fZNear(0.1f),
												m_fZFar(1000.0f),
												m_mBiasMat(),
												m_oViewFrustum(),
												m_vLastPos(0.0f),
												m_qLastRot(quat()),
												m_mTransitionMat(1.0f),
												m_fWidth(1.0f),
												m_fHeight(1.0f),
												m_oFrustumZs()
{
	m_mBiasMat = glm::translate(vec3(0.5f));
	m_mBiasMat = glm::scale(vec3(0.5f));
}

QuatCamera::QuatCamera(const QuatCamera& a_oSrc) : m_sName(a_oSrc.m_sName),
												   m_bDirty(a_oSrc.m_bDirty),
												   m_vEye(a_oSrc.m_vEye),
												   m_vCenter(a_oSrc.m_vCenter),
												   m_vUp(a_oSrc.m_vUp),
												   m_vDir(a_oSrc.m_vDir),
												   m_vViewport(a_oSrc.m_vViewport),
												   m_fZNear(a_oSrc.m_fZNear),
												   m_fZFar(a_oSrc.m_fZFar),
												   m_oViewFrustum(a_oSrc.m_oViewFrustum),
												   m_vLastPos(a_oSrc.m_vLastPos),
												   m_qLastRot(a_oSrc.m_qLastRot),
												   m_fWidth(a_oSrc.m_fWidth),
												   m_fHeight(a_oSrc.m_fHeight),
												   m_oFrustumZs(a_oSrc.m_oFrustumZs),
												   m_mView(a_oSrc.m_mView),
												   m_mProj(a_oSrc.m_mProj),
m_mBiasProj(a_oSrc.m_mBiasProj),
m_mBiasMat(a_oSrc.m_mBiasMat),
m_mTransitionMat(a_oSrc.m_mTransitionMat)
{
}

QuatCamera::~QuatCamera()
{
	m_oFrustumZs.clear();
}

const string& QuatCamera::GetName() const
{
	return m_sName;
}

void QuatCamera::UpdateViewFrustum()
{
	m_oViewFrustum.TransformToWorldSpace(*this);

	m_oFrustumZs.clear();

	float _zNDC, _zCurrent;

	for (std::int32_t i = 0; i < m_oViewFrustum.GetNumberOfSections(); ++i)
	{
		_zCurrent = -(m_fZNear + (m_fZFar - m_fZNear) * static_cast<float>(i) / static_cast<float>(m_oViewFrustum.GetNumberOfSections()));

		_zNDC = (-(m_fZFar + m_fZNear) / (m_fZFar - m_fZNear) * _zCurrent + (-2.0f * m_fZFar * m_fZNear) / (m_fZFar - m_fZNear)) / -_zCurrent;

		m_oFrustumZs.push_back(glm::clamp(_zNDC, -1.0f, 1.0f));
	}
}

void QuatCamera::LookAt(const vec4& a_vEye, const vec4& a_vCenter, const vec3& a_vUp)
{
	this->m_vEye = a_vEye;
	this->m_vCenter = a_vCenter;
	this->m_vUp = a_vUp;
	this->m_vDir = glm::normalize(m_vCenter - m_vEye).xyz();

	vec3 _left = glm::normalize(glm::cross(m_vUp, m_vDir));

	this->m_vUp = glm::normalize(glm::cross(m_vDir, _left));

	m_mView = glm::lookAt(m_vEye.xyz(), m_vCenter.xyz(), m_vUp);

	UpdateViewFrustum();
}

void QuatCamera::UpdateViewport(const vec2& a_vViewport)
{
	this->m_vViewport = a_vViewport;

	LookAt(this->m_vEye, this->m_vCenter, this->m_vUp);

	UpdateProjection();
}

const vec4& QuatCamera::GetEye() const
{
	return this->m_vEye;
}

const vec3& QuatCamera::GetDirection() const
{
	return this->m_vDir;
}

const vec3& QuatCamera::GetUp() const
{
	return this->m_vUp;
}

void QuatCamera::SetNearZ(float a_fZNear)
{
	this->m_fZNear = a_fZNear;
}

float QuatCamera::GetNearZ() const
{
	return this->m_fZNear;
}

void QuatCamera::SetFarZ(float a_fZFar)
{
	this->m_fZFar = a_fZFar;
}

float QuatCamera::GetFarZ() const
{
	return this->m_fZFar;
}

const vec2& QuatCamera::GetViewport() const
{
	return this->m_vViewport;
}

const mat4& QuatCamera::GetView() const
{
	return this->m_mView;
}

const mat4& QuatCamera::GetProjection() const
{
	return this->m_mProj;
}

const mat4& QuatCamera::GetBiasProjection() const
{
	return this->m_mBiasProj;
}

const ViewFrustum& QuatCamera::GetViewFrustum() const
{
	return this->m_oViewFrustum;
}

const vector<float>& QuatCamera::GetFrustumZs() const
{
	return this->m_oFrustumZs;
}

void QuatCamera::SetNumOfSections(std::int32_t a_iSections)
{
	this->m_oViewFrustum.SetNumOfSections(a_iSections);
}

float QuatCamera::SetDistToCamera(const BoundingSphere& a_oBoundingSphere) const
{
	return glm::length(a_oBoundingSphere.GetCenter() - this->m_vEye);
}

void QuatCamera::SetCameraProperties(ShaderProgram& a_oProgram, const vec4& a_vPos, const quat& a_qRot, bool a_bUseLocation)
{
	if (a_bUseLocation && (a_vPos != m_vLastPos || a_qRot != m_qLastRot || m_bDirty))
	{
		m_mTransitionMat = mat4(1.0f);
		m_mTransitionMat = glm::translate(a_vPos.xyz());
		m_mTransitionMat *= glm::toMat4(a_qRot);

		vec4 _eye	 = m_mTransitionMat * vec4(0.0f, 0.0f, 0.0f, 1.0f);
		vec4 _center = m_mTransitionMat * vec4(1.0f, 0.0f, 0.0f, 1.0f);
		vec4 _up	 = m_mTransitionMat * vec4(0.0f, 1.0f, 0.0f, 1.0f);

		LookAt(_eye, _center, _up.xyz());

		m_vLastPos = a_vPos;
		m_qLastRot = a_qRot;

		m_bDirty = false;
	}

	if (&a_oProgram != nullptr)
	{
		a_oProgram.Use();
		a_oProgram.SetUniform("Projection", m_mProj);
		a_oProgram.SetUniform("View", m_mView);
		a_oProgram.SetUniform("Eye", m_vEye);
		a_oProgram.SetUniform("ViewFrustumZ", m_oFrustumZs[0]);
		a_oProgram.Disable();
	}
}

void QuatCamera::DebugDraw(const vec4& a_vPos, const quat& a_qRot, bool a_bUseLocation) const
{
	if (a_bUseLocation)
	{
		quat _baseRot(-90.0f, vec3(0.0f, 1.0f, 0.0f));
		_baseRot *= quat(90.0f, vec3(1.0f, 0.0f, 0.0f));
		//Deug draw.
	}
	else
	{
		vec3 _right = glm::cross(m_vDir, m_vUp);
		mat3 _rotMat(_right, m_vUp, -m_vDir);
		quat _camRot(_rotMat);

		quat _baseRot(90.0f, vec3(1.0f, 0.0f, 0.0f));

		/*Draw debug*/
	}
}