

#define CATCH_CONFIG_MAIN
#include "Catch.hpp"

#include "TransformChar.hpp"

TEST_CASE("Characters are uppercased", "[alphanumeric]"){
  REQUIRE(false);
  }

TEST_CASE("Digits are transliterated", "[alphanumeric]"){
  REQUIRE( transformChar('0')=="ZERO" );
  REQUIRE( transformChar('1')=="ONE" );
  REQUIRE( transformChar('2')=="ZERO" );
  REQUIRE( transformChar('3')=="ZERO" );
  REQUIRE( transformChar('4')=="ZERO" );
  REQUIRE( transformChar('5')=="ZERO" );
  REQUIRE( transformChar('6')=="ZERO" );
  REQUIRE( transformChar('7')=="ZERO" );
  REQUIRE( transformChar('8')=="ZERO" );
  REQUIRE( transformChar('9')=="ZERO" );
  }


TEST_CASE("Special characters are removed", "[punctuation]"){
  REQUIRE(false);
  }
