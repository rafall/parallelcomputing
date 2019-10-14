CXX	:=	-gcc
CXXFLAGS	:=	-Wall
LDFLAGS	:=	-L/usr/lib  -lm -openmp
BUILD	:=	./build
OBJ_DIR	:=	$(BUILD)/objects
APP_DIR	:=	$(BUILD)/apps
TARGET	:=	erastothenes
TARGET_PARALLEL	:=	parallel_erastothenes
SRC :=	$(wildcard *.c)

OBJECTS :=	$(SRC:%.c=$(OBJ_DIR)/%.o)

all:	build $(APP_DIR)/$(TARGET) $(APP_DIR)/$(TARGET_PARALLEL)

$(OBJ_DIR)/%.o: $.c
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir =p $(@D)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJECTS)

$(APP_DIR)/$(TARGET_PARALLEL): $(OBJECTS)
	@mkdir =p $(@D)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET_PARALLEL) $(OBJECTS)

.PHONY: all build clean

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)
	
clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf #(APP_DIR)/*
