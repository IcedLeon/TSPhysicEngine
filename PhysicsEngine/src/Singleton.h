/********************************************************************************/
/* [File]: Singleton.h															*/
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
#ifndef _SINGLETON_H_
#define _SINGLETON_H_

template<class S>
class Singleton
{
private:
	static S* m_oInstance;

public:
	Singleton() {}
	virtual ~Singleton() {}

	static S* GetInstance()
	{
		if (!m_oInstance)
		{
			m_oInstance = new S();
		}

		return m_oInstance;
	}

	static void Terminate()
	{
		if (m_oInstance)
		{
			delete m_oInstance;

			m_oInstance = nullptr;
		}
	}
};

template<class S>
S* Singleton<S>::m_oInstance = nullptr;

#endif //!_SINGLETON_H_