
#ifndef _BAR_H_
#define _BAR_H_
//Lib
//#include <AntTweakBar.h>

//class Bar
//{
//private:
//	//Map of the tweek bars
//	map<const char*, TwBar*> m_mpTweekBar;

//	template <typename T>
//	struct TypeToTW
//	{
//		static const TwType value{ TW_TYPE_UNDEF };
//	};
//
//	template <>	struct TypeToTW<int> { static const TwType value{ TW_TYPE_INT32 }; };
//	template <>	struct TypeToTW<bool> { static const TwType value{ TW_TYPE_BOOLCPP }; };
//	template <>	struct TypeToTW<float> { static const TwType value{ TW_TYPE_FLOAT }; };
//	template <>	struct TypeToTW<double> { static const TwType value{ TW_TYPE_DOUBLE }; };
//
//public:
//	Bar() {}
//	~Bar() {}
//
//	//AntTweakBar initialise funcs
//	void InitTweek();
//
//	void CreateBar(const char* a_sNewBarName);
//	TwBar* GetMappedBar(const char* a_sBarName);
//
//	void DrawTweek();
//	void CleanUpTweek();
//	void ScaleTweek(int a_iWidth, int a_iHeight);
//
//	template<typename T>
//	inline void AddR_WTweak(const char* a_pccDivisor, const char* a_pccName, T a_Var, const char* a_pccDefinition);
//
//	template<typename T>
//	inline void AddR_OVar(const char* a_pccDivisor, const char* a_pccName, T a_Var, const char* a_pccDefinition);
//
//	void AddTweakColor3f(const char* a_pccDivisor, const char* a_pccName, vec3 a_vCol, const char* a_pccDefinition);
//	void AddTweakColor4f(const char* a_pccDivisor, const char* a_pccName, vec4 a_vCol, const char* a_pccDefinition);
//
//	void AddTweakDir3f(const char* a_pccDivisor, const char* a_pccName, vec3 a_vDir, const char* a_pccDefinition);
//};

//	template<typename T>
//	inline void AddR_WTweak(const char* a_pccDivisor, const char* a_pccName, T a_Var, const char* a_pccDefinition)
//	{
//		TwBar* _currBar = m_mpTweekBar[a_pccDivisor];
//	}

//	template<typename T>
//	inline void AddR_OVar(const char* a_pccDivisor, const char* a_pccName, T a_Var, const char* a_pccDefinition)
//	{
//		TwAddVarRO(m_mpTweekBar[a_pccDivisor], a_pccName, TypeToTW<T>::value, &a_Var, a_pccDefinition);
//	}

#endif //!_BAR_H_