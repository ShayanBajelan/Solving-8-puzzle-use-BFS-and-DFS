CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c -O3
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS = ./Node.o ./main.o
GTEST = /usr/local/lib/libgtest.a
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST)
./Node.o: ./Node.cpp
	$(CXX) $(CXXFLAGS) ./Node.cpp -o ./Node.o
./main.o: ./main.cpp
	$(CXX) $(CXXFLAGS) ./main.cpp -o ./main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)