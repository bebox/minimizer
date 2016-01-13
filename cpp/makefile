CXX = g++
# You may need to change -std=c++11 to -std=c++0x if your compiler is a bit older
CXXFLAGS = -Wall -c -std=c++11
LDFLAGS = $()
EXE = minimizer

all: $(EXE)

$(EXE): minimizer.o
	$(CXX) $< $(LDFLAGS) -o $@

main.o: minimizer.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)
