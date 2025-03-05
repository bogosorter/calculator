# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11 -I. -fsanitize=address

# Directories
SRC_DIR = .
ELEMENTS_DIR = elements
PARSER_DIR = parser

# Source files
SRCS = $(SRC_DIR)/calculator.cpp \
       $(ELEMENTS_DIR)/division.cpp \
       $(ELEMENTS_DIR)/integer.cpp \
       $(ELEMENTS_DIR)/multiplication.cpp \
       $(ELEMENTS_DIR)/subtraction.cpp \
       $(ELEMENTS_DIR)/sum.cpp \
       $(PARSER_DIR)/parser.cpp

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = calculator

# Default target
all: $(TARGET)

# Linking the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean