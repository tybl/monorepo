CC := clang
TARGET := goon
OBJECTS = $(SOURCES:src/%.cpp=$(BLDDIR)/%.o)
DEPS = $(OBJECTS:.o=.d)
INCLUDES := -I src
SOURCES := src/main.cpp \
           src/Window.cpp

ifndef CONFIG
   CONFIG=Valgrind
endif

ifeq ($(CONFIG), San)
   BLDDIR := build/sanitize
   CFLAGS := -g3 -O0 -fsanitize=address
   LFLAGS := -g3 -O0 -fsanitize=address
endif

ifeq ($(CONFIG), Valgrind)
   BLDDIR := build/debug
   CFLAGS := -g3 -O0
   LFLAGS := -g3 -O0
endif

ifeq ($(CONFIG), Release)
   BLDDIR := build/release
   CFLAGS := -g0 -O3
   LFLAGS := -g0 -O3
endif

CFLAGS += -c -std=c++14 -stdlib=libc++ -Weverything -Wno-c++98-compat -pedantic -MP -MMD
LFLAGS += -lc++ -lc++abi -lSDL2

$(TARGET): $(OBJECTS)
	$(CC) $(LFLAGS) -o $@ $(OBJECTS)

$(BLDDIR):
	mkdir -p $(dir $(OBJECTS))

$(BLDDIR)/%.o: src/%.cpp | $(BLDDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $<

.PHONY: clean
clean:
	$(RM) -r build $(TARGET)

-include $(DEPS)
