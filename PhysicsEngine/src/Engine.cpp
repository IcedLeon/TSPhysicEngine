#include "Engine.h"

void Engine::Render()
{

}

void Engine::Update(float a_fDeltaT)
{

}

void Engine::OnResize(GLint a_iWidth, GLint i_iHeight)
{

}

void Engine::OnKey(GLint a_iKey, GLint a_iAction)
{

}

void Engine::OnMouseButton(GLint a_iButton, GLint a_iAction)
{

}

void Engine::OnMouseMove(GLdouble a_dMouseX, GLdouble a_dMouseY)
{

}

void Engine::OnMouseWheel(GLdouble a_dPosition)
{

}

Engine::Engine()
{

}

Engine::Engine(vec3 a_vCamPos, ivec2 a_vScreenSize, const char* a_pccWinName, bool a_bFullScreen)
{

}

Engine::~Engine()
{

}

void Engine::Init(BaseApplication* a_oCurrApp, vec3 a_vCamPos, ivec2 a_vScreenSize,
	const char* a_pccWinName, bool a_bFullScreen)
{
	App::BaseApplication::Init(a_oCurrApp, a_vCamPos, a_vScreenSize, a_pccWinName, a_bFullScreen);

	
}