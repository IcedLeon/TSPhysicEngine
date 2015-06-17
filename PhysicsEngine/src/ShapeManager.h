//#ifndef _SHAPEMANAGER_H_
//#define _SHAPEMANAGER_H_
////Lib
//#include <map>
//#include "Singleton.h"
//
//using std::map;
//
//template<class S>
//struct SubShapesMap
//{
//	map<std::string, S*> m_AllTheSubShapes;
//
//	SubShapesMap() : m_AllTheSubShapes() { }
//	SubShapesMap(const SubShapesMap& a_Rhs) 
//	{ 
//		if (this == a_Rhs)
//			return *this;
//	}
//	SubShapesMap& operator= (const SubShapesMap& a_oSource)
//	{
//		if (this == &a_oSource)
//			return *this;
//
//		DestroyShapeMap();
//
//		this->m_AllTheSubShapes = &a_oSource.m_AllTheSubShapes;
//
//		return *this;
//	}
//
//	DestroyShapeMap()
//	{
//		auto _walker = m_AllTheSubShapes.begin();
//
//		while (_walker != m_AllTheSubShapes.end())
//		{
//			_walker->second.reset();
//
//			_walker++;
//		}
//
//		m_AllTheSubShapes.clear();
//	}
//};
//
//class ShapeManager : public Singleton<ShapeManager>
//{
//	friend class Singleton < ShapeManager > ;
//
//private:
//	template<class S>
//	map<std::string, SubShapesMap<S>> m_oAllTheShapes;
//
//	ShapeManager();
//	virtual ~ShapeManager();
//
//	template<class S>
//	void AddToScene(const std::string& a_sID, const S& a_oShape);
//
//	void RemoveAll();
//
//public:
//	template<class S>
//	void RemoveFromScene(const std::string& a_sID);
//
//	template<class S>
//	S* GenerateShape(const std::string& a_sShapeName, const std::string& a_sID,
//		const S& a_oShape);
//};
//
//#endif //!_SHAPEMANAGER_H_