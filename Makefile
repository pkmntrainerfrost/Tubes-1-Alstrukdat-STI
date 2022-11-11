# ########################################################################
# ####################### Makefile Template ##############################
# ########################################################################

# # Compiler settings - Can be customized.
# CC = gcc
# CXXFLAGS = -std=c11 -Wall
# LDFLAGS = 

# # Makefile settings - Can be customized.
# APPNAME = BNMO
# EXT = .c
# SRCDIR = ./src
# OBJDIR = obj

# ############## Do not change anything from here downwards! #############
# SRC = $(wildcard $(SRCDIR)/*$(EXT))
# OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
# DEP = $(OBJ:$(OBJDIR)/%.o=%.d)
# # UNIX-based OS variables & settings
# RM = rm
# DELOBJ = $(OBJ)
# # Windows OS variables & settings
# DEL = del
# EXE = .exe
# WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

# ########################################################################
# ####################### Targets beginning here #########################
# ########################################################################

# all: $(APPNAME)

# # Builds the app
# $(APPNAME): $(OBJ)
# 	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# # Creates the dependecy rules
# %.d: $(SRCDIR)/%$(EXT)
# 	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

# # Includes all .h files
# -include $(DEP)

# # Building rule for .o files and its .c/.cpp in combination with all .h
# $(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
# 	$(CC) $(CXXFLAGS) -o $@ -c $<

# ################### Cleaning rules for Unix-based OS ###################
# # Cleans complete project
# .PHONY: clean
# clean:
# 	$(RM) $(DELOBJ) $(DEP) $(APPNAME)

# # Cleans only all files with the extension .d
# .PHONY: cleandep
# cleandep:
# 	$(RM) $(DEP)

# #################### Cleaning rules for Windows OS #####################
# # Cleans complete project
# .PHONY: cleanw
# cleanw:
# 	$(DEL) $(WDELOBJ) $(DEP) $(APPNAME)$(EXE)

# # Cleans only all files with the extension .d
# .PHONY: cleandepw
# cleandepw:
# 	$(DEL) $(DEP)


compile:
	gcc -o main ./main.c ./src/Utility/splash.c ./src/Misc/io/io.c ./src/ADT/word/word.c ./src/ADT/list/array.c ./src/ADT/queue/queue2.c ./src/Utility/start/start.c ./src/Utility/load/load.c ./src/Utility/help/help.c ./src/Utility/commandlain/commandlain.c ./src/Utility/quit/quit.c ./src/Utility/listGame/listGame.c ./src/Utility/deleteGame/deleteGame.c ./src/Utility/playGame/playGame.c ./src/Utility/queuegame/queueGame.c ./src/Utility/skipGame/skipGame.c ./src/Utility/save/save.c ./src/Misc/ascii/ascii.c ./src/ADT/word/mesinkarakter/mesinkarakter.c ./src/ADT/word/mesinkata/mesinkata.c ./src/Games/battleship/battleship.c ./src/Games/rng/rng.c ./src/Games/dinerdash/dinerdash.c ./src/Games/random.c ./src/ADT/point/point.c ./src/ADT/queue/prioqueue.c

compile2:
	gcc -o main .\main.c .\src\Utility\splash.c .\src\Misc\io\io.c .\src\ADT\word\word.c .\src\ADT\list\array.c .\src\ADT\queue\queue2.c .\src\Utility\start\start.c .\src\Utility\load\load.c .\src\Utility\help\help.c .\src\Utility\commandlain\commandlain.c .\src\Utility\quit\quit.c .\src\Utility\listGame\listGame.c .\src\Utility\deleteGame\deleteGame.c .\src\Utility\playGame\playGame.c .\src\Utility\queuegame\queueGame.c .\src\Utility\skipGame\skipGame.c .\src\Utility\save\save.c .\src\Misc\ascii\ascii.c .\src\ADT\word\mesinkarakter\mesinkarakter.c .\src\ADT\word\mesinkata\mesinkata.c .\src\Games\battleship\battleship.c .\src\Games\rng\rng.c .\src\Games\dinerdash\dinerdash.c .\src\Games\random.c .\src\ADT\point\point.c .\src\ADT\queue\prioqueue.c