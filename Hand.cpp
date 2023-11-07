#include "Hand.hpp"

// Big Five and constructor
        /**
         * @post: Construct a new Hand object
         */
        Hand::Hand(){
            
        }

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
            if (this != &other){
                cards_ = other.cards_;
            }
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
            if (this != &other){
                cards_ = std::move(other.cards_);
            }
            return *this;
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
            std::reverse(cards_.begin(), cards_.end());
        }

        /**
         * @post: Play the card at the front of the hand, removing it from the hand
         * Throws an exception if the hand is empty or the card is not playable
         * If the card is not playable, the card is removed from the hand
         * @return the points earned from playing the card
         */
        int Hand::PlayCard(){
            if(isEmpty()){
                throw std::runtime_error("Hand is empty. Cannnot play a card.");
            }

            // Get the card at the front
            PointCard frontCard = std::move(cards_.front());

            // Remove the card from your hand
            cards_.pop_front();

            // Check if the card is playable
            if (frontCard.isPlayable())
                return stoi(frontCard.getInstruction()); // Returns the point value
            else
                return 0;
        }