#include "PhxTiming.h"
#include <windows.h>
#include <mmsystem.h>

static double _qpcFreq;
static bool _qpcFlag;

unsigned systemTime()
{
	if (_qpcFlag)
	{
		static LONGLONG _qpxMillSecPerTick;
		QueryPerformanceCounter((LARGE_INTEGER*)&_qpxMillSecPerTick);
		return (unsigned)(_qpxMillSecPerTick * _qpcFreq);
	}
	else
	{
		/* NOTE!!!!!!!: In order to the timeGetTime func, yopu should link
		winmm.lib into your project. Once linked you can get rid of the
		unresolved external symbol. Also make note that if you define 
		WIN32_LEAN_AND_MEAN this func would not be available.*/
		return unsigned(timeGetTime());
	}
}

unsigned PhxTimeData::GetTime()
{
	return systemTime();
}

unsigned long systemClock()
{
	__asm {
		rdtsc;
	}
}

unsigned long PhxTimeData::GetClock()
{
	return systemClock();
}

void initTime()
{
	LONGLONG _time;

	_qpcFlag = (QueryPerformanceFrequency((LARGE_INTEGER*)&_time) > 0);

	/*Check if we have access to the performance counter at this resolution*/
	if (_qpcFlag)
		_qpcFreq = 1000.0 / _time;
}

static PhxTimeData* _timingData = NULL;

PhxTimeData& PhxTimeData::Get()
{
	return (PhxTimeData&)*_timingData;
}

void PhxTimeData::Update()
{
	if (!_timingData)
		return;

	/*increment the frame number*/
	if (!_timingData->m_bIsPaused)
		_timingData->m_uFrameNum++;

	unsigned _currentTime = systemTime();
	_timingData->m_ulLastFrameClockTicks =
		_currentTime - _timingData->m_ulLastFrameClockstamp;
	_timingData->m_ulLastFrameClockstamp = _currentTime;

	/*Update the RWA frame rate if we are able to.*/
	if(_timingData->m_uFrameNum > 1)
	{
		if (_timingData->m_dAvgFrameDuration <= 0)
		{
			_timingData->m_dAvgFrameDuration = (double)_timingData->m_uLastFrameDuration;
		}
		else
		{
			/*RWA over 100 frames.*/
			_timingData->m_dAvgFrameDuration *= 0.99;
			_timingData->m_dAvgFrameDuration += 0.01 * (double)_timingData->m_uLastFrameDuration;

			/*invert to get the fps*/
			_timingData->m_fFps = (float)(1000.0 / _timingData->m_dAvgFrameDuration);
		}
	}
}

void PhxTimeData::Init()
{
	initTime();

	if (!_timingData)
		_timingData = new PhxTimeData();

	_timingData->m_uFrameNum = 0;

	_timingData->m_ulLastFrameClockstamp = systemTime();
	_timingData->m_uLastFrameDuration = 0;

	_timingData->m_ulLastFrameClockstamp = GetClock();
	_timingData->m_ulLastFrameClockTicks = 0;

	_timingData->m_bIsPaused = false;

	_timingData->m_dAvgFrameDuration = 0;

	_timingData->m_fFps = 0;
}

void PhxTimeData::De_Init()
{
	delete _timingData;
	_timingData = NULL;
}