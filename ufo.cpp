#include <iostream>
#include <vector>
#include "ufo_functions.hpp"
using namespace std;

int main(){
    greet();
    
    string codeword = "Technology";
    string answer = "__________";
    
    int misses = 0;
    vector <char> incorrect;
    bool guess = false;
    char letter;

    while(answer != codeword && misses < 7){
        displayMisses(misses);
        displayStatus(incorrect, answer);

        cout << "\nPlease enter your guess: ";
        cin >> letter;
        for(int i = 0; i < codeword.length(); i++){
            if(letter == codeword[i]){
                answer[i] = letter;
                guess = true;
            }
        }
        
        if(guess){
            cout << "Correct!";
        }else{
            cout << "Incorrect! The tractor beam pulls the person in further.";
            incorrect.push_back(letter);
            misses++;
        }

        guess = false;
    }

    endGame(answer, codeword);    
}
