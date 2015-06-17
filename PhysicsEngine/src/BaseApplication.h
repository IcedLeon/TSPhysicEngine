/********************************************************************************/
/* [File]: BaseApplication.h													*/
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
#ifndef _BASEAPPLICATION_H_
#define _BASEAPPLICATION_H_
//Libs
#include "UsedLibs.h"
#include "Camera.h"

#ifdef _DEBUG
#endif

namespace App
{
	class BaseApplication
	{
	public:
		struct
		{
			GLFWwindow*			m_oWin;
			Camera*				m_oCurrCamera;
			//Bar*				m_oTweeking;
			map<int, Camera*>	m_oTotalCameras;
			struct
			{
				mat4 m_mProjection;
				mat4 m_mView;
				mat4 m_mWorld;
			} TRANSFORM;
			struct
			{
				GLdouble m_dDeltaT;
				GLdouble m_dCurrT;
				GLdouble m_dPrevT;
			} TIME;
		} DATA;
		struct 
		{
			const char* m_pccTitle;
			ivec2		m_viWinSize;
			ivec2		m_viGLVersion; //X-> Major ver, Y->Minor ver.
			int			m_iSample;
			union
			{
				struct
				{
					unsigned int m_uiFullScreen : 1;
					unsigned int m_uiVSync		: 1;
					unsigned int m_uiCursor		: 1;
					unsigned int m_uiDebug		: 1;
				};
				unsigned int m_uiAll;
			} Flags;
		} APPINFO;
		static bool	m_bKeys[MAX_KEYS];

	protected:
		static App::BaseApplication* m_oApp;
		static void framebuffer_size_callback(GLFWwindow* a_oWindow, GLint a_iWidth, GLint a_iHeight);
		static void key_callback(GLFWwindow* a_oWindow, GLint a_iKey, GLint a_iKeyCode, GLint a_iAction, GLint a_iMode);
		static void mouse_callback(GLFWwindow* a_oWindow, GLdouble a_iMouseX, GLdouble a_iMouseY);
		static void mouse_button_callback(GLFWwindow* a_oWindow, GLint a_iButton, GLint a_iAction, GLint a_iMode);
		static void scroll_callback(GLFWwindow* a_oWindow, GLdouble a_fOffsetX, GLdouble a_fOffsetY);
		static void on_char_callback(GLFWwindow* a_oWindow, GLuint a_uiCodepoint, GLint a_iMode);
		static void APIENTRY debug_callback(GLenum a_eSource, GLenum a_eType, GLuint a_uiID, 
			GLenum a_eSeverity, GLsizei a_siLength, const GLchar* a_pccMsg, const GLvoid* a_pcvParam);
		//static void APIENTRY debug_callback_AMD(GLenum a_eType, GLuint a_uiID, 
		//	GLenum a_eSeverity, GLsizei a_siLength, const GLchar* a_pccMsg, const GLvoid* a_pcvParam);

		void InitWindow();

		void ChooseResolution();

		void InitDependency(vec3 a_vCamPos);

		void DumpGLInfo();

		void CreateCamera(vec3 a_vCamPos);

		void SwitchCamera(int a_iCamID);

		virtual void Render() = NULL;

		virtual void Update(float a_fDeltaT) = NULL;

		virtual void OnResize(GLint a_iWidth, GLint i_iHeight);
		
		virtual void OnKey(GLint a_iKey, GLint a_iAction) = NULL;

		virtual void OnMouseButton(GLint a_iButton, GLint a_iAction) = NULL;

		virtual void OnMouseMove(GLdouble a_dMouseX, GLdouble a_dMouseY) = NULL;

		virtual void OnMouseWheel(GLdouble a_dPosition) = NULL;

		virtual void GetGLError(GLenum a_eSource, GLenum a_eType, GLuint a_uiID,
			GLenum a_eSeverity, const GLchar* a_pccMsg);

		virtual void Shutdown();

		void EnableVsync(bool a_bVsyncEnable);
		
	public:
		BaseApplication();
		BaseApplication(const BaseApplication& a_Rhs);
		virtual ~BaseApplication();

		virtual void Init(BaseApplication* a_oCurrApp, vec3 a_vCamPos, ivec2 a_vScreenSize, const char* a_pccWinName, bool a_bFullScreen);
		
		void RunApp();

	};
}

#endif //!_BASEAPPLICATION_H_