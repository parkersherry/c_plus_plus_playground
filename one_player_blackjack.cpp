#include <iostream> // duh
#include <string> // included when strings are stored as variables 

// make card object
class card_t 
{
    public: 

    // make suits
    enum class suit_t : unsigned char // identifies suits numerically and reduces the memory required to store them
    {
        clubs,
        diamonds,
        hearts,
        spades,
        suit_last
    };

    // make ranks
    enum class rank_t : unsigned char // ranks cards by in-game value
    {
        ace,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        jack,
        queen,
        king,
        rank_last
    };

    rank_t rank;
    suit_t suit;
};

// functions for deck initialization
auto to_suit (int i) 
{
    return static_cast<card_t::suit_t>(i);
}
auto to_rank (int i) 
{
    return static_cast<card_t::rank_t>(i);
}

// card values in-game

constexpr auto to_value(card_t::rank_t r) noexcept -> int
{
    switch (r)
    {
        case card_t::rank_t::jack:
            return 10;
        case card_t::rank_t::queen:
            return 10;
        case card_t::rank_t::king:
            return 10;
        default:
            return static_cast<int>(r) + 1;
    }
}

// reading out card suits and ranks
auto to_string_s(card_t::suit_t s) -> std::string // converts suit value to suit name 
{
    switch (s)
    {
        case card_t::suit_t::clubs:
            return "clubs";
        case card_t::suit_t::diamonds:
            return "diamonds";
        case card_t::suit_t::hearts:
            return "hearts";
        case card_t::suit_t::spades:
            return "spades";
        case card_t::suit_t::suit_last:
            return "not a valid suit";
    } 
}

auto to_string_r(card_t::rank_t r) -> std::string // converts rank value to rank name 
{
    switch (r)
    {
        case card_t::rank_t::ace:
            return "ace of ";
        case card_t::rank_t::two:
            return "two of ";
        case card_t::rank_t::three:
            return "three of ";
        case card_t::rank_t::four:
            return "four of ";
        case card_t::rank_t::five:
            return "five of ";
        case card_t::rank_t::six:
            return "six of ";
        case card_t::rank_t::seven:
            return "seven of ";
        case card_t::rank_t::eight:
            return "eight of ";
        case card_t::rank_t::nine:
            return "nine of ";
        case card_t::rank_t::ten:
            return "ten of ";
        case card_t::rank_t::jack:
            return "jack of ";
        case card_t::rank_t::queen:
            return "queen of ";
        case card_t::rank_t::king:
            return "king of ";
        case card_t::rank_t::rank_last:
            return "not a valid rank";
    }
} 

// Make empty deck
int const number_of_suits = static_cast<int>(card_t::suit_t::suit_last);
int const number_of_ranks = static_cast<int>(card_t::rank_t::rank_last);
int const number_of_cards = number_of_suits*number_of_ranks;

card_t Deck[number_of_cards];

// Make shuffle function
void shuffle (card_t Deck[], int length) 
{
    srand ( time(NULL) );
    for (int i = 0; i < length; i++)
    {
        int swap_index = rand() % length;
        card_t temp = Deck[i];
        Deck[i]=Deck[swap_index];
        Deck[swap_index] = temp;
    }
};

// Initialize control variables

int play = 1;                                           // restart game
int is_split, hand_sum, hand_sum_1, dealer_sum = 0;     // flow control
int iter = 4;                                           // index for newly dealt cards
int break_var = 0;                                      // if break_var = 1, terminates the main while loop
int dummy_var = 0;                                      // allows error message to be looped in branches while user input is neither "yes" nor "no"

//int main allows me to return zero, whereas void main does not

