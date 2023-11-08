#include "ActionCard.hpp"
#include <iostream>

/**
         * @post: Construct a new Action Card object
        */
        ActionCard::ActionCard(){
            setType(ACTION_CARD);
        };

        /**
         * @return true if the card is playable, false otherwise
         * For a card to be playable, it has to be drawn and the instruction has to be valid
         * Valid instructions:
         * DRAW x CARD(S) : assume x is a positive integer
         * PLAY x CARD(S) : assume x is a positive integer
         * REVERSE HAND : reverse the order of the cards in the hand
         * SWAP HAND WITH OPPONENT : swap the hand with the opponent
        */
        bool ActionCard::isPlayable(){
            if (!getDrawn()){
                return false;
            }
            
            // Defining regular expressions for the instructions
            std::regex validInstruction(R"(DRAW|PLAY) (\\d+) CARD\\(S\\)|REVERSE HAND|SWAP HAND WITH OPPONENT")");
            std::string instruction = getInstruction();

            // Verify if valid instruction
            if (std::regex_match(instruction, validInstruction)){
                return true;
            }
            else{
                return false;
            }
        }
        

        
        /**
         * @post: Print the ActionCard in the following format:
         * Type: [CardType]
         * Instruction: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
        void ActionCard::Print()const{
            std::cout<<"Type: "<<getType()<<std::endl;
            std::cout<<"Instruction: "<<getInstruction()<<std::endl;
            std::cout<<"Card: "<<std::endl;
            const int* imgData = getImageData();
            if (imgData != nullptr){
                for (int i = 0; i <= 80; i++){
                    std::cout<<imgData[i]<<" ";
                }
                std::cout << std::endl;
            }
            else{
                std::cout<<"No image data"<<std::endl;
            }
            
        }