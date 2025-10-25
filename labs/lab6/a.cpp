

// Albert does not agree with the basic English alphabet. He thinks, that in the alphabet, 
// first, we need to print vowel letters first and then consonants, 
// and both vowels and consonants are ordered alphabetically. So he asks us to sort string according to his own alphabet.
//
// Examples
// Input
// 5
// abcde
// Output
// aebcd
// Input
// 5
// wlree
// Output
// eelrw

#include <iostream>
using namespace std;



int main() {
  int n;
  string s;
  cin >> n >> s;


  int freq[26] = {0};

  for (int i = 0; i < n; i++) {
    freq[s[i] - 'a']++;
  }

  bool isVowel[26] = {false};
  isVowel[0] = true;
  isVowel[4] = true;
  isVowel[8] = true;
  isVowel[14] = true;
  isVowel[20] = true;

  for (int i = 0; i < 26; i++) {
    if (isVowel[i]) {
      for (int j = 0; j < freq[i]; j++) {
        cout << (char) ('a' + i);
      }
    }

  }


  for (int i = 0; i < 26; i++) {
    if (!isVowel[i]) {
      for (int j = 0; j < freq[i]; j++) {
        cout << (char) ('a' + i);
      }
    }
  }

  return 0;
}
