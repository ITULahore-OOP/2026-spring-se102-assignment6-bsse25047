CXX = g++
CXXFLAGS = -std=c++17 -Wall
SRC = Hero.cpp Warrior.cpp Knight.cpp MagicalEntity.cpp Spellblade.cpp Guild.cpp

# Usage: make run
run: clean
	$(CXX) $(CXXFLAGS) main.cpp $(SRC) -o app.out
	./app.out

# Usage: make test
test: clean
	$(CXX) $(CXXFLAGS) test.cpp $(SRC) -o test.out
	./test.out

# Usage: make grade
grade: clean
	$(CXX) $(CXXFLAGS) hiddenTest.cpp $(SRC) -o grade.out
	./grade.out

clean:
	rm -f *.out *.o *.exe