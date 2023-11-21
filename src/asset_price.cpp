#include "asset_price.hpp"
#include "trading.hpp"

using namespace trading;

float Asset_price::get_price(Price_mark price_mark) const noexcept
{
    float price = 0.0;

    switch (price_mark)
    {
        case Price_mark::close:
            price = close;
            break;
        
        case Price_mark::open:
            price = open;
            break;

        case Price_mark::high:
            price = high;
            break;

        case Price_mark::low:
            price = low;
            break;

        default:
            break;
    }

    return price;
}
    



