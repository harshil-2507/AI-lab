/* Local Beam Search for Word Formation */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> dictionary = {"art", "rat", "tar", "fit", "artificial", "tact", "fact"};
vector<string> candidates = {"art", "fit", "rat"};

void localBeamSearch(int K) {
    for (int iter = 0; iter < 10; iter++) {
        vector<string> newCandidates;
        for (auto &word : candidates) {
            for (char c : "artificial") {
                string newWord = word + c;
                if (dictionary.count(newWord)) newCandidates.push_back(newWord);
            }
        }
        sort(newCandidates.begin(), newCandidates.end(), [](string a, string b) { return a.size() > b.size(); });
        if (newCandidates.size() > K) newCandidates.resize(K);
        if (newCandidates.empty()) break;
        candidates = newCandidates;
    }
    cout << "Local Beam Search Best Word: " << candidates[0] << "\n";
}

int main() {
    localBeamSearch(3);
    return 0;
}