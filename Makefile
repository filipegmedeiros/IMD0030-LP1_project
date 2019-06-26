# -------------------------------
# Author: filipegmedeiros
# Date  : 03/05/19
# -------------------------------


include doc/help.mk

PROG = petfera
PROGEXPORTED = exportedPetfera
LIB = petfera.so

INCDIR = ./include
SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
LIBDIR = ./lib

CC = g++
CFLAGS = -O0 -g -Wall -pedantic -std=c++11 -I$(INCDIR)
RM = rm

CC = g++
CFLAGS = -O0 -g -Wall -pedantic -std=c++11 -I$(INCDIR)
RM = rm

HEADERS := $(wildcard $(INCDIR)/*)
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)



all: project ##@Compilar Compila o programa petfera (Sem PIC)


project: $(OBJECTS) $(HEADERS) | $(BINDIR)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(BINDIR)/$(PROG)


$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


OBJSPIC := $(SOURCES:$(SRCDIR)/%.cpp=$(LIBDIR)/%.o)

EXCLUDED := $(SRCDIR)/main.cpp $(SRCDIR)/orchestrator.cpp $(SRCDIR)/manipulator.cpp
OBJS := $(EXCLUDED:$(SRCDIR)/%.cpp=$(LIBDIR)/%.o)
OBJECTS_FILTRED := $(filter-out $(OBJS),$(OBJSPIC))



export: runExport ##@Compilar Compila o programa export

runExport: makelib
	$(CC) $(CFLAGS) $(LIBDIR)/$(LIB) $(SRCDIR)/export.cpp $(SRCDIR)/main.cpp -o $(BINDIR)/$(PROGEXPORTED)

makelib: petfera.so ##@Gera a Biblioteca Dincamica.


petfera.so: $(OBJECTS_FILTRED) $(HEADERS) | $(BINDIR)
	$(CC) $(OBJECTS_FILTRED) $(CFLAGS) -shared -fPIC -o $(LIBDIR)/$(LIB)

$(OBJECTS_FILTRED): $(LIBDIR)/%.o : $(SRCDIR)/%.cpp $(HEADERS) | $(LIBDIR)
	$(CC) $(CFLAGS) -shared -fPIC -c $< -o $@



$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)
	
$(LIBDIR):
	@mkdir -p $(LIBDIR)


# Clean PHONY targets
.PRONY: clean clean_proj hahaha



clean: clean_proj ##@Clean Limpa a pasta obj e bin.

clean_proj:
	@echo "Removing OBJDIR..."
	@$(RM) -rf $(OBJDIR)
	@echo "Removing BINDIR..."
	@$(RM) -rf $(BINDIR)
	@$(RM) -f $(PROG)
	@echo "Removing LIBDIR..."
	@$(RM) -rf $(LIBDIR)
	@$(RM) -f $(LIB)
	@echo "Clean-up completed!"