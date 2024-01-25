#include <iostream>
#include <vector>
using namespace std;

vector<int> arrangeDeck(int N) {
    vector<int> deck;
    int counter = 1;

    for(int i = 1; i <= N; i++) {
        if(counter == i) {
            deck.push_back(i);
            counter++;
        } else {
            deck.push_back(i);
            swap(deck[0], deck.back());
        }
    }
    
    if(counter != N+1) {
        // If the counter is not equal to N+1, it means it was not possible to arrange the deck
        deck.clear();
        deck.push_back(-1);
    }

    return deck;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        vector<int> deck = arrangeDeck(N);

        for(int i = 0; i < deck.size(); i++) {
            cout << deck[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
 
