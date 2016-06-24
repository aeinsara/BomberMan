
# Makefile for BomberMam

CXX = g++
CFLAGS = -O2 -g -pipe -I.
LIBS =-lsfml-graphics -lsfml-window -lsfml-system

OBJ_DIR = .

HDRS = $(wildcard *.hpp)
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

TARGET = ./main
 
TOUCH = touch
RM = rm -f

.PHONY: all run clean touch

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) $(LIBS) -o $(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

run:
	$(TARGET)

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)

touch:
	$(TOUCH) $(wildcard *)
	
	



