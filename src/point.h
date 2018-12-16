#ifndef POINT_H
#define POINT_H

class Point
{
	public:
		Point(float x, float y);

		bool operator==(const Point& other);
		float x() const;
		float y() const;

		void x(const float x);
		void y(const float y);

	private:
		float x_;
		float y_;
};

#endif //POINT_H
