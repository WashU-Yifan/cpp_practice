1. Yifan Wang 488500 wang.y1@wustl.edu
     Duy Huynh 520644

Errors for step 7:
    Bad name for card_T class, didn't capitalize the starting char of class

    CardSet.cpp:6:6: error: ‘template<class R, class S> class CardSet’ used without template parameters
 void CardSet::print(std::ostream& os, size_t size) {
      ^~~~~~~
    Caused by forgot to add template declaration at the begining of the definition of the print method

Errors for step 8:
     have to manually add CardSet<R, S>:: before the deck iterator or otherwise the compiler fails to 
     compile.

Errors in Step 16:

Forgot to modify the makefile after changing the lab structure
     [wang.y1@linuxlab009 l1]$ make
     make: *** No rule to make target `Suit.cpp', needed by `lab1'.  Stop.
     
Some syntax errors:

     Game/PinochleGame.h:17:39: error: ISO C++ forbids declaration of ‘PinocleGame’ with no type [-fpermissive]
         PinocleGame(int, const char **);
                                       ^
     Game/PinochleGame.h:19:2: error: expected ‘;’ after class definition
     }

     Game/Game.h:9:9: error: ‘vector’ does not name a type; did you mean ‘perror’?
         vector<std::string> players;
         ^~~~~~
         perror
     Game/Game.cpp: In constructor ‘Game::Game(int, char**)’:
     Game/Game.cpp:5:15: error: ‘class Game’ has no member named ‘players’; did you mean ‘play’?
          this->players.push_back(players[i]);
                    ^~~~~~~
                    play


     Game/HoldEmGame.cpp:39:9: note: suggested alternative: ‘pselect’
         collect(playerHands[i]);
         ^~~~~~~
         pselect
     Game/HoldEmGame.cpp:41:5: error: ‘collect’ was not declared in this scope
          collect(sharedHands);
          ^~~~~~~
     Game/HoldEmGame.cpp:41:5: note: suggested alternative: ‘pselect’
          collect(sharedHands);
     ^~~~~~~


     Game/PinochleGame.cpp: In member function ‘virtual void PinochleGame::deal()’:
     Game/PinochleGame.cpp:13:19: error: ‘inddex’ was not declared in this scope
          index = ++inddex % argc;
                    ^~~~~~
     Game/PinochleGame.cpp:13:19: note: suggested alternative: ‘index’
          index = ++inddex % argc;
                    ^~~~~~
                    index

Runtime Errors:

     caused by failing to check the deck size
     [wang.y1@linuxlab009 l1]$ ./lab1 Pinochle 1 2 3 4
     1
     2
     3
     4
     Segmentation fault (core dumped)

     [wang.y1@linuxlab008 l1]$ ./lab1 HoldEm 1 2
1
JH 7S 2
5C 8D BOARD (turn):QC 7C JC BOARD (river):QC 7C JC 9H Continue Game? [yes/no]


In terms of behaving correctly, I have tested the program with serveral different 
command line arguments and the program bahaved as expected.