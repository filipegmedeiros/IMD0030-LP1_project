# -------------------------------
# Author: filipegmedeiros
# Date  : 03/05/19
# -------------------------------


include doc/help.mk

PROG = petfera

INCDIR = ./include
SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin

CC = g++
CFLAGS = -O0 -g -Wall -pedantic -std=c++11 -I$(INCDIR)
RM = rm

HEADERS := $(wildcard $(INCDIR)/*)
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)



all: project ##@Compilar Compila o programa.


project: $(OBJECTS) $(HEADERS) | $(BINDIR)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(BINDIR)/$(PROG)


$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

# Clean PHONY targets
.PRONY: clean clean_proj

clean: clean_proj ##@Clean Limpa a pasta obj e bin.

clean_proj:
	@echo "Removing OBJDIR..."
	@$(RM) -r $(OBJDIR)
	@echo "Removing BINDIR..."
	@$(RM) -r $(BINDIR)
	@$(RM) -f $(PROG)
	@echo "Clean-up completed!"
