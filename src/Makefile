all: main

clean:
	rm -f main *.o

.PHONY: all clean

CXX = g++
CPPFLAGS =
CXXFLAGS = -std=c++17 -Wall -g #-Wextra 
LIBS	 = -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -pthread -lXi -ldl -lXinerama -lXcursor -lGLEW
LDFLAGS  = 
OBJECTS  = shader.o		 vertex_array.o		vertex_buffer.o		element_buffer.o	texture.o			 	 rectangle.o   square.o			  color.o			  point.o
HEADERS  = shader.h		 vertex_array.h		vertex_buffer.h		element_buffer.h	texture.h				 drawable.h    rectangle.h		  square.h			  color.h			  point.h
CPPS	 = shader.cpp	 vertex_array.cpp	vertex_buffer.cpp	element_buffer.cpp	texture.cpp				 rectangle.cpp square.cpp		  color.cpp			  point.cpp


main: main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) -o $@ $^ $(LIBS)

main.o: main.cpp $(HEADERS) 
	$(CXX) $(CXXFLAGS) -c main.cpp $(CPPS)
	
shader.o: shader.h shader.cpp
	$(CXX) $(CXXFLAGS) -c shader.cpp

vertex_array.o: vertex_array.h vertex_array.cpp
	$(CXX) $(CXXFLAGS) -c vertex_array.cpp

vertex_buffer.o: vertex_buffer.h vertex_buffer.cpp
	$(CXX) $(CXXFLAGS) -c vertex_buffer.cpp

element_buffer.o: element_buffer.h element_buffer.cpp
	$(CXX) $(CXXFLAGS) -c element_buffer.cpp

texture.o: texture.h texture.cpp
	$(CXX) $(CXXFLAGS) -c texture.cpp

color.o: color.h color.cpp
	$(CXX) $(CXXFLAGS) -c color.cpp

point.o: point.h point.cpp
	$(CXX) $(CXXFLAGS) -c point.cpp

rectangle.o: rectangle.h rectangle.cpp
	$(CXX) $(CXXFLAGS) -c rectangle.cpp

square.o: square.h sqaure.cpp
	$(CXX) $(CXXFLAGS) -c square.cpp
