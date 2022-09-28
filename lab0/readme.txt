Lab0 Yifan Wang 488500 wang.y1@wustl.edu 

Design of the printing format:

        The way I choose to print the deck is to iterate through the suit for each rank.
    As the number of suit are currently fixed (4) but the rank number varies betwwen each game.
    This gives a cleaner printing format.

Correct Output of the program:
./lab0[wang.y1@shell lab0]$ ./lab0
9C 9D 9H 9S 
JC JD JH JS 
QC QD QH QS 
KC KD KH KS 
10C 10D 10H 10S 
AC AD AH AS 
9C 9D 9H 9S 
JC JD JH JS 
QC QD QH QS 
KC KD KH KS 
10C 10D 10H 10S 
AC AD AH AS 
 print method1  done
2C 2D 2H 2S 
3C 3D 3H 3S 
4C 4D 4H 4S 
5C 5D 5H 5S 
6C 6D 6H 6S 
7C 7D 7H 7S 
8C 8D 8H 8S 
9C 9D 9H 9S 
10C 10D 10H 10S 
JC JD JH JS 
QC QD QH QS 
KC KD KH KS 
AC AD AH AS 
 print method2  done




Errors ran into:
1. Forget to state #pragma once at the top of header files, result large naming conflict

2. Forget to add :: operator before the member function's signature in source file.

3. Defined the 
    template <typename R, typename S>std::ostream& operator<< (std::ostream& os,const card_T<R,S>& card)

    function inside the source file, result the undefined reference errors.

This concludes most of the errors I ran into. Others are more like typo/minor mistakes.


Warnings ran into:
1. used int instead of type_size for the index type in vector iteration. 
2. include pragma once in source file.