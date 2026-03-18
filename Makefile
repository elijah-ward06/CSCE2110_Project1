CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Itools

SRCS := $(wildcard *.cpp) $(wildcard tools/*.cpp)

OBJS := $(SRCS:.cpp=.o)

TARGET = project1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all