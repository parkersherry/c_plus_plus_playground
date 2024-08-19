#include <iostream>

// First make scoped enumeration
enum class suit_t : unsigned char
    {
        clubs,
        diamonds,
        hearts,
        spades,
        suit_last
    };

// Then convert suit value to suit name
auto to_string(suit_t s) -> std::string
    {
        switch (s)
        {
            case suit_t::clubs:
                return "clubs";
            case suit_t::diamonds:
                return "diamonds";
            case suit_t::hearts:
                return "hearts";
            case suit_t::spades:
                return "spades";
            case suit_t::suit_last:
                return "not a valid suit";
        } 
    }

int const number_of_suits = static_cast<int>(suit_t::suit_last);
// Make deck
suit_t Deck[number_of_suits];
// may need to move this to main

int main () {
    for (int i = 0; i < number_of_suits; i++) 
    {
        suit_t c = static_cast<suit_t>(i);
        Deck[i] = c;
        std::cout << to_string(Deck[i]) << "\n";
    }
}

// Conclusion: I can static_cast integer index values to their corresponding suit or rank value