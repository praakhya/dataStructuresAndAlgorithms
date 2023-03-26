PROJNAME := horspool


SRCS = horspool.cpp \
programMain.cpp

OBJS := $(patsubst %.cpp,%.o,$(SRCS))

WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
            -Wredundant-decls -Wnested-externs -Winline \
            -Wuninitialized -Wconversion -Wstrict-prototypes

CXXFLAGS := -g $(WARNINGS)


all: $(PROJNAME)

.PHONY: all clean

clean:
	-@$(RM) $(wildcard $(OBJS) $(DEPS) $(PROJNAME))

-include $(DEPFILES)

$(PROJNAME): $(OBJS)
	@$(CXX) $(LDFLAGS) $^ -o $@

%.o: %.cpp Makefile
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@
