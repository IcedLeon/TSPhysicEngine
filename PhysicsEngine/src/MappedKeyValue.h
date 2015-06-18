/********************************************************************************/
/* [File]: MappedKeyValue.h														*/
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
#ifndef _MAPPEDKEYVALUE_H_
#define _MAPPEDKEYVALUE_H_
//Lib
#include <map>
#include <stdint.h>

template<class K, class V>
class MappedKeyValue
{
protected:
	std::map<K, V> m_oAllValues;

public:
	MappedKeyValue()
	{
	}

	virtual ~MappedKeyValue()
	{
		Clear();
	}

	virtual void Clear()
	{
		m_oAllValues.clear();
	}

	virtual typename std::map<K, V>::iterator Begin()
	{
		return m_oAllValues.begin();
	}

	virtual typename std::map<K, V>::const_iterator Begin() const
	{
		return m_oAllValues.begin();
	}

	virtual typename std::map<K, V>::iterator End()
	{
		return m_oAllValues.end();
	}

	virtual typename std::map<K, V>::const_iterator End() const
	{
		return m_oAllValues.end();
	}

	virtual bool Add(const K& key, const V& value)
	{
		if (m_oAllValues.find(key) != m_oAllValues.end())
		{
			return false;
		}

		m_oAllValues[key] = value;

		return true;
	}

	virtual void Replace(const K& key, const V& value)
	{
		m_oAllValues[key] = value;
	}

	virtual bool Remove(const K& key)
	{
		if (m_oAllValues.find(key) == m_oAllValues.end())
		{
			return false;
		}

		m_oAllValues.erase(key);

		return true;
	}

	virtual V Search(const K& key) const
	{
		auto result = m_oAllValues.find(key);

		if (result != m_oAllValues.end())
		{
			return result->second;
		}

		return V();
	}

	virtual bool Contains(const K& key) const
	{
		return m_oAllValues.find(key) != m_oAllValues.end();
	}

	virtual V& At(const K& key)
	{
		return m_oAllValues.at(key);
	}

	virtual const V& At(const K& key) const
	{
		return m_oAllValues.at(key);
	}

	virtual V& operator[](const K& key)
	{
		return m_oAllValues[key];
	}

	virtual const std::map<K, V>& GetAllValues() const
	{
		return m_oAllValues;
	}

	virtual std::int32_t Size() const
	{
		return m_oAllValues.size();
	}

};

#endif //!_MAPPEDKEYVALUE_H_