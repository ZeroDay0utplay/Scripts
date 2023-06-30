#include <bits/stdc++.h>
using namespace std;




string portion(string s, int start, int end); // Used for slicing


int main(int argc, char *argv[]) 
{
    cout << "\n";
    if (argc > 2 || argc == 1)
    {
        cout << "[!] Please Enter one command line argument.\n";
        return 1;
    }
    
    string s="", arg=argv[1];
    int l = arg.length();


    if (portion(arg, l-4, l) != ".cpp")
    {
        cout << "[!] Please enter the filename extension (.cpp)\n";
        return 1;
    }

    system("type nul > input.txt");

    for (int i=0; i<l-3; i++)
    {
        int car = arg[i];
        if ((car > 64 && car < 123) || (car > 47 && car < 58))
        {
            s+=arg[i];
        }
    }
    s+=".cpp";
    string cmd = "copy \%userprofile\%/\\Documents\\projects\\Scripts\\VSCPP\\cpp.cpp ./" + s;
    const char *command = cmd.c_str();
    
    system(command);
    string vs = "code ./" + s;
    const char *runVS = vs.c_str();
    system("code input.txt");
    system(runVS);
    cout << "\n[+] Done.\n";
}




string portion(string s, int start, int end)
{
    string st="";
    for (int i=start; i<end; i++)
    {
        st+=s[i];
    }
    return st;
}