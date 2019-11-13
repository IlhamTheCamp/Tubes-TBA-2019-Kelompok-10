#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string input;
    getline(cin, input);
    int b = input.length();
    int i = 0;
    int k = 0;
    stack <char> s;

    cout<<"Token = |";
    while(i<b) {
        //Cek Spasi
        if(input[i] == ' ') {
            i++;
        }

        //Cek Proposisi
        else if(input[i] == 'p' || input[i] == 'q' || input[i] == 'r' || input[i] == 's') {
            s.push(input[i]);
            i++;
            cout<<"|1|";
        }

        //Cek NOT
        else if(input[i] == 'n' && input[i+1] == 'o' && input[i+2] == 't'){
            s.push(input[i]);
            s.push(input[i+1]);
            s.push(input[i+2]);
            cout<<"|2|";
            i = i+3;
        }

        //Cek IF
        else if(input[i] == 'i' && input[i+1] == 'f' && (input[i+2] == ' ' || input[i+2] == 'p' || input[i+2] == 'q' || input[i+2] == 'r' || input[i+2] == 's' || input[i+2] == '(')){
            s.push(input[i]);
            s.push(input[i+1]);
            cout<<"|6|";
            i = i+2;
        }

        //Cek Kurung Buka
        else if(input[i] == '('){
            s.push(input[i]);
            i++;
            cout<<"|9|";
        }

        //Cek AND
        else if(input[i] == 'a' && input[i+1] == 'n' && input[i+2] == 'd' && !s.empty()){
            s.push(input[i]);
            s.push(input[i+1]);
            s.push(input[i+2]);
            cout<<"|3|";
            i = i+3;
        }

        //Cek OR
        else if(input[i] == 'o' && input[i+1] == 'r' && !s.empty()){
            s.push(input[i]);
            s.push(input[i+1]);
            cout<<"|4|";
            i = i+2;
        }

        //Cek XOR
        else if(input[i] == 'x' && input[i+1] == 'o' && input[i+2] == 'r' && !s.empty()){
            s.push(input[i]);
            s.push(input[i+1]);
            s.push(input[i+2]);
            cout<<"|5|";
            i = i+3;
        }

        //Cek THEN
        else if(input[i] == 't' && input[i+1] == 'h' && input[i+2] == 'e' && input[i+3] == 'n' && !s.empty()){
            s.push(input[i]);
            s.push(input[i+1]);
            s.push(input[i+2]);
            s.push(input[i+3]);
            cout<<"|7|";
            i = i+4;
        }

        //Cek IFF
        else if(input[i] == 'i' && input[i+1] == 'f' && input[i+2] == 'f' && !s.empty()){
            s.push(input[i]);
            s.push(input[i+1]);
            s.push(input[i+2]);
            cout<<"|8|";
            i = i+3;
        }

        //Cek Kurung Tutup
        else if(input[i] == ')'){
            int j = i-1;
            while(input[j] != '(') {
                s.pop();
                j--;
            }
            s.pop();
            s.pop();
            i++;
            cout<<"|10|";
        }

        //Cek Error
        else{
            cout<<"|Error|";
            i = b;
        }
        cout<<"|";

    }
    return 0;
}
