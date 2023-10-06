1. Yifan Wang 488500 wang.y1@wustl.edu
     Duy Huynh 520644

Compile Time errors:
1.
   Deck/Card_T.cpp:19:31: error: type/value mismatch at argument 1 in template parameter list for ‘template<class> struct std::rank’
     return card1.rank < card2.rank;

     This is caused by adding using namespace std at the top of the source file. The compiler has mistakenly choose to 
     pattern match rank with std::rank instead of card.rank. Solved by explicitly scoping the class from STL.

2. got a compile time error for sorting the HoldEmHand struct. The error messages was long and inconclusive. It basically
says that if a member variable is a reference, the default operator= and move constructor is deleted, and thus std::sort()
can not be used. 

     Fixed by changing string reference to string.

Runtime Errors:

     I was luck enough to not face any runtime error that could crash the process. However, there is a small error causing
     the program to not sort playerhand + sharedhands deck, which was caused by evoking sort on the wrong vector.

     

In terms of behaving correctly, I have tested the program with serveral different 
command line arguments and the program bahaved as expected.

Example of the HoldEm game ouput of the eval feature:

     Current rank after flop:
     Player Name: 2, cardSet: 2H 4H 5D 6D 6S 
     Rank: pair
     Player Name: 4, cardSet: 2C 2H 5D 6S AC 
     Rank: pair
     Player Name: 5, cardSet: 2H 5D 6S JC QC 
     Rank: xhigh
     Player Name: 3, cardSet: 2H 5D 6S 7D AH 
     Rank: xhigh
     Player Name: 1, cardSet: 2H 3D 5D 6S 9D 
     Rank: xhigh
     BOARD (turn):6S 2H 5D 7C 
     BOARD (river):6S 2H 5D 7C 3H 

Example of the Pinochle game ouput of the eval feature:
     1
     9D JS QC QC 
     QD QS QS KS 
     10C 10D 10S AS 
     2
     9H JC JD QD 
     QH QH KH 10D 
     10H 10H 10S AD 
     3
     9C 9H 9S JC 
     JH KD KS 10C 
     AC AD AH AS 
     hundredaces 100
     4
     9C 9D 9S JD 
     JH JS KC KC 
     KD KH AC AH 