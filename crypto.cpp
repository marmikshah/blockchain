#include "crypto.hpp"

std::string calculateSHA265(std::string data) {
  CryptoPP::SHA256 hash;
  CryptoPP::byte digest[CryptoPP::SHA256::DIGESTSIZE];
  hash.CalculateDigest(digest, (CryptoPP::byte*)data.c_str(), data.length());

  std::string output;
  CryptoPP::HexEncoder encoder;
  encoder.Attach(new CryptoPP::StringSink(output));
  encoder.Put(digest, sizeof(digest));
  encoder.MessageEnd();

  return output;
}