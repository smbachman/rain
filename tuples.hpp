class BaseTuple {
	public:
		BaseTuple();
		BaseTuple(double a, double b, double c, double d);
		
		bool operator==(const BaseTuple& rhs) const;
		BaseTuple operator+(const BaseTuple& rhs) const;
		BaseTuple operator-(const BaseTuple& rhs) const;
		BaseTuple operator-() const;
		BaseTuple operator*(double scalar) const;
		BaseTuple operator/(double scalar) const;
		double operator[](int index) const;
		
	protected:
		double a[4];
};

class Tuple : public BaseTuple {
  public:
    Tuple();
    Tuple(double x, double y, double z, double w);
		
    double getX();
    double getY();
    double getZ();
    double getW();
		
		double magnitude();
		Tuple normalize();
		double dot(const Tuple& rhs);
		Tuple cross(const Tuple& rhs);
    
    bool isPoint();
    bool isVector();
};

class Point : public Tuple {
	public:
		Point();
		Point(double x, double y, double z);
};

class Vector : public Tuple {
	public:
		Vector();
		Vector(double x, double y, double z);
};