#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long BASE = 31;
const long long MOD = 1e9 + 7;

// Compute hash of a string
long long computeHash(const string& s) {
    long long hash_value = 0;
    long long pow_base = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * pow_base) % MOD;
        pow_base = (pow_base * BASE) % MOD;
    }
    return hash_value;
}

int main() {
    string s;
    int n;
    cin >> s >> n;

    vector<string> tapes(n);
    for (int i = 0; i < n; i++) {
        cin >> tapes[i];
    }

    int len = s.length();

    // Store hashes of all small tapes with their lengths
    vector<pair<int, long long>> tape_hashes;
    for (const string& tape : tapes) {
        tape_hashes.push_back({tape.length(), computeHash(tape)});
    }

    // For each position, check if it can be covered by at least one tape
    vector<bool> canCover(len, false);

    // Check all possible tape placements
    for (int start = 0; start < len; start++) {
        for (auto [tape_len, tape_hash] : tape_hashes) {
            if (start + tape_len > len) continue;

            // Compute hash of s[start..start+tape_len-1]
            long long substr_hash = 0;
            long long pow = 1;
            for (int j = start; j < start + tape_len; j++) {
                substr_hash = (substr_hash + (s[j] - 'a' + 1) * pow) % MOD;
                pow = (pow * BASE) % MOD;
            }

            // If this tape matches, mark all positions it covers
            if (substr_hash == tape_hash) {
                for (int j = start; j < start + tape_len; j++) {
                    canCover[j] = true;
                }
            }
        }
    }

    // Check if all positions are covered
    bool allCovered = true;
    for (int i = 0; i < len; i++) {
        if (!canCover[i]) {
            allCovered = false;
            break;
        }
    }

    if (allCovered) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
