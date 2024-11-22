#ifndef MPAGSCIPHER_VIGENERECIPHER_CPP
#define MPAGSCIPHER_VIGENERECIPHER_CPP

#include <string>
#include <iostream>
#include <algorithm>

#include "CipherMode.hpp"
#include "VigenereCipher.hpp"
#include "Alphabet.hpp"

VigenereCipher::VigenereCipher(const std::string& key) {
    this->setKey(key);
}

void VigenereCipher::setKey(const std::string& key) {
    // Store the key
    key_ = key;

    // Check if the key is empty and replace with default if so
    if (key_.size() == 0) {
        key_ = "MPAGSCIPHER";
    }
    else {
        // Make sure the key is uppercase and remove non-alphabet characters
        auto formatKey = [&] (char c) {
            if (std::isalpha(c)){
                return std::toupper(c);
            }
            else {
                return 0;
            }
        };
        std::transform(key_.begin(), key_.end(), key_.begin(), formatKey);
        std::cout << key_ << std::endl;
    };

    // loop over the key
    for (char c: key_) {
        // Find the letter position in the alphabet
        for (std::size_t i{0}; i < Alphabet::size; ++i){
            if (c == Alphabet::alphabet[i]){
                // Create a CaesarCipher using this position as a key
                charLookup_.emplace(c, CaesarCipher{i});
                break;
            }
        }
    }
}

std::string VigenereCipher::applyCipher(const std::string& inputText, const CipherMode cipherMode) const {

    std::string outputText{""};
    std::size_t keyLength = key_.size(); 
    // For each letter in input:
    for (std::size_t i{0}; i < inputText.size(); ++i) {
        // Find the corresponding letter in the key,
        // repeating/truncating as required
        char keyLetter = key_[i % keyLength];

        // Find the Caesar cipher from the lookup
        CaesarCipher cipher = charLookup_.at(keyLetter);
        
        // Run the (de)encryption
        std::string inputLetter{inputText[i]};
        std::string encodedLetter = cipher.applyCipher(inputLetter, cipherMode);
        
        // Add the result to the output
        outputText += encodedLetter;
    }
    return outputText;
}

#endif