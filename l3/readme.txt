lab3
Yifan Wang 488500 wang.y1@wustl.edu
Duy Huynh 520644

At stage of step 8:
     Compile time error:
          Fix some iterator typename errors. 

          modifies some functions' signature since the break of encapsulation
          would cause some objects to lose their constness inside the function.
     
     Run time error:
          Fix the command line argument bug that crash the program.

At stage of step 12:
     Compile time error:
          Game/../Deck/CardSet.cpp:62:108: error: ‘rank’ is not captured
          auto iter = std::find(cardSet.getDeckBegin(), cardSet.getDeckEnd(), [](auto& card){return card.rank == rank;});
                               
At stage of step 24:
     Compile time error:
          In file included from lab3.cpp:8:
          Game/GoFishGame.h:32:9: error: ‘Deck’ is not a template
               Deck<R, S> deck;
               ^~~~
          make: *** [lab3] Error 1
     This is due to Deck class and the template parameter having same name.

     /tmp/cc6Mk0jL.o: In function `void __gnu_cxx::new_allocator<GoFishGame<UnoRank, Color, Uno> >::construct<GoFishGame<UnoRank, Color, Uno>, int, char const**>(GoFishGame<UnoRank, Color, Uno>*, int&&, char const**&&)':
/project/engineering/compilers/gcc-8.3.0/include/c++/8.3.0/ext/new_allocator.h:136: undefined reference to `GoFishGame<UnoRank, Color, Uno>::GoFishGame(int, char const**)'
     This is due to not implementing the pure virtual function.

     /project/engineering/compilers/gcc-8.3.0/include/c++/8.3.0/bits/predefined_ops.h:241:17: error: no match for ‘operator==’ (operand types are ‘Card_T<UnoRank, Color>’ and ‘const CardSet<R, S>::request(CardSet<R, S>&, R) [with R = UnoRank; S = Color]::<lambda(auto:1&)>’)
  { return *__it == _M_value; }
     Thi is because find is used instead of find_if in the request function


     g++ -o lab3 -DUNIX   -Wall -W -g -std=c++17 -DTEMPLATE_HEADERS_INCLUDE_SOURCE Deck/Suit.cpp Deck/PinochleDeck.cpp Deck/HoldEmDeck.cpp lab3.cpp Game/Game.cpp Game/HoldEmGame.cpp Game/PinochleGame.cpp 
     /tmp/cclJCpoH.o: In function `GoFishGame<UnoRank, Color, Uno>::GoFishGame(int, char const**)':
     /home/warehouse/wang.y1/428/l3/Game/GoFishGame.cpp:34: undefined reference to `Uno::Uno()'
     /tmp/cclJCpoH.o:(.rodata._ZTV10GoFishGameI7UnoRank5Color3UnoE[_ZTV10GoFishGameI7UnoRank5Color3UnoE]+0x28): undefined reference to `GoFishGame<UnoRank, Color, Uno>::~GoFishGame()'
     /tmp/cclJCpoH.o:(.rodata._ZTV10GoFishGameI7UnoRank5Color3UnoE[_ZTV10GoFishGameI7UnoRank5Color3UnoE]+0x30): undefined reference to `GoFishGame<UnoRank, Color, Uno>::~GoFishGame()'
     /tmp/cclJCpoH.o:(.rodata._ZTV10GoFishGameI12PinochleRank4Suit8PinochleE[_ZTV10GoFishGameI12PinochleRank4Suit8PinochleE]+0x28): undefined reference to `GoFishGame<PinochleRank, Suit, Pinochle>::~GoFishGame()'
     /tmp/cclJCpoH.o:(.rodata._ZTV10GoFishGameI12PinochleRank4Suit8PinochleE[_ZTV10GoFishGameI12PinochleRank4Suit8PinochleE]+0x30): undefined reference to `GoFishGame<PinochleRank, Suit, Pinochle>::~GoFishGame()'
     /tmp/cclJCpoH.o:(.rodata._ZTV10GoFishGameI10HoldEmRank4Suit6HoldEmE[_ZTV10GoFishGameI10HoldEmRank4Suit6HoldEmE]+0x28): undefined reference to `GoFishGame<HoldEmRank, Suit, HoldEm>::~GoFishGame()'
     /tmp/cclJCpoH.o:(.rodata._ZTV10GoFishGameI10HoldEmRank4Suit6HoldEmE[_ZTV10GoFishGameI10HoldEmRank4Suit6HoldEmE]+0x30): undefined reference to `GoFishGame<HoldEmRank, Suit, HoldEm>::~GoFishGame()'
     /tmp/cclJCpoH.o: In function `std::ostream& operator<< <UnoRank, Color>(std::ostream&, Card_T<UnoRank, Color> const&)':
     /home/warehouse/wang.y1/428/l3/Deck/Card_T.cpp:11: undefined reference to `operator<<(std::ostream&, UnoRank)'
     /home/warehouse/wang.y1/428/l3/Deck/Card_T.cpp:11: undefined reference to `operator<<(std::ostream&, Color)'
     collect2: error: ld returned 1 exit status
     not updating the MAKEFILE

     Runtime Errors:
          Mostly some game logic errors and index out of bounds errors.

Example trails ran for the GoFish game:
     Since the GoFish Game has a considerably longer gaming peroid than other card games.
     I revisd the PinochleDeck constructor so that there will be only 24 cards in the deck.

     I have tested the following scenarios:
     when current player input a player number that does not exist.
     when current player request a card rank that does not exist.
     when current player GoFish and the common deck is empty.
     when current player request a rank from another player and that player does not have that rank.
     When the game ends due to insufficient player.
     When the game ends due to deck being empty.





