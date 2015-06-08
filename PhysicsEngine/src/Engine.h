/********************************************************************************/
/* [File]: Engine.h																*/
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
#ifndef _ENGINE_H_
#define _ENGINE_H_
//Lib
#include "PhysicsEngine.h"

class Engine : public App::BaseApplication
{
private:
	virtual void Render() override;

	virtual void Update(float a_fDeltaT) override;

	virtual void OnResize(GLint a_iWidth, GLint i_iHeight);

	virtual void OnKey(GLint a_iKey, GLint a_iAction) override;

	virtual void OnMouseButton(GLint a_iButton, GLint a_iAction) override;

	virtual void OnMouseMove(GLdouble a_dMouseX, GLdouble a_dMouseY) override;

	virtual void OnMouseWheel(GLdouble a_dPosition) override;
	
public:
	Engine();
	Engine(vec3 a_vCamPos, ivec2 a_vScreenSize, const char* a_pccWinName, bool a_bFullScreen);
	virtual ~Engine();

	virtual void Init(BaseApplication* a_oCurrApp, vec3 a_vCamPos, ivec2 a_vScreenSize,
		const char* a_pccWinName, bool a_bFullScreen) override;
};

#endif //!_ENGINE_H_