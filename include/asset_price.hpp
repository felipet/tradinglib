#if !defined(TRADINGLIB_ASSET_PRICE_HPP)
#define TRADINGLIB_ASSET_PRICE_HPP

#include <string>
#include <vector>
#include "trading.hpp"

namespace trading {

/**
 * Asset_price class.
 * 
 * This class represents an asset's price entry for a given day.
 * 
 * An asset price for a given period of time includes the following:
 * - A close price. This is the last negotiated price for the given period of time.
 * - An open price. The starting price for the given period of time.
 * - A highimum price. The highimum negotiated price reached during the given period of time.
 * - A lowimum price. The lowimum negotiated price reached during the given period of time.
 * - A date, with the format "YYYYMMDD".
 * 
*/
    class Asset_price 
    {
        private:
            float close, open, high, low;
            std::string date;
        public:
            /**
             * Class' constructor.
             * 
             * Receives as arguments the prices for the close, open, high, low prices of the
             * day.
            */
            Asset_price(float close, float open, float high, float low, const std::string &date) noexcept
                :close{close}, open{open}, high{high}, low{low}, date{date} {}

            /**
             * Inline member to retrieve the close price.
            */
            float get_close() const { return close; }

            /**
             * Inline member to retrieve the open price.
            */
            float get_open() const { return open; }
            
            /**
             * Inline member to retrieve the high price.
            */
            float get_high() const { return high; }

            /**
             * Inline member to retrieve the low price.
            */
            float get_low() const { return low; }

            /**
             * Inline member to retrieve the date.
            */
            std::string get_date() const { return date; }
            
            /**
             * Member that allows a selection of the price based on an argument.
             * 
             * \param price_mark indicates what price is aimed to be retrieved. See \ref Price_mark.
            */
            float get_price(Price_mark price_mark) const noexcept; 

            /**
             * Inline member that returns the price range of the period of time.
            */
            float get_price_range() const { return high-low; };
            
    };
};

#endif //#if !defined(TRADINGLIB_ASSET_PRICE_HPP)