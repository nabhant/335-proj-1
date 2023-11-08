#include <iostream>
#include <algorithm>
#include "Hand.hpp"

// Big Five and constructor
        /**
         * @post: Construct a new Hand object
         */
        Hand::Hand(){}

        /**
         * @post: Destroy the Hand object
         */
        Hand::~Hand(){}

        /**
         * Copy Constructor
         * @param: other Hand object
         */
        Hand::Hand(const Hand& other){
            cards_ = other.cards_;
        }
            
        /**
         * Copy Assignment Operator
         * @param: other Hand object
         * @return this Hand 
         */
        Hand& Hand::operator=(const Hand& other){
            if (this == &other) { 
                return *this;
            }
            cards_ = other.cards_;
            return *this;
        }

        /**
         * Move Constructor
         * @param: other Hand object
         */
        Hand::Hand(Hand&& other){
            cards_ = std::move(other.cards_);
        }

        /**
         * 
         * Move assignment operator
         * @param: other Hand object
         * @return this Hand
         */
        Hand& Hand::operator=(Hand&& other){
            if (this == &other){
                return *this;
            }
            cards_ = std::move(other.cards_);
        }

        /**
         * @return Hand
         */
        const std::deque<PointCard>& Hand::getCards() const{
            return cards_;
        }
        
        /**
         * @post: Add a card to the hand
         * @param PointCard object
         */
        void Hand::addCard(PointCard&& card){
            card.setDrawn(true);
            cards_.push_back(std::move(card));
        }

        /**
         * @return true if hand is empty, false otherwise
         */
        bool Hand::isEmpty() const{
            return cards_.empty();
        }

        /**
         * @post: Reverse the hand
         */
        void Hand::Reverse(){
            int i = 0;
            int j = cards_.size()-1;

            while (i < j) {
                std::swap(cards_[i], cards_[j]);
                i++;
                j--;
            }
        }

        /**
         * @post: Play the card at the front of the hand, removing it from the hand
         * Throws an exception if the hand is empty or the card is not playable
         * If the card is not playable, the card is removed from the hand
         * @return the points earned from playing the card
         */
        int Hand::PlayCard(){
             if (!isEmpty()) {
                int points_ = 0; // We will still play the card if its point value is 0

                if(cards_.front().isPlayable()) {
                    points_ = std::stoi(cards_.front().getInstruction());
                    cards_.pop_front();
                    return points_;
                }
        
                cards_.pop_front();
                return points_;
            }
        }