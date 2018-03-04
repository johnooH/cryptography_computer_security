#include <iostream>
#include <map>
#include <string>

std::map<char, int> alph_map = {
   {'A', 0 },
{ 'B', 1 },
{ 'C', 2 },
{ 'D', 3 },
{ 'E', 4 },
{ 'F', 5 },
{ 'G', 6 },
{ 'H', 7 },
{ 'I', 8 },
{ 'J', 9 },
{ 'K', 10 },
{ 'L', 11 },
{ 'M', 12 },
{ 'N', 13 },
{ 'O', 14 },
{ 'P', 15 },
{ 'Q', 16 },
{ 'R', 17 },
{ 'S', 18 },
{ 'T', 19 },
{ 'U', 20 },
{ 'V', 21 },
{ 'W', 22 },
{ 'X', 23 },
{ 'Y', 24 },
{ 'Z', 25 } };

std::map < int, char> inv_alph_map = {
  { 0, 'A' },
{ 1, 'B' },
{ 2, 'C' },
{ 3, 'D' },
{ 4, 'E' },
{ 5, 'F' },
{ 6, 'G' },
{ 7, 'H' },
{ 8, 'I' },
{ 9, 'J' },
{ 10, 'K' },
{ 11, 'L' },
{ 12, 'M' },
{ 13, 'N' },
{ 14, 'O' },
{ 15, 'P' },
{ 16, 'Q' },
{ 17, 'R' },
{ 18, 'S' },
{ 19, 'T' },
{ 20, 'U' },
{ 21, 'V' },
{ 22, 'W' },
{ 23, 'X' },
{ 24, 'Y' },
{ 25, 'Z' }
};
  
  std::map<int, int> perm_map = {
    { 0, 23 },
  { 1, 13 },
  { 2, 24 },
  { 3, 0 },
  { 4, 7 },
  { 5, 15 },
  { 6, 14 },
  { 7, 6 },
  { 8, 25 },
  { 9, 16 },
  { 10, 22 },
  { 11, 1 },
  { 12, 19 },
  { 13, 18 },
  { 14, 5 },
  { 15, 11 },
  { 16, 17 },
  { 17, 2 },
  { 18, 21 },
  { 19, 12 },
  { 20, 20 },
  { 21, 4 },
  { 22, 10 },
  { 23, 9 },
  { 24, 3 },
  { 25, 8 }
  };
  
  std::map<int, int> inv_perm_map = {
    { 23, 0 },
  { 13, 1 },
  { 24, 2 },
  { 0, 3 },
  { 7, 4 },
  { 15, 5 },
  { 14, 6 },
  { 6, 7 },
  { 25, 8 },
  { 16, 9 },
  { 22, 10 },
  { 1, 11 },
  { 19, 12 },
  { 18, 13 },
  { 5, 14 },
  { 11, 15 },
  { 17, 16 },
  { 2, 17 },
  { 21, 18 },
  { 12, 19 },
  { 20, 20 },
  { 4, 21 },
  { 10, 22 },
  { 9, 23 },
  { 3, 24 },
  { 8, 25 }
  };
  
int handle_neg(int i, int lim) {
  if (i >= 0) 
    return i;
  return lim + i;
}

int get_z_i(int K, int i) {
  return handle_neg(K + i - 1, 26) % 26;
}

int decrypt_single(int y, int z) {
  return (inv_perm_map[handle_neg(y-z, 26)])% 26;
}

int encrypt_single(int x, int z) {
  return (perm_map[x] + z)  % 26;
}

std::string decrypt(std::string encrpyted_string) {
  int es_size = encrpyted_string.length();
  int K = 0;
  int j = 0;
  std::string flag;
  std::string answer = "";
  
  while (K < 26) {
    std::string temp_string = "";
    for (int i = 0; i < es_size; i++) {
      char en_ch = encrpyted_string[i];
      if (isspace(en_ch)) {
        temp_string += " ";
        continue;
      }
      int y = alph_map[en_ch];
      int z = get_z_i(K, j);

      int d_val = decrypt_single(y, z);
      temp_string += inv_alph_map[d_val];
      j += 1;
    }
    std::cout<< "Possible decrpyted string, try " << K << ": " << temp_string << std::endl;
    std::cout<< " Should I keep going? If you want me to stop type 'n'" << std::endl;
    std::cin >> flag;
    
    if (flag == "n") {
      answer = temp_string;
      break;
    }
    K += 1;
  }
  
  return answer;
}


int main() {
  decrypt("WRT CNRLD SAFARWK XFTXCZRNH NY PDT ZUUKMPLU SOX NEUDOKLX RMCBKG RC CURR");
  
}