CXX ?= g++
LDFLAGS = -Wall
LDLIBS =

TARGET = $(notdir $(basename $<))
SRC_DIRS ?= ./src

SRCS := main.cc $(shell find $(SRC_DIRS) -name "*.cc" -or -name "*.c" -or -name "*.s")
OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

FLAGS ?= $(INC_FLAGS) -MMD -MP

all: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o out $(LDLIBS)
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)
