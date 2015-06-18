/********************************************************************************/
/* [File]: Color.h																*/
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
#ifndef _COLOR_H_
#define _COLOR_H_
//Libs
#include "UsedLibs.h"

class Color
{
private:
	vec4 m_vRGBA;

public:
	const static Color WHITE;
	const static Color WHITE_TRANSPARENT;
	const static Color BLACK;
	const static Color BLACK_TRANSPARENT;
	const static Color RED;
	const static Color RED_TRANSPARENT;
	const static Color GREEN;
	const static Color GREEN_TRANSPARENT;
	const static Color BLUE;
	const static Color BLUE_TRANSPARENT;
	const static Color YELLOW;
	const static Color YELLOW_TRANSPARENT;
	const static Color MAGENTA;
	const static Color MAGENTA_TRANSPARENT;
	const static Color CYAN;
	const static Color CYAN_TRANSPARENT;
	const static Color BRIGHT_GREY;
	const static Color BRIGHT_GREY_TRANSPARENT;
	const static Color GREY;
	const static Color GREY_TRANSPARENT;
	const static Color DARK_GREY;
	const static Color DARK_GREY_TRANSPARENT;

	const static Color DEFAULT_EMISSIVE;
	const static Color DEFAULT_AMBIENT;
	const static Color DEFAULT_DIFFUSE;
	const static Color DEFAULT_SPECULAR;
	const static Color DEFAULT_REFLECTION;
	const static Color DEFAULT_REFRACTION;

public:
	Color();

	Color(float a_fLuminance);
	Color(const vec3& a_vRGB);
	Color(const vec4& a_vRGBA);
	Color(float a_fR, float a_fG, float a_fB);
	Color(float a_fR, float a_fG, float a_fB, float a_fA);
	Color(const float a_fRGBA[4]);

	Color(std::uint8_t a_iLuminance);
	Color(std::uint8_t a_iR, std::uint8_t a_iG, std::uint8_t a_iB);
	Color(std::uint8_t a_iR, std::uint8_t a_iG, std::uint8_t a_iB, std::uint8_t a_iA);
	Color(const std::uint8_t a_iRGBA[4]);

	Color(const Color& a_oSrc);
	~Color();

	void SetLuminance(float a_fLuminance);
	void SetLuminance(std::uint8_t a_iLuminance);
	void SetRBGA(const vec4& a_vRGBA);
	void SetRBGA(float a_fR, float a_fG, float a_fB, float a_fA);
	void SetRBGA(const float a_fRGBA[4]);
	void SetRBGA(std::uint8_t a_iR, std::uint8_t a_iG, std::uint8_t a_iB, std::uint8_t a_iA);
	void SetRBGA(const std::uint8_t a_iRGBA[4]);

	void SetR(float a_fR);
	float GetR() const;

	void SetG(float a_fG);
	float GetG() const;

	void SetB(float a_fB);
	float GetB() const;

	void SetA(float a_fA);
	float GetA() const;
	
	const vec4& GetRGBA() const;
};

#endif //!_COLOR_H_