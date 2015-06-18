/********************************************************************************/
/* [File]: CameraManager.h														*/
/* [Description]: */
/* */
/* [Author]: Tommaso Galatolo tommaso.galatolo@gmail.com						*/
/* [Date]: 12/6/2015															*/
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
#ifndef _CAMERAMANAGER_H_
#define _CAMERAMANAGER_H_
//Libs
#include "MappedKeyValue.h"
#include "Singleton.h"
#include "QuatCamera.h"

class CameraManager : public Singleton<CameraManager>
{
	friend class Singleton<CameraManager>;

private:
	MappedKeyValue<std::string, QuatCamera*> m_AllCameras;

	MappedKeyValue<std::string, QuatCamera*> m_AllWinCameras;

public:
	static const string DEFAULT_PERSPECRIVE_CAMERA_KEY;
	static const string DEFAULT_ORTHOGRAPHIC_CAMERA_KEY;

private:
	CameraManager();
	virtual ~CameraManager();

public:
	const QuatCamera& GetDefaultPerspectiveCam() const;
	
	const QuatCamera& GetDefaultOrthoCamera() const;
	
	bool ContainsCamera(const std::string& a_sName) const;

	const QuatCamera& GetCamera(const std::string& a_sName) const;

	void SetCurrentCamera(const std::string& a_sName, const QuatCamera& a_oCamera, bool m_bWinCamera);
	
	void UpdateWindowViewport(const vec2& a_vViewport);
};

#endif //!_CAMERAMANAGER_H_