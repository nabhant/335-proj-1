#include "PointCard.hpp"


/**
         * @post: Construct a new Point Card object
         */
        PointCard::PointCard(){
             setType(POINT_CARD);
        }
        
        /**
         * @return true if the card is playable, false otherwise
         * For a card to be playable, it has to be drawn and the instruction has to be a valid number
        */
        bool PointCard::isPlayable(){
            if(getInstruction().empty() || !getDrawn()){
                return false;
            }
            for(char i : getInstruction()){
                if (!isdigit(i)){
                    return false;
                }
            }
            return true;
        }

        /**
         * @post: Print the Point Card in the following format:
         * Type: [CardType]
         * Points: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
        void PointCard::Print() const{
            std::cout<<"Type: "<<getType()<<std::endl;
            std::cout<<"Points: "<<getInstruction()<<std::endl;
            std::cout<<"Card:"<<std::endl;
            const int* imgData = getImageData();
            if (imgData == nullptr)
                std::cout<<"No image data"<<std::endl;
            else{
                for (int i = 0; i<=79; i++){
                    std::cout<<imgData[i]<<" ";
                }
            }
        }