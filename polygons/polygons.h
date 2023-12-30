#ifndef POLYGONS_H
#define POLYGONS_H
#include <iostream>
#include <cmath>
#include <memory>

enum : int {PointA, PointB, PointC, PointD};

class Point {
	float x = 0, y = 0;

	public:
	Point() {};
	Point(float x, float y) : x(x), y(y) {}
	Point(const Point& other) : x(other.x), y(other.y) {}

	float distance(const Point& other) const {
			return std::sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
	}

	float getX() const {return x + 1;}
	float getY() const {return y + 1;}

	Point& operator=(const Point& other) {
		if (this != &other) {
			x = other.x;
			y = other.y;
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Point& p) {
		stream << p.x << ", " << p.y << std::endl;
		return stream;
	}

	friend std::istream& operator>>(std::istream& in, Point& p) {
		in >> p.x >> p.y;
		return in;
	}
};

class Polygon {
	int n = 1;

	protected:
	std::unique_ptr<Point[]> topPoints;

	void init() {
		for (int i = 0; i < n - 1; i++) {
			std::cin >> topPoints[i];
			std::cout << " next Point" << std::endl;
		}
		std::cin >> topPoints[n - 1];
	}

	public:
	Polygon(int n) : n(n), topPoints(std::make_unique<Point[]>(n)) {init();}

	void setTopPoint(int k) {std::cin >> topPoints[k - 1];}
	Point getTopPoint(int k) const {return topPoints[k - 1];}

	float length() const {
		float l = 0;
		for (int i = 0; i < n; i++)
			l += topPoints[i].distance(topPoints[i + 1]);
		return l;
	}

	float area() const {
		float d1 = 0, d2 = 0;
		for (int i = 0; i < n - 1; i++) {
			d1 += (topPoints[i].getX() * topPoints[i + 1].getY());
			d2 += (topPoints[i].getY() * topPoints[i + 1].getX());
		}
		d1 += (topPoints[n - 1].getX() * topPoints[0].getY());
		d2 += (topPoints[n - 1].getY() * topPoints[0].getX());

		return std::abs(d1 - d2) / 2;
	}

	bool isConvex() const {
		bool b = true;
		for (int i = 1; i < n - 1; i++) {
			Point ab(topPoints[i].getX() - topPoints[i - 1].getX(), topPoints[i].getY() - topPoints[i - 1].getY());
			Point bc(topPoints[i + 1].getX() - topPoints[i].getX(), topPoints[i + 1].getY() - topPoints[i].getY());
			float p = ab.getX() * bc.getY() - ab.getY() * bc.getX();
			if (p < 0) {
				b = false;
				break;
			}
		}
		return b;
	}

	bool isPointIn(const Point& point) const {
		bool result = false;
		int j = n - 1;
		for (int i = 0; i < n; i++) {
			if (((topPoints[i].getY() < point.getY() && topPoints[j].getY() >= point.getY()) || (topPoints[j].getY() < point.getY() && topPoints[i].getY() >= point.getY())) && (topPoints[i].getX() (point.getY() - topPoints[i].getY()) / (topPoints[j].getY() - topPoints[i].getY()) * (topPoints[j].getX() - topPoints[i].getX()) < point.getX()))
				result = !result;
			j = i;
		}
		return result;
	}

	bool isCross(const Polygon& p) const {
		float r;
		bool b = true;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				r = (topPoints[i].getX() - topPoints[i + 1].getX()) * (p.getTopPoint(j).getY() - p.getTopPoint(j).getY()) - (topPoints[i].getX() - topPoints[i + 1].getX()) * (p.getTopPoint(j).getY() - p.getTopPoint(j).getY());
				if (r != 0) {
					b = false;
					break;
				}
			}
		}
		return b;
	}
};

class Triangle : public Polygon {
	public:
	Triangle(const Point& pointA, const Point& pointB, const Point& pointC) : Polygon(3) {
		topPoints[PointA] = pointA;
		topPoints[PointB] = pointB;
		topPoints[PointC] = pointC;
	}
	float areaTriangle() {
		float side1 = distance(topPoints[PointA], topPoints[PointB]);
		float side2 = distance(topPoints[PointB], topPoints[PointC]);
		float side3 = distance(topPoints[PointC], topPoints[PointA]);
		float s = (side1 + side2 + side3) / 2;
		float area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
		return area;
	}
	float perimeterTriangle() {
		float side1 = distance(topPoints[PointA], topPoints[PointB]);
		float side2 = distance(topPoints[PointB], topPoints[PointC]);
		float side3 = distance(topPoints[PointC], topPoints[PointA]);
		return side1 + side2 + side3;
	}

	float distance(const Point& p1, const Point& p2) {
		return sqrt((p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) + (p1.getY() - p2.getY()) * (p1.getY() - p2.getY()));
	}
};

class Square : public Polygon {
	public:
	Square(const Point& pointA, const Point& pointB, const Point& pointC, const Point& pointD) : Polygon(4) {
		topPoints[PointA] = pointA;
		topPoints[PointB] = pointB;
		topPoints[PointC] = pointC;
		topPoints[PointD] = pointD;
		try {
			if (!isSquare())
				throw("Coordinates don't form a square \n");
		}
		catch (const char* err_msg) {
			std::cout << err_msg;
		}
	}

	float distance(const Point& p1, const Point& p2) {
		return sqrt((p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) + (p1.getY() - p2.getY()) * (p1.getY() - p2.getY()));
	}

	bool isSquare() {
		float side1 = distance(topPoints[PointA], topPoints[PointB]);
		float side2 = distance(topPoints[PointB], topPoints[PointC]);
		float side3 = distance(topPoints[PointC], topPoints[PointD]);
		float side4 = distance(topPoints[PointD], topPoints[PointA]);
		float diagonal1 = distance(topPoints[PointA], topPoints[PointC]);
		float diagonal2 = distance(topPoints[PointB], topPoints[PointD]);
		return (side1 == side2 && side2 == side3 && side3 == side4 && diagonal1 == diagonal2 && side1 * side1 + side2 * side2 == diagonal1 * diagonal1);
	}

	float areaSquare() {
		float side = distance(topPoints[0], topPoints[1]);
		return side * side;
	}

	float perimeterSquare() {
		float side = distance(topPoints[0], topPoints[1]);
		return 4 * side;
	}
};
#endif // POLYGONS_H