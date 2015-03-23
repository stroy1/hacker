#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    long long int numTestCases;
    cin >> numTestCases;
    
    for(long long int i = 0; i < numTestCases; i++){
        string w,s;
        long long int j;
        cin >> w;
        
        for(j = w.length()-1; j > 0; j--){
            if(w[j] > w[j-1]){
                s = w.substr(0, j-1);
                string sub = w.substr(j-1); // get from next to the end
                sort(sub.begin(), sub.end());
                int position, k = 1;
                while((position = (sub.find(w[j-1]))+k) == w[j-1]){
                    k++;
                }
                s += sub[position];
                sub.erase(position,1);
                s += sub;
                break;
            }
        }

        if(j == 0){
            cout << "no answer"<< endl;
        }else{
            cout << s << endl;
        }
    }
    
    return 0;
}