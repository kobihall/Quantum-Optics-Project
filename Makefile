CXX = g++
CXXFLAGS = -g -Wall -std=c++1y
LDFLAGS = -g
LDLIBS  =

EXECUTABLES = testODE1
OBJECTS = testODE1.o

.PHONY: default
default: $(EXECUTABLES)

$(EXECUTABLES): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJECTS): EulerStep.h

.PHONY: clean
clean:
		rm -f *~ a.out core $(OBJECTS) $(EXECUTABLES)

.PHONY: all
all: clean default