int main () 
{
    while (play == 1 && break_var != 1){
        play = 0;
        hand_sum = 0;
        hand_sum_1 = 0;
        dealer_sum = 0;
        iter = 4;
       
        // create deck
       
        for (int i = 0; i < number_of_suits; i++)
        {
            for (int j = 0; j < number_of_ranks; j++) 
            {
                Deck[i*13+j].rank = to_rank(j);
                Deck[i*13+j].suit = to_suit(i);
            }
        }
        
        // shuffle deck
       
        shuffle (Deck, number_of_cards);

        // welcome message
       
        std::string input;
        std::cout << "Welcome to One-Player Blackjack! Would you like to play? (Enter Yes or No)\n";
        
        // player can opt out of playing

        std::cin >> input;
        if (input == "Yes" || input == "yes") 
        {
            // deal cards

            hand_sum = to_value(Deck[0].rank) +  to_value(Deck[1].rank);    // keeps track of whether the players hand is under 21
            dealer_sum = to_value(Deck[2].rank) +  to_value(Deck[3].rank) ; // ditto but for dealer
            
            std::cout << "The Dealer has... a " << to_string_r(Deck[2].rank) << to_string_s(Deck[2].suit) << ".\n";
            std::cout << "You have a " << to_string_r(Deck[0].rank) << to_string_s(Deck[0].suit) << " and a " << to_string_r(Deck[1].rank) << to_string_s(Deck[1].suit) << ".\n";

            // check if dealer and/or player received a natural
            
            if (dealer_sum == 21 && hand_sum != 21) 
            {
                input = "null";
                while (input != "Yes" && input != "yes" && input != "No" && input != "no"){
                    if (dummy_var == 1) {
                        std::cout << "I'm sorry, that wasn't a valid response. Please enter Yes or No.\n";
                    }
                    if (dummy_var == 0) {
                        std::cout << "Oof, it seems that the Dealer has a blackjack! Bad Luck; want to try again? (Enter Yes or No)\n";
                        dummy_var = 1;
                    }
                    std::cin >> input;
                    if (input == "Yes" || input == "yes") {
                        play = 1;
                        dummy_var = 0; 
                    }
                    else if (input == "No" || input == "no") {
                        std::cout << "Ok, thanks for stopping by!\n"; 
                        break_var = 1;
                        dummy_var = 0;
                    }
                }
            }
            else if (dealer_sum == 21 && hand_sum == 21)  
            {
                input = "null";
                while (input != "Yes" && input != "yes" && input != "No" && input != "no") {
                    if (dummy_var == 1) {
                        std::cout << "I'm sorry, that wasn't a valid response. Please enter Yes or No.\n";
                    }
                    if (dummy_var == 0) {
                        std::cout << "You and the Dealer both have a blackjack! This one's a tie. Want to try again? (Enter Yes or No)\n";
                        dummy_var = 1;
                    }
                    std::cin >> input;
                    if (input == "Yes" || input == "yes") {
                        play = 1;
                        dummy_var = 0;
                    }
                    else if (input == "No" || input == "no") {
                        std::cout << "Ok, thanks for stopping by!\n"; 
                        break_var = 1;
                        dummy_var = 0;
                    }
                }
            }
            else if (dealer_sum != 21 && hand_sum == 21) 
            {
                input = "null";
                while (input != "Yes" && input != "yes" && input != "No" && input != "no") {
                    if (dummy_var == 1) {
                        std::cout << "I'm sorry, that wasn't a valid response. Please enter Yes or No.\n";
                    }
                    if (dummy_var == 0) {
                        std::cout << "You've got a blackjack! You win this round. Want to try again? (Enter Yes or No)\n";
                        dummy_var = 1;
                    }
                    std::cin >> input;
                    if (input == "Yes" || input == "yes") {
                        play = 1;
                        dummy_var = 0;
                    }
                    else if (input == "No" || input == "no") {
                        std::cout << "Ok, thanks for stopping by!\n"; 
                        break_var = 1;
                        dummy_var = 0;
                    }
                } 
            }

            // restart game based on previous input
            
            if (play == 1 || break_var == 1) {
                continue;
            }

            // check if Player was dealt a pair + ask to split
            
            if (Deck[0].rank == Deck[1].rank)
            {
                input = "null";
                while (input != "Yes" && input != "yes" && input != "No" && input != "no") {
                    if (dummy_var == 1) {
                        std::cout << "I'm sorry, that wasn't a valid response. Please enter Yes or No.\n";
                    } 
                    if (dummy_var == 0) {
                        std::cout << "Oh! Your cards are a pair? Would you like to Split? (Enter Yes or No)\n";
                        dummy_var = 1;
                    }
                    std::cin >> input;
                    if (input == "Yes" || input == "yes") 
                    { 
                        dummy_var = 0;
                        is_split = 1;
                        std::cout << "There, your starting hand has been split. You'll start the game with the " << to_string_r(Deck[0].rank) << to_string_s(Deck[0].suit)<< ". \n";
                        hand_sum = to_value(Deck[0].rank);
                    }
                    else if (input == "No" || input == "no") 
                    {
                        dummy_var = 0;
                        std::cout << "Okay, we'll keep your starting hand as is.\n";
                    }
                } 
            }
            
            // gameplay
           
            input = "null";
            while (input != "Stand" && input != "stand" && break_var != 1) {
                if (dummy_var == 1) {
                    std::cout << "I'm sorry, that wasn't a valid response. Please enter Hit or Stand.\n";
                }
                if (dummy_var == 0) {
                    std::cout << "Would you like to Hit or Stand?\n";
                    dummy_var = 1;
                }
                std::cin >> input;
                if (input == "Hit" || input == "hit") {
                    dummy_var = 0;
                    hand_sum += to_value(Deck[iter].rank);
                    std::cout << "You've received the " << to_string_r(Deck[iter].rank) << to_string_s(Deck[iter].suit) << ".\n";
                    iter ++;
                    if (hand_sum > 21) {
                        input = "null";
                        while (input != "Yes" && input != "yes" && input != "No" && input != "no") {
                            if (dummy_var == 1) {
                                std::cout << "I'm sorry, that wasn't a valid response. Please enter Yes or No.\n";
                            }
                            if (dummy_var == 0) {
                                std::cout << "Oh no, you've gone bust! I'm afraid you lose this round. Want to try again? (Enter Yes or No)\n";
                                dummy_var = 1;
                            }
                            std::cin >> input;
                            if (input == "Yes" || input == "yes") {
                                play = 1;
                                dummy_var = 0;
                            }
                            else if (input == "No" || input == "no") {
                                std::cout << "Ok, thanks for stopping by!\n"; 
                                break_var = 1;
                                dummy_var = 0;
                            }
                        }
                    }
                    else if (hand_sum == 21) {
                        input = "null";
                        while (input != "Yes" && input != "yes" && input != "No" && input != "no") {
                            if (dummy_var == 1) {
                                std::cout << "I'm sorry, that wasn't a valid response. Please enter Yes or No.\n";
                            }
                            if (dummy_var == 0) {
                                std::cout << "You got a blackjack! You win this round. Want to try again?\n";
                                dummy_var = 1;
                            }
                            std::cin >> input;
                            if (input == "Yes" || input == "yes") {
                                play = 1;
                                dummy_var = 0;
                            }
                            else if (input == "No" || input == "no") {
                                std::cout << "Ok, thanks for stopping by!\n"; 
                                break_var = 1;
                                dummy_var = 0;
                            }
                        }
                    }
                }
                else if (input == "Stand" || input == "stand") {
                    dummy_var = 0;
                    if (is_split == 1) {
                        hand_sum_1 = hand_sum;
                        hand_sum = to_value(Deck[1].rank);
                        is_split = 0;
                        input = "null";
                        std::cout << "Now, we'll play with your second hand.\n";
                    }
                }
            }

            if (play == 1 || break_var == 1) {
                continue;
            }

            std::cout << "Ok, let's see what the Dealer has...\n";
            if (dealer_sum < hand_sum || dealer_sum < hand_sum_1) {
                input = "null";
                while (input != "Yes" || input != "No" || input != "yes" || input != "no") {
                    if (dummy_var == 1) {
                        std::cout << "I'm sorry, that wasn't a valid response. Please enter Yes or No.\n";
                    }
                    if (dummy_var == 0) {
                       std::cout << "Congratulations, you beat the Dealer! You win! Want to play again?\n";
                       dummy_var = 1; 
                    }
                    std::cin >> input;
                    if (input == "Yes" || input == "yes") {
                        play = 1;
                        dummy_var = 0;
                        break;
                    }
                    else if (input == "No" || input == "no") {
                        std::cout << "Ok, thanks for stopping by!\n"; 
                        break_var = 1;
                        dummy_var = 0;
                        break;
                    }
                }
            }
            else { 
                input = "null";
                while (input != "Yes" || input != "No" || input != "yes" || input != "no") {
                    if (dummy_var == 1) {
                        std::cout << "I'm sorry, that wasn't a valid response. Please enter Yes or No.\n";
                    }
                    if (dummy_var == 0) {
                       std::cout << "Unfortunately, it looks like the Dealer has beaten you with a " << to_string_r(Deck[3].rank) << to_string_s(Deck[3].suit) << ". Better luck next time! Want to play again? (Enter Yes or No)\n"; 
                       dummy_var = 1; 
                    }
                    std::cin >> input;
                if (input == "Yes" || input == "yes") {
                        play = 1;
                        dummy_var = 0;
                        break;
                    }
                    else if (input == "No" || input == "no") {
                        std::cout << "Ok, thanks for stopping by!\n"; 
                        break_var = 1;
                        dummy_var = 0;
                        break;
                    }
                }
            }
            if (play == 1 || break_var == 1) {
                continue;
            }
        }
        else if (input == "No" || input == "no") 
        {
            std::cout << "Ok, thanks for stopping by!\n";
            break_var = 1;
        }
        else {std::cout << "I'm sorry, that wasn't a valid response. Please restart the program and enter Yes or No.\n";}
    }
    return 0;
}