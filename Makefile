CXX=clang++

test: tuples.o test-tuples.o
	$(CXX) tuples.o test-tuples.o -o test
	
projectile: tuples.o projectile.o
	$(CXX) tuples.o projectile.o -o projectile

test-tuples.o: tuples.cpp tuples.hpp test-tuples.cpp
	$(CXX) -fno-exceptions -c test-tuples.cpp -o test-tuples.o
  
tuples.o: tuples.hpp tuples.cpp
	$(CXX) -c tuples.cpp -o tuples.o
	
projectile.o: tuples.hpp tuples.cpp projectile.cpp
	$(CXX) -c projectile.cpp -o projectile.o
