Lab1 Yifan Wang 488500 wang.y1@wustl.edu 

Difficulties ran into:

Compiling issue:
    In HoldEmGame::print and PinochleGame::print
        Forget to remove the definition and declaration of print from HoldEmDeck and PinochleDeck. 
        Although the compilation succeed, the correct version of print was not excuted.

    In Makefile
        Didn't remove the extra R in the Makefile's flag, leads to linking errors.

    In HoldEmGame::printstatus and PinochleGame::printstatus
        The
Runtime Issue:

    In HoldEmGame::HoldEmGame and PinochleGame::PinochleGame
        Decide to initialize HoldEmGame's PLayerHands vector with HoldEmDeck constructor, causing
        players to have all the cards at the begining.

    In HoldEmGame::Collect_hands
        forget to collect the Shared deck.

    In PinochleGame::deal and HoldEmGame::deal
        Used auto playerhand instead of auto& playerhand. The value instead of reference of 
        the CardSet object was passed into the block. Then the modification on the object will not 
        persist, leading to invalid deal().

Design of the printing format:

        The way I choose to print the deck is to iterate through the suit for each rank.
    As the number of suit are currently fixed (4) but the rank number varies betwwen each game.
    This gives a cleaner printing format.

