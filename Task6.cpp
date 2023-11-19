
//Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
//A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
//Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.


#include <iostream>
using namespace std;

string New(string x) {             //function change string 
    int i;
    int count = 0;
    int alpha[26];
    for (i = 0; i < 26; i++){
        alpha[i]=0;
    }  
    
    for (i = 0; i < x.length(); ++i){
        if(bool (x[i]-x[0])){
            if (alpha[x[i]-'a']==0){
                alpha[x[i]-'a'] = 1 + count;
                count++;
            }       
        } 
    }
 
    for (i = 0; i < x.length(); ++i) {    
        x[i] = 'a' + alpha[x[i]-'a'];
    }
    return x;
}

void matchpattern(string a[], string p, int n){     //function print match string
    int k = 0;
    for (int i = 0; i < n; i++){
        if (New(a[i]) == New(p)){
            cout << a[i] << "; ";
            k++;
        }
    }
    if (k==0) cout << "Cannot find";
}        

int main()
{
    int n, i;
    cout << "Input the number of strings words of the list: ";
    cin >> n;
    string a[n];
    for(i = 0;i < n; i++){      
        cout << "Input the " << i+1 << "th string word: ";
        cin >> a[i];
    }
    cout << "Input string pattern: ";
    string p;
    cin >> p;
    cout << "Strings match string pattern: ";
    matchpattern(a, p, n);
}
