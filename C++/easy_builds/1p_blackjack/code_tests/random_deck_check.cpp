#include <iostream> // duh
#include <string> // included when strings are stored as variables 
#include <stdlib.h>
#include <time.h>

// make card object
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

    constexpr auto to_value(rank_t r) noexcept -> int
    {
        switch (r)
        {
            case rank_t::jack:
                [[fallthrough]];
            case rank_t::queen:
                [[fallthrough]];
            case rank_t::king:
                return 10;
            default:
                return static_cast<int>(r);
        }
    }
    
    auto to_string(suit_t s) -> std::string // converts suit value to suit name 
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
};

auto to_suit (int i) 
{
    return static_cast<card_t::suit_t>(i);
}
auto to_rank (int i) 
{
    return static_cast<card_t::rank_t>(i);
}

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

// Make shuffle function v1
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

int main () 
{   
    // initialize Deck
    for (int i = 0; i < number_of_suits; i++)
    {
        for (int j = 0; j < number_of_ranks; j++) 
        {
            Deck[i*13+j].rank = to_rank(j);
            Deck[i*13+j].suit = to_suit(i);
        }
    }
    shuffle (Deck, number_of_cards);
    for (int i = 0; i < number_of_cards; i++)
    {
        std::cout << to_string_r(Deck[i].rank) << to_string_s(Deck[i].suit) << "\n";
    }
    return 0;
}

