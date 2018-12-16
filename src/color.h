#ifndef COLOR_H
#define COLOR_H

enum class Shade
{
	RED,
	GREEN,
	BLUE,
	BLACK,
	WHITE
};

class Color
{
	public:
		Color(float red, float green, float blue);
		Color(Shade shade);

		void setRed(float red);
		void setGreen(float green);
		void setBlue(float blue);

		float red() const;
		float green() const;
		float blue() const;

	private:
		float red_;
		float green_;
		float blue_;
};

#endif //COLOR_H
