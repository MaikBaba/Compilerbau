# -----------------------------
# Make settings
# -----------------------------

MAKEFLAGS=

# -----------------------------
# Compiler settings
# -----------------------------

CC  := gcc
CXX := g++
LD  := g++
RM  := rm
FLEX := flex
BISON := bison

# -----------------------------
# Project settings
# -----------------------------

PROJNAME		 := compilerbau
PROJNAME_DEBUG   := $(PROJNAME)_debug
PROJNAME_RELEASE := $(PROJNAME)

# -----------------------------
# Directory settings
# -----------------------------

INCLUDE_DIR := /usr/local/lib/llvm-3.8/include

# -----------------------------
# Compiler flags
# -----------------------------

WFLAGS	   := -Wall -Wextra -pedantic -Wdouble-promotion -Wformat=2 -Winit-self \
				-Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wunused-local-typedefs \
				-Wunused -Wuninitialized -Wstrict-overflow=5 \
				-Wundef -Wshadow -Wunsafe-loop-optimizations \
				-Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings \
				-Wconversion -Wlogical-op \
				-Wmissing-field-initializers \
				-Wmissing-format-attribute -Wpacked -Winline -Wredundant-decls \
				-Wvector-operation-performance -Wdisabled-optimization \
				-Wstack-protector -Wfloat-equal -Wsuggest-attribute=pure \
				-Wsuggest-attribute=const -Wsuggest-attribute=noreturn \
				-Wold-style-cast
CWFLAGS	  := -Wdeclaration-after-statement -Wc++-compat -Wbad-function-cast \
				-Wstrict-prototypes -Wmissing-prototypes -Wnested-externs -Wunsuffixed-float-constants
#-Wzero-as-null-pointer-constant -Wpadded
DEBUGFLAGS   := -g3 -O0
RELEASEFLAGS := -g0 -O3 -flto
CFLAGS	   := -std=c11
CXXFLAGS	 := -std=c++11
INCLUDEFLAGS := $(foreach inc,$(INCLUDE_DIR),-I $(inc))

# -----------------------------
# Linker flags
# -----------------------------

LFLAGS := -L/usr/lib/llvm-3.8/lib
LIBS   := LLVM-3.8

# -----------------------------
# Some automatic stuff
# -----------------------------

LFLAGS += $(foreach lib,$(LIBS),-l$(lib))

CSRCFILES := $(shell find . -name "*.c")
COBJFILES := $(patsubst %.c,%.o,$(CSRCFILES))
CDEPFILES := $(patsubst %.c,%.d,$(CSRCFILES))
CXXSRCFILES := $(shell find . -name "*.C")
CXXOBJFILES := $(patsubst %.C,%.o,$(CXXSRCFILES))
CXXDEPFILES := $(patsubst %.C,%.d,$(CXXSRCFILES))

SRCFILES := $(CSRCFILES) $(CXXSRCFILES) Lexer.C Parser.C
OBJFILES := $(COBJFILES) $(CXXOBJFILES)
DEPFILES := $(CDEPFILES) $(CXXDEPFILES)

OBJFILES_DEBUG   := $(patsubst %.o,debug/%.o,$(OBJFILES))
OBJFILES_RELEASE := $(patsubst %.o,release/%.o,$(OBJFILES))

DEPFILES_DEBUG   := $(patsubst %.d,debug/%.d,$(DEPFILES))
DEPFILES_RELEASE := $(patsubst %.d,release/%.d,$(DEPFILES))

# -----------------------------
# Make targets
# -----------------------------

.PHONY: all debug relase clean

all: $(PROJNAME_DEBUG) $(PROJNAME_RELEASE) Makefile
	@echo "  [ finished ]"

debug: $(PROJNAME_DEBUG) Makefile
	@echo "  [ done ]"

release: $(PROJNAME_RELEASE) Makefile
	@echo "  [ done ]"

-include $(DEPFILES_DEBUG)
-include $(DEPFILES_RELEASE)

$(PROJNAME_DEBUG): $(OBJFILES_DEBUG) $(SRCFILES) Makefile
	@echo "  [ Linking $@ ]" && \
	$(LD) $(OBJFILES_DEBUG) -o $@ $(LFLAGS)

$(PROJNAME_RELEASE): $(OBJFILES_RELEASE) $(SRCFILES) Makefile
	@echo "  [ Linking $@ ]" && \
	$(LD) $(OBJFILES_RELEASE) -o $@ $(LFLAGS) $(RELEASEFLAGS)

debug/%.o: %.c Makefile
	@echo "  [ Compiling $< (DEBUG) ]" && \
	mkdir debug/$(dir $<) -p && \
	$(CC) $(CFLAGS) $(WFLAGS) $(CWFLAGS) $(DEBUGFLAGS) $(INCLUDEFLAGS) -MMD -MP -c $< -o $@

debug/%.o: %.C Makefile
	@echo "  [ Compiling $< (DEBUG) ]" && \
	mkdir debug/$(dir $<) -p && \
	$(CXX) $(CXXFLAGS) $(WFLAGS) $(DEBUGFLAGS) $(INCLUDEFLAGS) -MMD -MP -c $< -o $@

release/%.o: %.c Makefile
	@echo "  [ Compiling $< (RELEASE) ]" && \
	mkdir release/$(dir $<) -p && \
	$(CC) $(CFLAGS) $(WFLAGS) $(CWFLAGS) $(RELEASEFLAGS) $(INCLUDEFLAGS) -MMD -MP -c $< -o $@

release/%.o: %.C Makefile
	@echo "  [ Compiling $< (RELEASE) ]" && \
	mkdir release/$(dir $<) -p && \
	$(CXX) $(CXXFLAGS) $(WFLAGS) $(RELEASEFLAGS) $(INCLUDEFLAGS) -MMD -MP -c $< -o $@

Lexer.C: CPP.l
	${FLEX} -oLexer.C CPP.l

Parser.C: CPP.y
	${BISON} CPP.y -o Parser.C

clean:
	-@$(RM) -f $(wildcard $(OBJFILES_DEBUG) $(OBJFILES_RELEASE) $(DEPFILES_DEBUG) $(DEPFILES_RELEASE) $(PROJNAME_DEBUG) $(PROJNAME_RELEASE)) Lexer.C Parser.C && \
	$(RM) -rf debug release && \
	echo "  [ done ]"
