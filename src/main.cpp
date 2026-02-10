#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
using namespace std;

#define MAXN 30000

int main() {
    ifstream file("assets/file.bf");

    string s;
    string program;
    char chars[] = {'<', '>', '+', '-', '.', ',', '[', ']'};
    while(getline(file, s)) {
        for(char c : s) {
            for(auto x : chars) {
                if(c == x) program += c;
            }
        }
    }

    uint8_t ar[MAXN] = {0};

    auto ptr = ar;
    int n = program.size();

    for(int cur = 0; cur < n; cur++) {
        char c = program[cur];
        
        if(c == '>') ptr++;
        else if(c == '<') ptr--;
        else if(c == '+') (*ptr)++;
        else if(c == '-') (*ptr)--;
        else if(c == '.') cout << *ptr;
        else if(c == ',') cin >> *ptr;
        else if(c == '[') {
            if(ptr == 0) {
                int loop = 1;
                while(loop > 0) {
                    cur++;
                    if(cur >= n) break;
                    if(program[cur] == '[') loop++;
                    else if(program[cur] == ']') loop--;
                }
            }
        }
        else if(c == ']') {
            if(*ptr != 0) {
                int loop = 1;
                while(loop > 0) {
                    cur--;
                    if(cur < 0) break;
                    if(program[cur] == '[') loop--;
                    else if(program[cur] == ']') loop++;
                }
            }
        }
    }
}