# Define the compiler
CC = g++
CFLAGS = -Wall -std=c++17

# Specify source files
SRCS = list.cpp
OBJ = list.o

# Define the executable
TARGET = list

# Default rule (build the executable)
all: $(TARGET)

# Compile source files into an executable
$(TARGET): $(OBJ)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile object files
%.o: %.cpp
    $(CC) $(CFLAGS) -c $< -o $@

# Run tests (check target)
check: $(TARGET)
    ./$(TARGET)

# Clean compiled files
clean:
    rm -f $(OBJ) $(TARGET)
