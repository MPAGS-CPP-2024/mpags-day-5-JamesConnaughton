//! Unit Tests for MPAGSCipher VigenereCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"

TEST_CASE("Vigenere Cipher encryption", "[vigenere]") {
  VigenereCipher cc{"hello"};
  REQUIRE( cc.applyCipher("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", CipherMode::Encrypt) == "ISMTGZSXPGVVEZTQYYTCYGZXDSIIISUSASCUIZYSGICZHOMYR");
}

TEST_CASE("Vigenere Cipher decryption", "[vigenere]") {
  VigenereCipher cc{"hello"};
  REQUIRE( cc.applyCipher("ISMTGZSXPGVVEZTQYYTCYGZXDSIIISUSASCUIZYSGICZHOMYR", CipherMode::Decrypt) == "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING");
}