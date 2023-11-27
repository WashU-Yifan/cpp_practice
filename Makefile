#		The name of the executable file you want to build
EXECUTABLE	= lab1

#		Source (.cpp) files you want to compile
#		(NOTE: Don't include header (.h) files, or any source (.cpp) files
#		that only contain template class method definitions.)
CMPL_SRCS	= Deck/Suit.cpp Deck/PinochleDeck.cpp Deck/HoldEmDeck.cpp lab1.cpp Game/Game.cpp Game/HoldEmGame.cpp Game/PinochleGame.cpp

#               Source files containing only template class method definitions
TMPL_SRCS	= Deck/Card_T.cpp Deck/CardSet.cpp Deck/Deck.cpp

#               Header (.h) files
HEADER_FILES    = Deck/Suit.h Deck/Card_T.h Deck/Deck.h Deck/PinochleDeck.h Deck/HoldEmDeck.h Deck/CardSet.h Game/Game.h Game/HoldEmGame.h Game/PinochleGame.h

#               Any special flags that should be set for compilation
SPECIAL_FLAGS  = -std=c++17 -DTEMPLATE_HEADERS_INCLUDE_SOURCE
#SPECIAL_FLAGS  = -std=c++17

#               Any additional libraries that need to be linked in (e.g., -lsocket -lnsl)
LIBS    =       

#
#################### DO NOT CHANGE ANYTHING BELOW THIS LINE ###################

#		C++ compiler
CXX		= g++

#               All your source files (needed for executable dependency)
USER_SRCS        = $(CMPL_SRCS) $(TMPL_SRCS) $(HEADER_FILES)

#               The name of the compiler
CCC      = $(CXX)

#              Names of object files (from names of source files)
OBJS     = $(CMPL_SRCS:.cc=.o)

#               Any define flags that should be set for conditional compilation
DEFFLAGS  = -DUNIX

#               Any general flags that should be set for the compiler
#               NOTE: to optimize fully, change -g to -O4
CXXFLAGS  =     -Wall -W -g $(SPECIAL_FLAGS)

#               Any -I directories in which there are .h files that should be included
INCFLAGS  =
#               Flags that are specific to SUN object code
SUNFLAGS  =  #-misalign

#               The concatenation of all the flags that the compiler should get
CCFLAGS = $(DEFFLAGS) $(INCFLAGS) $(SUNFLAGS) $(CXXFLAGS)

###
# Targets
###

#               Special target for environments like Eclipse that want "all"
all: $(EXECUTABLE)

#               Construct the executable
$(EXECUTABLE): $(OBJS)
	$(CXX) -o $(EXECUTABLE) $(CCFLAGS) $(OBJS) $(LIBS)

#		Remove all junk that might be lying around
clean:
	-rm -f *.o core *.bak *~

realclean: clean
	-rm -f $(EXECUTABLE)

#		Change the Makefile to reflect the correct dependencies.
depend:
	-rm -f ccdep
	-rm -f eddep
	$(CXX) -xM $(CCFLAGS) $(CMPL_SRCS) > ccdep
	sed -n '1,/^# DO NOT DELETE THIS LINE/p' Makefile > eddep
	echo \#\#\# >> eddep
	cat ccdep >> eddep
	cp Makefile Makefile.bak
	mv eddep Makefile
	rm ccdep

.SUFFIXES: .cpp
.cpp.o:
	$(COMPILE.cc) $(CCFLAGS) $(OUTPUT_OPTION) $<
.cpp:
	$(LINK.cc) $(LDFLAGS) -o $@ $< $(LDLIBS)

main.o: $(USER_SRCS) Makefile

###
# OBJECT FILE DEPENDENCIES FOLLOW.
#
# DO NOT DELETE THIS LINE -- make depend uses it
###