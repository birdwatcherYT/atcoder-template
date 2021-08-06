SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
TARGETS = $(SOURCES:.cpp=.exe)
DEPENDS = $(SOURCES:.cpp=.d)

CXX      = g++
CXXFLAGS = -g -MMD -MP -Wall -Wextra -Winit-self -Wno-unused-parameter -std=c++17
RM       = rm -f
LDFLAGS  =
INCLUDE  = 
# INCLUDE  = -I ac-library

.PHONY:run
run:$(TARGETS) $(OBJECTS)

%.exe: %.o
	$(CXX) -o $@ $< $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

#クリーンして実行
.PHONY: all
all: clean run

#クリーン
.PHONY:clean
clean: 
	$(RM) $(TARGETS) $(OBJECTS) $(DEPENDS)


-include $(DEPENDS)
