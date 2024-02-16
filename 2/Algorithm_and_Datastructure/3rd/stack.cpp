#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    stack<int> myStack;
        string s;
        getline(cin, s);
        int i =0;
        while(i < s.size()){
        if(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != ' '){
            int b = i;
            while(1){
                
                if(s[i] == ' '){
                    string STR = s.substr(b,i-b);
                    myStack.push(stoi(STR));
                    break;
                }
                i++;
            }
        }
        if(s[i] = ' '){
            i++;
        }
        if(s[i] == '+'){
            int x = myStack.top();
            myStack.pop();
            int y = myStack.top();
            myStack.pop();
            myStack.push(x+y);
            i++;
            continue;
        }
        if(s[i] == '-'){
            int x = myStack.top();
            myStack.pop();
            int y = myStack.top();
            myStack.pop();
            myStack.push(y - x);
            i++;
            continue;
        }
        if(s[i] == '*'){
            int x = myStack.top();
            myStack.pop();
            int y = myStack.top();
            myStack.pop();
            myStack.push(x*y);
            i++;
            continue;
        }

} 
cout << myStack.top() << endl;
   return 0;
}

