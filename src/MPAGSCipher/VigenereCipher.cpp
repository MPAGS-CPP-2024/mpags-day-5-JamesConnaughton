#ifndef MPAGSCIPHER_VIGENERECIPHER_CPP
#define MPAGSCIPHER_VIGENERECIPHER_CPP

#include <string>
#include <iostream>

#include "CipherMode.hpp"
#include "VigenereCipher.hpp"

VigenereCipher::VigenereCipher(const std::string& key) {
    this->setKey(key);
}

void VigenereCipher::setKey(const std::string& key) {
    key_ = key;
}

std::string VigenereCipher::applyCipher(const std::string& inputText, const CipherMode cipherMode) const {
    std::cout << "We're running the vigenere cipher!!" << std::endl; 
    if (cipherMode == CipherMode::Encrypt) {
        return inputText;
    }
    else {
        return inputText;
    }
}

#endif