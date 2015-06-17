#include "Bar.h"

//void Bar::InitTweek()
//{
//	//if (TwInit(TW_OPENGL, NULL))
//	//	printf("-- ANTTWEEKBAR INIT SUCCESSFULLY. \n");
//	//else
//	//	fprintf(stderr, "%s");
//}
//
//void Bar::CreateBar(const char* a_sNewBarName)
//{
//	m_mpTweekBar[a_sNewBarName] = TwNewBar(a_sNewBarName);
//}
//
//TwBar* Bar::GetMappedBar(const char* a_sBarName)
//{
//	//Checks if the bar has been mapped.
//	if (m_mpTweekBar.find(a_sBarName) != m_mpTweekBar.end())
//	{
//		return m_mpTweekBar[a_sBarName];
//	}
//	else
//	{
//		printf("ERROR: <COULD NOT FIND '%s' BAR FROM THE MAP. CHECK IF BAR HAS BEEN INIT BEFORE> \n", a_sBarName);
//		return nullptr;
//	}
//}
//
//void Bar::DrawTweek()
//{
//	TwDraw();
//}
//
//void Bar::CleanUpTweek()
//{
//	TwDeleteAllBars();
//	TwTerminate();
//}
//
//void Bar::ScaleTweek(int a_iWidth, int a_iHeight)
//{
//	TwWindowSize(a_iWidth, a_iHeight);
//}
//
//void Bar::AddTweakColor3f(const char* a_pccDivisor, const char* a_pccName, vec3 a_vCol, const char* a_pccDefinition)
//{
//	TwAddVarRW(m_mpTweekBar[a_pccDivisor], a_pccName, TW_TYPE_COLOR3F, &a_vCol, a_pccDefinition);
//}
//
//void Bar::AddTweakColor4f(const char* a_pccDivisor, const char* a_pccName, vec4 a_vCol, const char* a_pccDefinition)
//{
//	TwAddVarRW(m_mpTweekBar[a_pccDivisor], a_pccName, TW_TYPE_COLOR4F, &a_vCol, a_pccDefinition);
//}
//
//void Bar::AddTweakDir3f(const char* a_pccDivisor, const char* a_pccName, vec3 a_vDir, const char* a_pccDefinition)
//{
//	TwAddVarRW(m_mpTweekBar[a_pccDivisor], a_pccName, TW_TYPE_DIR3F, &a_vDir, a_pccDefinition);
//}