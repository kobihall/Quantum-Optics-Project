CXX = g++
CXXFLAGS = -g -Wall -std=c++1y
LDFLAGS = -g
LDLIBS  =

EXECUTABLES = testODE1 testODE2
OBJECTS = testODE1.o testODE2.o RK4Step.o DensityMatrix.o

.PHONY: default
default: $(EXECUTABLES)

testODE1: testODE1.o RK4Step.o DensityMatrix.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@
	chmod +x testODE1

testODE2: testODE2.o RK4Step.o DensityMatrix.o
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@
	chmod +x testODE2

%.o: %.cpp RK4Step.h DensityMatrix.h
	$(CXX) $(LDFLAGS) -c $<
#$(OBJECTS): RK4Step.h

.PHONY: clean
clean:
	rm -f *~ a.out core $(OBJECTS) $(EXECUTABLES)

.PHONY: all
all: clean default