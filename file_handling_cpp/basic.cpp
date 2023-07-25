#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    string s;
    cout << "Enter your name and age:" << '\n';
    getline(cin, s);
    
    ofstream myfile("data.txt", ios::app); // class ofstream helps you to write information to a file (here data.txt)

    //myfile.open("data.txt"); it will by default open the file
    if (myfile.is_open())
    myfile << s;
    myfile.close();
    cout << "file write operation performed successfully!" << '\n';


    //file read operation
    string input;
    cout << "Reading from file operation started!" << '\n';
    ifstream obj("data.txt");
    getline(obj, input);
    cout << '\n';
    cout << input << '\n';
    cout << "string content printed!" << '\n';
    return 0;
}