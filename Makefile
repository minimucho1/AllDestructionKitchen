# Project Variables
adk_NAME := adk
adk_TGT := obj

# SRC: Source files
adk_CXX_SRCS := $(notdir src/$(wildcard *.cpp))

# OBJS: Object files
adk_CXX_OBJS := $(addprefix obj/,$(notdir ${adk_CXX_SRCS:.cpp=.o}))

# Addtional include paths
adk_INCLUDE_PATHS := ./include ./SDL/include/SDL2 #-ISDL\include\SDL2 -I./include

# Addtional library paths
adk_LIBRARY_PATHS := ./SDL/lib #-LSDL\lib

# Addiontal libraries
adk_LIBRARIES := mingw32 SDL2main SDL2 SDL2_image

# Adds -I to every include path
CPPFLAGS += $(foreach includedir, $(adk_INCLUDE_PATHS), -I$(includedir))
CPPFLAGS += -Wl,-subsystem,windows

# Adds -L to every library path
LDFLAGS += $(foreach librarydir, $(adk_LIBRARY_PATHS), -L$(librarydir))

# Adds -I for every library
LDFLAGS += $(foreach library, $(adk_LIBRARIES), -l$(library))

# Phony Targets
.PHONY: all clean distclean

all: $(adk_NAME)

$(adk_NAME): $(adk_CXX_OBJS)
	$(LINK.cc) $(adk_CXX_OBJS) -o $(adk_NAME)

clean:
	@- $(RM) $(adk_NAME)
	@- $(RM) $(adk_CXX_OBJS)

disclean: clean
