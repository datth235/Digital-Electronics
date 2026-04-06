CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = app.exe

SRC = main.cpp fsm_graphviz.cpp gen_state_table.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)