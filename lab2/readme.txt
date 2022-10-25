            CSE428 Lab2 
Yifan Wang|488500|wang.y1@wustl.edu 

PinochleGame.cpp:
    void check_same_rank(std::vector<Card_T<PinochleRank,Suit> >*,std::vector<PinochleMelds>&);
        Utilize unordered_set to records the number of different suits in the same rank. Due to logical
    errors, the first card was not counted.