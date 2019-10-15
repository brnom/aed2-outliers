#include <iostream>
#include <string>

using namespace std;

int main(){
    long int i=0, N;
    int j=0, k, L;
    
    cin >> N;
    cin >> k;
    //cin >> L;
    
    while(i<=N){
        for(j=0; j<k; j++)
            cout<<i<<", "<<j<<endl;
        i++;
    }
    
    return 0;
}