#include <iostream>
#include "Player.hpp"

    /**
    * @post: Construct a new Player object
    */
    Player::Player() {
        score_ = 0;
        opponent_ = nullptr;
        actiondeck_ = nullptr;
        pointdeck_ = nullptr;
    };

    /**
    * @post: Destroy the Player object
    */
    Player::~Player() {
        delete opponent_;    
        delete pointdeck_;
        delete actiondeck_;
        opponent_ = nullptr;
        pointdeck_ = nullptr;
        actiondeck_ = nullptr;
    };

    /**
    * @return the player’s hand
    */
    const Hand& Player::getHand() const {
        return hand_;
    };

    /**
    * @post: Set the player’s hand
    * @param const reference to a hand object
    */
    void Player::setHand(const Hand& hand) {
        hand_ = hand;
    };

    /**
    * @return the Player’s current score
    */
    int Player::getScore() const {
        return score_;
    };

    /**
    * @post: Set the player’s score
    * @param: score
    */
    void Player::setScore(const int& score) {
        score_ = score;
    };

    /**
    * @post: Play a given action card
    * @param: an Actioncard object
    * Begin the function by reporting the instruction of the card:
    * PLAYING ACTION CARD: [instruction]
    */
    void Player::play(ActionCard&& card) {
        if(card.getInstruction() == "REVERSE HAND") {    // Check which card and play its action
            std::cout << "PLAYING ACTION CARD: REVERSE HAND" << std::endl;
            hand_.Reverse();
            }
    
        else if (card.getInstruction() == "SWAP HAND WITH OPPONENT") {
            std::cout << "PLAYING ACTION CARD: SWAP HAND WITH OPPONENT" << std::endl;
            if(opponent_ != nullptr) {
                Hand temp = getHand();
                setHand(opponent_->getHand());
                opponent_->setHand(temp);
            }
        }
        else {
            std::vector<std::string> words;     // Break the instruction down word by word and store it in a vector
            std::string word = "";
            for (int i = 0; i < card.getInstruction().size(); i++) {
                if(card.getInstruction()[i] == ' ') {
                    words.push_back(word);
                    word = "";
                }
                else {
                    word += (card.getInstruction()[i]);    
                }
            }

            if (words[0] == "PLAY") {
                std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
                int count = std::stoi(words[1]);    // The second word in the instruction is the number of cards to draw or play
                for (int i = 0; i < count; i++) {
                    playPointCard();
                }
            }
            else if (words[0] == "DRAW") {
                std::cout << "PLAYING ACTION CARD: "<< card.getInstruction() << std::endl;
                int count = std::stoi(words[1]);
                for (int i = 0; i < count; i++) {
                    drawPointCard();
                }
            }
        }

    };

    /**
    * @post: Draw a point card and place it in the player’s hand
    */
    void Player::drawPointCard() {
        if (pointdeck_ != nullptr) {
            hand_.addCard(std::move(pointdeck_->Draw()));
        }
    };

    /**
    * @post: Play a point card from the player’s hand and update the player’
    s score
    */
    void Player::playPointCard() {
        if(!hand_.isEmpty())
            setScore(getScore() + hand_.PlayCard());
    };

    /**
    * @post: Set the opponent of the player
    * @param a pointer to a Player opponent
    */
    void Player::setOpponent(Player* opponent) {
        opponent_ = opponent;
    };

    /**
    * @return: a pointer to the player’s opponent
    */
    Player* Player::getOpponent() {
        return opponent_;
    };

    /**
    * @post: set the action deck of the player
    * @param: A pointer to a deck holding Action cards
    */
    void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
        actiondeck_ = actiondeck;
    };

    /**
    * @return a pointer to the player’s action deck
    */
    Deck<ActionCard>* Player::getActionDeck() {
        return actiondeck_;
    };

    /**
    * @post: set the point deck of the player
    * @param: A pointer to a deck holding Point cards
    */
    void Player::setPointDeck(Deck<PointCard>* pointdeck) {
        pointdeck_ = pointdeck;
    };

    /**
    * @return: a pointer to the player’s point deck
    */
    Deck<PointCard>* Player::getPointDeck() {
        return pointdeck_;
    };