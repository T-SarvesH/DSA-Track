#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

bool valid(int frequency[256]){

    for(int i=0; i<256; i++){

        if(frequency[i]>1)
        return false;
    }
    return true;
}

int longestSubstring(string s){

    int frequency[256] = {0};
    int index = 0;
    int maxLen = 0;
    int window = 0;
    frequency[s[index]-'\0']++;
    
    while(window < s.size()){

            //Expand the window
            if(valid(frequency)){

                maxLen++;
                window++;
            }
            

            else{
                //Move the window forward
                frequency[s[index]-'\0']--;
                index++;
                window++;
                
            }

            frequency[s[window]-'\0']++;
    }
    return maxLen;

}
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << endl;

    int ans = longestSubstring(s);

    cout << ans << endl;
    return 0;
}
