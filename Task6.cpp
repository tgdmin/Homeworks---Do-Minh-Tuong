
//Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
//A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
//Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.


#include <iostream>
using namespace std;

string New(string z) {             // This function is to make a new character based on its input
    int p = 0;
    int alpha[26];          // alpha is to keep track of the characters
    for (int i = 0; i < 26; i++){
        alpha[i]=0;
    }  
    
    for (int i = 0; i < z.length(); ++i){       // Make unique identifier to each distinct character
        if(bool (z[i]-z[0])){
            if (alpha[z[i]-'a']==0){
                alpha[z[i]-'a'] = 1 + p;
                p++;
            }       
        } 
    }
 
    for (int i = 0; i < z.length(); ++i) {    
        z[i] = 'a' + alpha[z[i]-'a'];
    }
    return z;
}

void match_the_pattern(string a[], string l, int n){        // Condition for the input to match the pattern
    int k = 0;
    for (int i = 0; i < n; i++){
        if (New(a[i]) == New(l)){
            cout << a[i] << "; ";
            k++;
        }
    }
    if (k==0) cout << "Cannot find";
}        

int main()
{
    int n;
    cout << "Enter the number of strings words of the list: ";
    cin >> n;
    string a[n];
    for(int i = 0;i < n; i++){      
        cout << "Enter the " << i+1 << "th string word: ";
        cin >> a[i];
    }
    cout << "Enter string pattern: ";
    string p;
    cin >> p;
    cout << "Strings match string pattern: ";
    match_the_pattern(a, p, n);
}
