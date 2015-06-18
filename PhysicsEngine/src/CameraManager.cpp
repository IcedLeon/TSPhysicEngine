#include "CameraManager.h"
#include "PerspectiveCamera.h"
#include "OrthoCamera.h"
#include "Log.h"

const string CameraManager::DEFAULT_PERSPECRIVE_CAMERA_KEY = "Default_Perspective";

const string CameraManager::DEFAULT_ORTHOGRAPHIC_CAMERA_KEY = "Default_Orthographic";

CameraManager::CameraManager() : Singleton<CameraManager>(),
								 m_AllCameras(),
								 m_AllWinCameras()
{
	m_AllCameras[DEFAULT_PERSPECRIVE_CAMERA_KEY]	 = new PerspectiveCamera(DEFAULT_PERSPECRIVE_CAMERA_KEY);
	m_AllCameras[DEFAULT_ORTHOGRAPHIC_CAMERA_KEY]	 = new OrthoCamera(DEFAULT_ORTHOGRAPHIC_CAMERA_KEY);
	m_AllWinCameras[DEFAULT_PERSPECRIVE_CAMERA_KEY]  = m_AllCameras[DEFAULT_PERSPECRIVE_CAMERA_KEY];
	m_AllWinCameras[DEFAULT_ORTHOGRAPHIC_CAMERA_KEY] = m_AllCameras[DEFAULT_ORTHOGRAPHIC_CAMERA_KEY];

	vec4 _eye(0.0f, 0.0f, 5.0f, 1.0f);
	vec4 _center(0.0f, 0.0f, 0.0f, 1.0f);
	vec3 _up(0.0f, 1.0f, 0.0f);

	m_AllCameras[DEFAULT_PERSPECRIVE_CAMERA_KEY]->LookAt(_eye, _center, _up);
	m_AllCameras[DEFAULT_ORTHOGRAPHIC_CAMERA_KEY]->LookAt(_eye, _center, _up);
}

CameraManager::~CameraManager()
{
	map<string, QuatCamera*>::iterator walker;

	walker = m_AllCameras.Begin();
	while (walker != m_AllCameras.End())
	{
		delete walker->second;
		walker++;
	}
	m_AllCameras.Clear();

	walker = m_AllWinCameras.Begin();
	while (walker != m_AllWinCameras.End())
	{
		delete walker->second;
		walker++;
	}
	m_AllWinCameras.Clear();
}

const QuatCamera& CameraManager::GetDefaultPerspectiveCam() const
{
	return *m_AllCameras.At(DEFAULT_PERSPECRIVE_CAMERA_KEY);
}

const QuatCamera& CameraManager::GetDefaultOrthoCamera() const
{
	return *m_AllCameras.At(DEFAULT_ORTHOGRAPHIC_CAMERA_KEY);
}

bool CameraManager::ContainsCamera(const string& a_sName) const
{
	return m_AllCameras.Contains(a_sName);
}

const QuatCamera& CameraManager::GetCamera(const string& a_sName) const
{
	return *m_AllCameras.At(a_sName);
}

void CameraManager::SetCurrentCamera(const string& a_sName, const QuatCamera& a_oCamera, bool a_bWinCamera)
{
	if (DEFAULT_PERSPECRIVE_CAMERA_KEY.compare(a_sName) != NULL)
		return;
	LOG("<INFO>: Adding a new camera to the manager: %s\n", a_oCamera.GetName().c_str());

	*m_AllCameras[a_sName] = a_oCamera;

	if (a_bWinCamera)
	{
		*m_AllWinCameras[a_sName] = a_oCamera;
	}
}

void CameraManager::UpdateWindowViewport(const vec2& a_vViewport)
{
	map<string, QuatCamera*>::iterator walker = m_AllWinCameras.Begin();

	while (walker != m_AllWinCameras.End())
	{
		walker->second->UpdateViewport(a_vViewport);

		walker++;
	}
}