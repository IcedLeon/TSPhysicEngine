/********************************************************************************/
/* [File]: Camera.h																*/
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
#ifndef _CAMERA_H_
#define _CAMERA_H_
//Lib
#include "gl_core_4_4.h"
#define GLM_SWIZZLE
#include "glm\glm\glm.hpp"
#include "glm\glm\gtc\matrix_transform.hpp"

enum CameraMovement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

class Camera
{
protected:
	//Reference to the screen size.
	glm::vec2	m_vScreenSize;
	//Attribute of the camera.
	glm::vec3	m_vPos,
				m_vFront,
				m_vUp,
				m_vRight,
				m_vWorldUp;
	//Euclidian angles
	GLfloat m_fYaw,
			m_fPitch,
			//Camera option
			m_fCamSpeed,
			m_fMouseSensitivity,
			m_fFOV;
	//Recalculate the front vector from the camera Euclidian angles.
	void UpdateCameraVectors();

public:
	Camera(glm::vec2 a_vScreenSize) : m_vScreenSize(a_vScreenSize),
									  m_vPos(0.0f),
									  m_vFront(0.0f),
									  m_vUp(0.0f),
									  m_vRight(0.0f),
									  m_vWorldUp(0.0f),
									  m_fYaw(0.0f),
									  m_fPitch(0.0f),
									  m_fCamSpeed(0.0f),
									  m_fMouseSensitivity(0.0f),
									  m_fFOV(0.0f)
	{ }
	virtual ~Camera() { }
	//Camera builder with vectors
	void BuildCamera(glm::vec3 a_vPos,
					 glm::vec3 a_vUp = glm::vec3(0.0f, 1.0f, 0.0f),
					 GLfloat a_fYaw	= -90.0f,
					 GLfloat a_fPitch = 0.0f);
	//Camera builder with scalar values
	void BuildCamera(GLfloat a_fPosX,
					 GLfloat a_fPosY,
					 GLfloat a_fPosZ,
					 GLfloat a_fUpX,
					 GLfloat a_fUpY,
					 GLfloat a_fUpZ,
					 GLfloat a_fYaw,
					 GLfloat a_fPitch);
	//Return the view matrix
	glm::mat4 GetInverseView() const;
	glm::mat4 GetView() const;
	glm::mat4 GetProjection(float a_fNearPlane = 0.01f, float a_fFarPlane = 100000.0f) const;
	glm::mat4 GetProjectionView() const;

	//Keyborad input processor.
	void KeyboardInput(CameraMovement a_eDir, GLfloat a_fDeltaTime);
	//Mouse input processor.
	void MouseInput(GLfloat a_fOffsetX,
					GLfloat a_fOffsetY,
					GLboolean a_bConstrainPitch = true);

	void MouseScrollZoom(GLfloat a_fOffsetY);

	void SetReferenceOfScreen(glm::vec2 a_vScreenSize);

	glm::vec3 GetRayFromMouse(float a_fX, float a_fY);

	glm::vec3 PickAgainstPlain(float a_fX, float a_fY, glm::vec4 a_vPlane);

	//vec3 ScreenPositionToDir(float a_fX, float a_fY) const;

	GLfloat GetZoom() const;
	GLfloat GetYaw() const;
	GLfloat GetPitch() const;
};
#endif //!_CAMERA_H_