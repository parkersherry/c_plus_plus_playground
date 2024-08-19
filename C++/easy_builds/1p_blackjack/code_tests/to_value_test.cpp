#include <iostream>
#include <string>


class card_t 
{
    public: 

   
    enum class suit_t : unsigned char
    {
        clubs,
        diamonds,
        hearts,
        spades,
        suit_last
    };

    
    enum class rank_t : unsigned char
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

int main () {
    std::cout << to_value(card_t::rank_t::king);
    return 0;
}