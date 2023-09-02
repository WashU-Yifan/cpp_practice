Lab0 Yifan Wang 488500 wang.y1@wustl.edu 

Design of the printing format:

        The strategy I choose to print the deck is to print all cards with the same rank value in a row.
    As the number of cards with same rank value are fix for each game(4 for HoldEm, 8 for Pinochle),
    this would yield a cleaner printing result.

Correct Output of the program:
First trail:
    wang.y1@shell l0]$ ./lab0 
    9C 9C 9D 9D 
    9H 9H 9S 9S 
    JC JC JD JD 
    JH JH JS JS 
    QC QC QD QD 
    QH QH QS QS 
    KC KC KD KD 
    KH KH KS KS 
    10C 10C 10D 10D 
    10H 10H 10S 10S 
    AC AC AD AD 
    AH AH AS AS 
    print method1  done
    2C 2D 2H 2S 3C 3D 3H 3S 4C 4D 4H 4S 5C 5D 5H 5S 6C 6D 6H 6S 7C 7D 7H 7S 8C 8D 8H 8S 9C 9D 9H 9S 10C 10D 10H 10S JC JD JH JS QC QD QH QS KC KD KH KS AC AD AH AS  print method2  done

Second Trail:
    [wang.y1@shell l0]$ make
    g++ -o lab0 -DUNIX   -Wall -W -g -std=c++17 -DTEMPLATE_HEADERS_INCLUDE_SOURCE Suit.cpp PinochleDeck.cpp HoldEmDeck.cpp lab0.cpp 
    [wang.y1@shell l0]$ ./lab0 
    9C 9C 9D 9D 
    9H 9H 9S 9S 
    JC JC JD JD 
    JH JH JS JS 
    QC QC QD QD 
    QH QH QS QS 
    KC KC KD KD 
    KH KH KS KS 
    10C 10C 10D 10D 
    10H 10H 10S 10S 
    AC AC AD AD 
    AH AH AS AS 
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

Third Trail:
    [wang.y1@shell l0]$ ./lab0 
    9C 9C 9D 9D 9H 9H 9S 9S 
    JC JC JD JD JH JH JS JS 
    QC QC QD QD QH QH QS QS 
    KC KC KD KD KH KH KS KS 
    10C 10C 10D 10D 10H 10H 10S 10S 
    AC AC AD AD AH AH AS AS 
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
1. Forget to state #pragma once at the top of header files, result large amount of naming conflicts

2. 
    Card_T.h:9:31: error: stray ‘\357’ in program
     card_T(R _rank_, S _suit_)��� rank(_rank), suit(_suit){}

    ： from Chinese charactor differs with : in English
3. Defined the 
    template <typename R, typename S>std::ostream& operator<< (std::ostream& os,const card_T<R,S>& card)

    function inside the source file, result the undefined reference errors. Finally finds out that I forgot
    to include source file into the header file, resulting missing template implementation.

4.
    Card_T.h:9:38: error: ‘_rank’ was not declared in this scope
    card_T(R _rank_, S _suit_): rank(_rank), suit(_suit){}


This concludes most of the errors I ran into. Others are more likely typo/minor mistakes.


Warnings ran into:
1. Forgot to add return statement inside the prefix operator++.