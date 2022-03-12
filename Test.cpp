#include "doctest.h"
#include "mat.hpp"
#include <stdexcept>

using namespace ariel;

std::string nospaces(std::string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("valid rows and cols"){
    CHECK_THROWS(nospaces(mat(2,5,'@','$')));
    CHECK_THROWS(nospaces(mat(5,2,'@','$')));
    CHECK_THROWS(nospaces(mat(2,2,'@','$')));
    CHECK_THROWS(nospaces(mat(-1,5,'@','$')));
    CHECK_THROWS(nospaces(mat(5,-1,'@','$')));
    CHECK_THROWS(nospaces(mat(-3,-5,'@','$')));
    CHECK_THROWS(nospaces(mat(0,5,'@','$')));
    CHECK_THROWS(nospaces(mat(3,0,'@','$')));
}

TEST_CASE("Not valid symbol"){
    CHECK_THROWS(nospaces(mat(5,9,'\n','@')));
    CHECK_THROWS(nospaces(mat(5,9,'1','\n')));
    CHECK_THROWS(nospaces(mat(5,9,'\t','-')));
    CHECK_THROWS(nospaces(mat(5,9,'@','\t')));
    CHECK_THROWS(nospaces(mat(5,9,'@','\v')));
    CHECK_THROWS(nospaces(mat(5,9,'\v','@')));
    CHECK_THROWS(nospaces(mat(5,9,'@','\0')));
    CHECK_THROWS(nospaces(mat(5,9,'\0','@')));
}


TEST_CASE("mat on samll dimenstions"){
    CHECK(nospaces(mat(1,1,'@','~')) == nospaces("@"));
    CHECK(nospaces(mat(3,1,'@','~')) == nospaces("@@@"));
    CHECK(nospaces(mat(1,3,'@','~')) == nospaces("@\n@\n@"));
    CHECK(nospaces(mat(3,1,'~','@')) == nospaces("~~~"));
    CHECK(nospaces(mat(1,3,'~','@')) == nospaces("~\n~\n~"));
    CHECK(nospaces(mat(5,1,'@','~')) == nospaces("@@@@@"));
    CHECK(nospaces(mat(1,5,'@','~')) == nospaces("@\n@\n@\n@\n@"));
    CHECK(nospaces(mat(5,1,'~','@')) == nospaces("~~~~~"));
    CHECK(nospaces(mat(1,5,'~','@')) == nospaces("~\n~\n~\n~\n~"));
}

TEST_CASE("mat on big dimenstions"){
    CHECK(nospaces(mat(9,7,'@','-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
    CHECK(nospaces(mat(13,5,'@','-')) == nospaces("@@@@@@@@@@@@@\n@-----------@\n@-@@@@@@@@@-@\n@-----------@\n@@@@@@@@@@@@@"));
}

