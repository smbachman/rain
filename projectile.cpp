#include <iostream>
using namespace std;
#include "tuples.hpp"

struct Projectile {
	Tuple position;
	Tuple velocity;
};

struct Environment {
	Tuple gravity;
	Tuple wind;
};

Projectile tick(Projectile proj, Environment env) {
	Projectile p;
	p.position = proj.position + proj.velocity;
	p.velocity = proj.velocity + env.gravity + env.wind;
	return p;
}

int main() {
	Projectile p;
	p.position = Point(0,1,0);
	p.velocity = Vector(1,1,0).normalize();
	
	Environment e;
	e.gravity = Vector(0,-0.1,0);
	e.wind = Vector(-0.01,0,0);
	
	int ticks = 0;
	do {
		cout << "tick " << ticks++ << " position ("
			<< p.position.getX() << ", " 
			<< p.position.getY() << ", "
			<< p.position.getZ() << ")" << endl;
			
		p = tick(p, e);
	} while (p.position.getY() > 0);
	
	cout << "Done after " << ticks - 1 << " ticks" << endl;
}