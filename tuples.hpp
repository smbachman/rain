class Tuple {
  public:
    Tuple();
    Tuple(double x, double y, double z, double w);
		
		bool operator==(const Tuple& rhs) const;
		Tuple operator+(const Tuple& rhs) const;
		Tuple operator-(const Tuple& rhs) const;
		Tuple operator-() const;
		Tuple operator*(double scalar) const;
		Tuple operator/(double scalar) const;
    
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
  private:
    double x;
    double y;
    double z;
    double w;
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