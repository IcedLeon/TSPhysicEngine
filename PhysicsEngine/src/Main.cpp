//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	XXXXXXXXXXXXXXXX   X           X  XX           X      XXXXXXXXXXXX    XXX     XXXXXXXXXXXXX    XXX            XXXXXXXX      XXXXXXXXXXXX	//
//	X              X   X           X   XX         XX    XXX        XX     XXX   XXXX        XX     XXX      XXXXXXX           XXX        XX 	//
//	X              X   X           X    XX       XX    XX                 XXX   XX                 XXX     XX                XX             	//
//	X              X   X           X     XX     XX     X                  XXX   X                  XXX    XX                 X              	//
//	X              X   X           X      XXX  XX      X                  XXX   X                  XXX    X                  X              	//
//	X              X   X           X        XX X       XXXXX              XXX   XXXXX              XXX    X                  XXXXX          	//
//	XXXXXXXXXXXXXXXX   XXXXXXXXXXXXX         XXX           XXXXXXXXXX     XXX       XXXXXXXXXX     XXX    X                      XXXXXXXXXX 	//
//	X                  X           X         XX                     XX    XXX                XX    XXX    X                               XX	//
//	X                  X           X         XX                      X    XXX                 X    XXX    X                                X	//
//	X                  X           X         XX                      X    XXX                 X    XXX    X                                X	//
//	X                  X           X         XX                     XX    XXX                XX    XXX    XX                              XX	//
//	X                  X           X         XX                    XX     XXX               XX     XXX     XX                            XX 	//
//	X                  X           X         XX        XX        XXX      XXX   XX        XXX      XXX      XXXXXXX          XX        XXX  	//
//	X                  X           X         XX       XXXXXXXXXXXX        XXX  XXXXXXXXXXXX        XXX            XXXXXXXX  XXXXXXXXXXXX    	//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/********************************************************************************/
/* [File]: Main.cpp																*/
/* [Description]: The main, here the program run and perform other task.		*/
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
#include "Engine.h"

int main()
{
	Engine* _app = new Engine();

	_app->Init(_app, vec3(0, 0, 0), ivec2(0, 720), "TEST", false);

	_app->RunApp();

	_app = nullptr;

	return 0;
}