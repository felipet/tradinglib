#include <boost/test/unit_test.hpp>
#include "asset_price.hpp"
#include <string>

struct asset_fixture
{
    const std::string date = "19910123";
    const float close = 5.0;
    const float open = 3.0;
    const float high = 10;
    const float low = 2;
    trading::Asset_price price;
    
    asset_fixture() :price(close, open, high, low, date){
        BOOST_TEST_MESSAGE("Setup fixture: asset_fixture");
    }

    ~asset_fixture() {
        BOOST_TEST_MESSAGE("teardown fixture: asset_fixture");
    }

};

BOOST_FIXTURE_TEST_SUITE ( asset_price, asset_fixture )

BOOST_AUTO_TEST_CASE( constructor )
{
    BOOST_REQUIRE_EQUAL(price.get_close(), close);
    BOOST_REQUIRE_EQUAL(price.get_open(), open);
    BOOST_REQUIRE_EQUAL(price.get_high(), high);
    BOOST_REQUIRE_EQUAL(price.get_low(), low);
    BOOST_REQUIRE_EQUAL(price.get_date(), date);

    trading::Price_mark price_mark = trading::Price_mark::close;
    BOOST_REQUIRE_EQUAL(price.get_price(price_mark), close);
    price_mark = trading::Price_mark::open;
    BOOST_REQUIRE_EQUAL(price.get_price(price_mark), open);
    price_mark = trading::Price_mark::high;
    BOOST_REQUIRE_EQUAL(price.get_price(price_mark), high);
    price_mark = trading::Price_mark::low;
    BOOST_REQUIRE_EQUAL(price.get_price(price_mark), low);
}

BOOST_AUTO_TEST_CASE( price_range )
{
    BOOST_REQUIRE_EQUAL(price.get_price_range(), high-low);
}

BOOST_AUTO_TEST_SUITE_END()