#include "Card.hpp"

// Big Five and Constructor
        /**
         * Destructor
         * @post: Destroy the Card object
        */
        Card::~Card(){}

        /**
         * Copy Constructor
         * @post: Construct a new Card object
         * @param: const reference to a Card object
        */
        Card::Card(const Card& rhs){
            cardType_ = rhs.cardType_;
            instruction_ = rhs.instruction_;
            bitmap_ = rhs.bitmap_;
            drawn_ = rhs.drawn_;
        }

        /**
         * Copy Assignment Operator
         * @param const reference to a Card object
         * @return this Card object
         */
        Card& Card::operator=(const Card& rhs){
            if (this == &rhs){
                return *this; 
            }
            cardType_ = rhs.cardType_;
            instruction_ = rhs.instruction_;
            bitmap_ = rhs.bitmap_;
            drawn_ = rhs.drawn_;
        }

        /**
         * Move Constructor
         * @param: rvalue reference to a Card object 
        */
       Card::Card(Card&& rhs){
            cardType_ = std::move(rhs.cardType_);
            instruction_ = std::move(rhs.instruction_);
            bitmap_ = std::move(rhs.bitmap_);
            drawn_ = rhs.drawn_;
        }

        /**
         * Move assignment operator
         * @param: rvalue reference to a Card object
         * @return this card object
        */
        Card& Card::operator=(Card&& rhs){
            if (this == &rhs){
                return *this;
            }
            cardType_ = std::move(rhs.cardType_);
            instruction_ = std::move(rhs.instruction_);
            bitmap_ = std::move(rhs.bitmap_);
            drawn_ = rhs.drawn_;
        }

        /**
         * Default Constructor
         * @post: Construct a new Card object 
         */
        Card::Card(){
            bitmap_ = nullptr;
            instruction_ = "";
            drawn_ = false;
        }

        /**
         * @return the string representation of the card type
         */
        std::string Card::getType() const{
            if (cardType_ == POINT_CARD)      
             return "POINT CARD";
             
            else
                return "ACTION CARD";
            }
        /**
         * @post: set the card type
         * @param const reference to a CardType object
         */
        void Card::setType(const CardType& type){
            this->cardType_ = type;
        }

        /**
         * @return the string representation of the card instruction
        */
        const std::string& Card::getInstruction() const{ 
            return instruction_;
            }

        /**
         * @post: set the card instruction
         * @param: const reference to an instruction 
         */
        void Card::setInstruction(const std::string& instruction){
            this->instruction_ = instruction;
        }

        /**
         * @return the image data
         */
        const int* Card::getImageData() const{
            return bitmap_;
        }

        /**
         * @post: Set the image data
         * @param pointer to an array of integers
         */
        void Card::setImageData(int* data){
            this->bitmap_ = data;
        }

        /**
         * @return the drawn status of the card
        */
        bool Card::getDrawn() const{
            return drawn_;
        }

        /**
         * @post: set the drawn status of the card
         * 
         * @param: const reference to a boolean
         */
        void Card::setDrawn(const bool& drawn){
            this->drawn_ = drawn;
        }

        // Pure Virtual Functions
        void Card::Print() const {}
        bool Card::isPlayable() {}