CXX = g++
CXXFLAGS= -std=c++17 -Wall -g -O0 -fno-omit-frame-pointer -fsanitize=address,undefined

TARGET = pa3exe

SOURCE = main.cpp data.cpp Data_Struct_Wrap.cpp  

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

clean: 
	rm -f $(TARGET) *.o