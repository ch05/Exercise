#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isInteger(string& str){
    size_t len = str.length();
    return ( (str[0] > 47) && (str[0] < 58));
}

unsigned long strToInt(string& str){
    unsigned long res = 0;
    for(size_t i = 0; i < str.length(); i++){
        res = res*10 + (str[i]-48);
    }
    return res;
}

unsigned long intStrLength(string& str){
    size_t len = str.length();
    unsigned long intLen = 0;
    for(size_t i = 0; i < len; i++){
        if( (str[i] > 47) && (str[i] < 58)){
            intLen++;
        }
    }
    return intLen;
}

void operate(unsigned short op, string& instr, string& editor, vector<string>& history){
    unsigned long k;
    unsigned long pos;  
    size_t len = editor.length();
    size_t subStrLen, intLen;
    size_t historyLen = history.size();
    string subStr;
    string lastInstr;
    switch(op){
        case 1:
            editor += instr;
            history.push_back(instr);
            break;
        case 2:
            k = strToInt(instr);
            subStr = editor.substr(len-k, k);
            editor = editor.substr(0, len-k);
            history.push_back((instr+subStr));
            break;
        case 3:        
            pos = strToInt(instr) - 1;  //Index in instruction starts at 1
            if(pos < len)
                cout << editor[pos] << endl;            
            break;
        case 4:
            if(history.size() > 0){
                lastInstr = history[historyLen-1];
                history.pop_back();
                if(isInteger(lastInstr)){   //type 2 instruction, undo erase = append
                    intLen = intStrLength(lastInstr);
                    editor += lastInstr.substr(intLen);
                }
                else{   //type 1 instruction, undo append = erase
                    subStrLen = lastInstr.length();
                    editor = editor.substr(0, len-subStrLen);
                }
            }
            break;
        default:
            break;
    }
}

int main() {
    unsigned long n;
    unsigned short op;
    string instr;
    string editor;
    vector<string> history;
    cin >> n;
    for(unsigned long i = 0; i < n; i++){
        cin >> op;
        if(op < 4){
            cin >> instr;
        }
        operate(op, instr, editor, history);
    }
    return 0;
}
