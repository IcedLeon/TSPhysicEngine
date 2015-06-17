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
	/*Base Application inherited*/
	
	/*
	This function would render all the render pass,
	geometry, model, ecc currently associated with the main
	scene.
	*/
	virtual void Render() override;
	/*
	The update function, as the name suggest would update all the
	value that need constant "refresh"(since it's called once per frame)
	to keep the application up to date.
	*/
	virtual void Update(float a_fDeltaT) override;
	/*
	All the screen related option, function or variables that need to be 
	associated with GLFW can be passed trought here. It eliminates the problem
	of making any variables static.
	*/
	virtual void OnResize(GLint a_iWidth, GLint i_iHeight);
	/*
	As the function above, this one is related to the key input.
	It's helpful if we want to pass 3th party like AntTweekBar.
	*/
	virtual void OnKey(GLint a_iKey, GLint a_iAction) override;
	/*
	As the function above, but for the mouse button.
	*/
	virtual void OnMouseButton(GLint a_iButton, GLint a_iAction) override;
	/*
	This function is directly passed into the GLFW mouse callback function.
	All the input passed or received are immediately locked onto the application window.
	*/
	virtual void OnMouseMove(GLdouble a_dMouseX, GLdouble a_dMouseY) override;
	/*
	Mouse wheel option enabling.
	*/
	virtual void OnMouseWheel(GLdouble a_dPosition) override;

	/*Member function*/

	/*
	The update key is the function in charge of updating the keyboard input.
	*/
	void UpdateKeyInput();

public:
	Engine();
	Engine(vec3 a_vCamPos, ivec2 a_vScreenSize, const char* a_pccWinName, bool a_bFullScreen);
	virtual ~Engine();

	virtual void Init(BaseApplication* a_oCurrApp, vec3 a_vCamPos, ivec2 a_vScreenSize,
		const char* a_pccWinName, bool a_bFullScreen) override;
};

#endif //!_ENGINE_H_