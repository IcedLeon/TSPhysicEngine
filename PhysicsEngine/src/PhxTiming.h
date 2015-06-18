/********************************************************************************/
/* [File]: PhxTimeData.h														*/
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
#ifndef _PHXTIMING_H_
#define _PHXTIMING_H_
//Lib
#include "UsedLibs.h"

struct PhxTimeData
{
private:
	PhxTimeData() {}
	PhxTimeData(const PhxTimeData& a_Rhs) {}
	PhxTimeData& operator=(const PhxTimeData& a_Rhs);

public:
	/* 
	The current rendering frame.
	For semplicity it would be incrementing only. 
	*/
	unsigned m_uFrameNum;
	/* 
	The timestamp when the ;ast frame eneded. 
	Times are given in milliseconds since undefined time. 
	*/
	unsigned m_uLastFramestamp;
	/* 
	The duration of the last frame in milliseconds.
	*/
	unsigned m_uLastFrameDuration;
	/*
	The clockstamp of the end of the last frame.
	*/
	unsigned long m_ulLastFrameClockstamp;
	/*
	The duration of the last frame in ticks
	*/
	unsigned long m_ulLastFrameClockTicks;
	/*
	Keeps track of whether the rendering has been paused.
	*/
	bool m_bIsPaused;

	/* Calculated data */
	
	/*
	This value hold the recency weighted avarage of the last frame time,
	calculated form the duration between the current frame and the other.
	*/
	double m_dAvgFrameDuration;
	/*The reciprocal of the avarage frame duration givin the mean fps 
	over a recency weighted avarage.
	*/
	float m_fFps;
	/*
	Returns the global timing data object
	*/
	static PhxTimeData& Get();
	/*
	Updates the timing system (once per frame)
	*/
	static void Update();
	/*
	Initializes the fram information system. NOTE: If you want to initialiase
	all the modulles use the overall init func.
	*/
	static void Init();
	/*
	De-initialises the fram info system.
	*/
	static void De_Init();
	/*
	Gets the globals system time, in the best resolution possible.
	NOTE: Timing is in milliseconds
	*/
	static unsigned GetTime();
	/*
	Gets the clock ticks since the process has started.
	*/
	static unsigned long GetClock();
};

#endif //!_PHXTIMING_H_