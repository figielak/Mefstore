CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

SRC_DIR := src
BUILD_DIR := build
DATA_SRC := $(SRC_DIR)/data
DATA_BUILD := $(BUILD_DIR)/data

SRCS := $(wildcard $(SRC_DIR)/*.cpp) \
        $(wildcard $(SRC_DIR)/core/*.cpp) \
        $(wildcard $(SRC_DIR)/ui/*.cpp)

OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

EXEC := $(BUILD_DIR)/Mefstore

all: $(EXEC) copy_data

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)       # tworzymy katalogi w build/ jeśli nie istnieją
	$(CXX) $(CXXFLAGS) -c $< -o $@

copy_data:
	@mkdir -p $(BUILD_DIR)
	@cp -r $(DATA_SRC) $(BUILD_DIR)/

clean:
	rm -rf $(BUILD_DIR)/*

run: all
	./$(EXEC)
