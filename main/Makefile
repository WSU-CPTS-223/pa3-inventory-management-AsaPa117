# Collect all .cpp files in the current directory
SRC = $(wildcard *.cpp)

# Create matching .o object file names
OBJ = $(SRC:.cpp=.o)

# Name of the final executable
TARGET = mainexe

# Build target (compile all .cpp into .o, then link into executable)
compile: $(OBJ)
	@g++ -g -Wall -std=c++17 -I. $(OBJ) -o $(TARGET)


# Run the program
execute: $(TARGET)
	@./$(TARGET)

# Clean up all generated files
clean:
	@rm -rf $(OBJ) $(TARGET)
