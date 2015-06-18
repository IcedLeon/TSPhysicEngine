#include "Color.h"

/*Define some default color palette, this are the most used */
const Color Color::WHITE = Color(1.0f, 1.0f, 1.0f, 1.0f);
const Color Color::WHITE_TRANSPARENT = Color(1.0f, 1.0f, 1.0f, 0.0f);
const Color Color::BLACK = Color(0.0f, 0.0f, 0.0f, 1.0f);
const Color Color::BLACK_TRANSPARENT = Color(0.0f, 0.0f, 0.0f, 0.0f);
const Color Color::RED = Color(1.0f, 0.0f, 0.0f, 1.0f);
const Color Color::RED_TRANSPARENT = Color(1.0f, 0.0f, 0.0f, 0.0f);
const Color Color::GREEN = Color(0.0f, 1.0f, 0.0f, 1.0f);
const Color Color::GREEN_TRANSPARENT = Color(0.0f, 1.0f, 0.0f, 0.0f);
const Color Color::BLUE = Color(0.0f, 0.0f, 1.0f, 1.0f);
const Color Color::BLUE_TRANSPARENT = Color(0.0f, 0.0f, 1.0f, 0.0f);
const Color Color::YELLOW = Color(1.0f, 1.0f, 0.0f, 1.0f);
const Color Color::YELLOW_TRANSPARENT = Color(1.0f, 1.0f, 0.0f, 0.0f);
const Color Color::MAGENTA = Color(1.0f, 0.0f, 1.0f, 1.0f);
const Color Color::MAGENTA_TRANSPARENT = Color(1.0f, 0.0f, 1.0f, 0.0f);
const Color Color::CYAN = Color(0.0f, 1.0f, 1.0f, 1.0f);
const Color Color::CYAN_TRANSPARENT = Color(0.0f, 1.0f, 1.0f, 0.0f);
const Color Color::BRIGHT_GREY = Color(0.75f, 0.75f, 0.75f, 1.0f);
const Color Color::BRIGHT_GREY_TRANSPARENT = Color(0.75f, 0.75f, 0.75f, 0.0f);
const Color Color::GREY = Color(0.5f, 0.5f, 0.5f, 1.0f);
const Color Color::GREY_TRANSPARENT = Color(0.5f, 0.5f, 0.5f, 0.0f);
const Color Color::DARK_GREY = Color(0.25f, 0.25f, 0.25f, 1.0f);
const Color Color::DARK_GREY_TRANSPARENT = Color(0.25f, 0.25f, 0.25f, 0.0f);

const Color Color::DEFAULT_EMISSIVE = Color(0.0f, 0.0f, 0.0f, 1.0f);
const Color Color::DEFAULT_AMBIENT = Color(0.2f, 0.2f, 0.2f, 1.0f);
const Color Color::DEFAULT_DIFFUSE = Color(0.8f, 0.8f, 0.8f, 1.0f);
const Color Color::DEFAULT_SPECULAR = Color(0.0f, 0.0f, 0.0f, 1.0f);
const Color Color::DEFAULT_REFLECTION = Color(0.0f, 0.0f, 0.0f, 1.0f);
const Color Color::DEFAULT_REFRACTION = Color(0.0f, 0.0f, 0.0f, 1.0f);

Color::Color() : m_vRGBA(0.0f)
{
}

Color::Color(float a_fLuminance) : 
	m_vRGBA(a_fLuminance, a_fLuminance, a_fLuminance, 1.0f)
{
}

Color::Color(const vec3& a_vRGB) : m_vRGBA(a_vRGB.xyz(), 1.0f)
{
}

Color::Color(const vec4& a_vRGBA) : m_vRGBA(a_vRGBA)
{
}

Color::Color(float a_fR, float a_fG, float a_fB) : 
	m_vRGBA(a_fR, a_fG, a_fB, 1.0f)
{
}

Color::Color(float a_fR, float a_fG, float a_fB, float a_fA) : 
	m_vRGBA(a_fR, a_fG, a_fB, a_fA)
{
}

