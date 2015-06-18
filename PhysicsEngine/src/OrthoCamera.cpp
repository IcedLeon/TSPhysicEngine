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

	vec3 _min;
	vec3 _max;

	for (std::int32_t i = a_iSections * 4; i < a_iSections * 4 + 8; ++i)
	{
		vec3 _v = (_frustumPoint[i] - vec4(0.0f, 0.0f, 0.0f, 1.0f)).xyz;

		vec3 _lightPos;

		_lightPos.x = glm::dot(_lightRight, _v);
		_lightPos.y = glm::dot(_lightUp, _v);
		_lightPos.z = glm::dot(_lightForward, _v);

		if (i == a_iSections * 4)
		{
			for (std::int32_t k = 0; k < 3; ++k)
				_min[k] = _max[k] = _lightPos[k];
		}
		else
		{
			for (std::int32_t k = 0; k < 3; ++k)
			{
				if (_lightPos[k] < _min[k])
					_min[k] = _lightPos[k];
				if (_lightPos[k] > _max[k])
					_max[k] = _lightPos[k];
			}
		}
	}

	float _orthoScale = std::max(std::abs(_max[0] - _min[0]), std::abs(_max[1] - _min[1]));

	Orthografic(_orthoScale, _orthoScale, 0.1f, 1000.0f);

	vec3 _offset(0.0f, 0.0f, 0.0f);

	_offset += _lightRight * ((_max[0] + _min[0]) / 2.0f);
	_offset += _lightUp * ((_max[1] + _min[1]) / 2.0f);

	if (_min[2] <= 0.0f)
		_offset += _lightForward * _min[2];

	m_mTransitionMat = mat4(1.0f);
	m_mTransitionMat = glm::translate(a_vLightPos.xyz() + _offset);
	m_mTransitionMat *= glm::toMat4(a_qLightRot);

	vec4 _eye = m_mTransitionMat * vec4(0.0f, 0.0f, 0.0f, 1.0f);
	vec4 _center = m_mTransitionMat * vec4(1.0f, 0.0f, 0.0f, 1.0f);
	vec3 _up = (m_mTransitionMat * vec4(0.0f, 1.0f, 0.0f, 0.0f)).xyz();

	LookAt(_eye, _center, _up);

	m_vLastPos = a_vLightPos + vec4(_offset, 0.0f);
	m_qLastRot = a_qLightRot;
}