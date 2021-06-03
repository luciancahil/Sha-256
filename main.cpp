#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sha256 {
  public:
    //int myNum;
    string mainString;
    vector<unsigned> parts;
    long long length;

    Sha256(string s){
        mainString = s;
        length = mainString.length();
        int padding = 64 - (length % 64 + 1) - 1; // plus 1, because we need one byte for the ending 1, and -1 for the size byte

        std:cout <<"Main String: " << mainString << "\n";

        // adding every character in the string to the parts array
        for(int i = 0; i < length; i++){
            parts.insert(parts.begin() + i, int(mainString.at(i)));
        }

        // adding the 1 to end the original message

        cout << length << "\n";

        for(int i = 0; i < parts.size(); i++){
            cout << "part " << i << " :" << parts[i] << " " << char(parts[i]) << "\n";
        }


        for(int i = 0; i < padding; i++){
            parts.insert(parts.begin() + length + i, 0);
        }



        // adding the length in bits of the original string
        parts.insert(parts.begin() + length, 128);
        parts.insert(parts.begin() + length + padding + 1, length * 8);


        for(int i = 0; i < parts.size(); i++){
            cout << "part " << i << " :" << parts[i] << " " << char(parts[i]) << "\n";
        }
    }
};


int leftRotate(int n, unsigned int d)
{

    /* In n<<d, last d bits are 0. To
     put first 3 bits of n at
    last, do bitwise or of n<<d
    with n >>(INT_BITS - d) */
    return (n << d)|(n >> (INT_BITS - d));
}

/*Function to right rotate n by d bits*/
int rightRotate(int n, unsigned int d)
{
    /* In n>>d, first d bits are 0.
    To put last 3 bits of at
    first, do bitwise or of n>>d
    with n <<(INT_BITS - d) */
    return (n >> d)|(n << (INT_BITS - d));
}


int main()
{
    Sha256* hasher = new Sha256("Hello World");
    return 0;
}