Color::Color(const float a_fRGBA[4]) : 
	m_vRGBA(a_fRGBA[0], a_fRGBA[1], a_fRGBA[2], a_fRGBA[3])
{
}

Color::Color(std::uint8_t a_iLuminance) : 
	m_vRGBA((float)a_iLuminance / 255.0f, 
			(float)a_iLuminance / 255.0f, 
			(float)a_iLuminance / 255.0f, 
			1.0f)
{
}

Color::Color(std::uint8_t a_iR, std::uint8_t a_iG, std::uint8_t a_iB) :
	m_vRGBA((float)a_iR / 255.0f,
			(float)a_iG / 255.0f,
			(float)a_iB / 255.0f,
			1.0f)
{

}

Color::Color(std::uint8_t a_iR, std::uint8_t a_iG, std::uint8_t a_iB, std::uint8_t a_iA) : 
	m_vRGBA((float)a_iR / 255.0f,
			(float)a_iG / 255.0f,
			(float)a_iB / 255.0f,
			(float)a_iA / 255.0f)
{
}

Color::Color(const std::uint8_t a_iRGBA[4]) : m_vRGBA((float)a_iRGBA[0] / 255.0f,
													  (float)a_iRGBA[1] / 255.0f,
													  (float)a_iRGBA[2] / 255.0f,
													  (float)a_iRGBA[3] / 255.0f)
{
}

Color::Color(const Color& a_oSrc) : m_vRGBA(a_oSrc.m_vRGBA)
{
}

Color::~Color()
{
}

void Color::SetLuminance(float a_fLuminance)
{
	this->m_vRGBA = vec4(a_fLuminance, a_fLuminance, a_fLuminance, 1.0f);
}

void Color::SetLuminance(std::uint8_t a_iLuminance)
{
	float _newLum = (float)a_iLuminance / 255.0f;
	this->m_vRGBA = vec4(_newLum, _newLum, _newLum, 1.0f);
}

void Color::SetRBGA(const vec4& a_vRGBA)
{
	this->m_vRGBA = a_vRGBA;
}

void Color::SetRBGA(float a_fR, float a_fG, float a_fB, float a_fA)
{
	this->m_vRGBA = vec4(a_fR, a_fG, a_fB, a_fA);
}

void Color::SetRBGA(const float a_fRGBA[4])
{
	this->m_vRGBA = vec4(a_fRGBA[0], a_fRGBA[1], a_fRGBA[2], a_fRGBA[3]);
}

void Color::SetRBGA(std::uint8_t a_iR, std::uint8_t a_iG, std::uint8_t a_iB, std::uint8_t a_iA)
{
	this->m_vRGBA = vec4((float)a_iR / 255.0f,
						 (float)a_iG / 255.0f,
						 (float)a_iB / 255.0f,
						 (float)a_iA / 255.0f);
}

void Color::SetRBGA(const std::uint8_t a_iRGBA[4])
{
	this->m_vRGBA = vec4((float)a_iRGBA[0] / 255.0f,
						 (float)a_iRGBA[1] / 255.0f,
						 (float)a_iRGBA[2] / 255.0f,
						 (float)a_iRGBA[3] / 255.0f);
}

void Color::SetR(float a_fR)
{
	this->m_vRGBA.r = a_fR;
}

float Color::GetR() const
{
	return this->m_vRGBA.r;
}

void Color::SetG(float a_fG)
{
	this->m_vRGBA.g = a_fG;
}

float Color::GetG() const
{
	return this->m_vRGBA.g;
}

void Color::SetB(float a_fB)
{
	this->m_vRGBA.b = a_fB;
}

float Color::GetB() const
{
	return this->m_vRGBA.b;
}

void Color::SetA(float a_fA)
{
	this->m_vRGBA.a = a_fA;
}

float Color::GetA() const
{
	return this->m_vRGBA.a;
}

const vec4& Color::GetRGBA() const
{
	return this->m_vRGBA;
}