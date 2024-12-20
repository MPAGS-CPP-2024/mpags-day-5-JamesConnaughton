#ifndef MPAGSCIPHER_CIPHERTYPE_HPP
#define MPAGSCIPHER_CIPHERTYPE_HPP

/**
 * \file CipherType.hpp
 * \brief Contains the declaration of the CipherType enumeration
 */

/**
 * \enum CipherType
 * \brief Defines the ciphers that can be used
 */
enum class CipherType {
    Caesar,     ///< The Caesar cipher
    Playfair,    ///< The Playfair cipher
    Vigenere  ///< The Vigenere cipher
};

#endif    // MPAGSCIPHER_CIPHERTYPE_HPP