/********************************************************************************/
/* [File]: UsedLibs.h															*/
/* [Description]: The propouse of this class is to wrap,						*/
/* all the current dependency of the MS to be extended to the whole project.	*/
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
#ifndef _USEDLIBS_H_
#define _USEDLIBS_H_

//MS
#include <algorithm>
#include <cstdint>
#include <map>
using std::map;
#include <memory>
#include <string>
using std::string;
#include <vector>
using std::vector;
//GL
#include "gl_core_4_4.h"
#define GLM_SWIZZLE
#include "glm\glm\glm.hpp"
#include "glm\glm\gtc\matrix_transform.hpp"
using glm::ivec2;
using glm::ivec3;
using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::mat3;
using glm::mat4;
using glm::lookAt;
using glm::radians;
using glm::normalize;
using glm::dot;
using glm::cross;
//GLFW
#include <glfw\include\GLFW\glfw3.h>
//Macros
#define MAX_KEYS	1024

#endif //!_USEDLIBS_H_