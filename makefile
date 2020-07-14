# Source: http://web.engr.oregonstate.edu/~rookert/cs162/03.mp4

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o determinant.o helperFunctions.o readMatrix.o
SRCS = main.cpp determinant.cpp helperFunctions.cpp readMatrix.cpp
HEADERS = determinant.hpp helperFunctions.hpp readMatrix.hpp

lab1: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o lab1

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o lab1
