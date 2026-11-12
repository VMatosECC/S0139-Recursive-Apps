// S0139-Recursive-Apps.cpp 

#include <iostream>
#include <vector>
using namespace std;

int triangularNumber(int h) {
    //Base case
    if (h == 0)
        return 0;
    else
        return (h + triangularNumber(h - 1));
}



void experiment01() {
    //Triangular Numbers
    for (int i = 0; i < 10; i++) {
        int blocks = triangularNumber(i);
        cout << "A pyramid of height " << i
            << " needs " << blocks << " blocks\n";
    }
}
//----------------------------------------------------

bool isPalindrome(string s) {
    //Base case
    if (s.size() == 0) return true;

    if (s.front() != s.back())
        return false;
    else
        return isPalindrome(s.substr(1, s.size() - 2));
}


void experiment02() {
    //Palindromes
    string s = "racecar";
    cout << s << " is Palindrome? " << isPalindrome(s) << endl;

}

//string reverse(string s) {
//    if (s.empty())
//        return "";
//    else {
//        char leader = s.front();
//        string rest = s.substr(1);
//        return reverse(rest) + leader;
//    }
//
//}

string reverse(string s) {
    if (s.size() <= 1)
        return s;
    else {
        char first = s.front();
        char last = s.back();
        string rest = s.substr(1, s.size() -2 );
        return (last + reverse(rest) + first);
    }

}



void experiment03() {
    string s = "El Camino";
    cout << s << endl << reverse(s) << endl;
}

int binSearch(vector<int>& v, int first, int last, int key) {
    //base case
    if (first > last) return -1; //key not found

    int mid = (first + last) / 2;
    if (v[mid] < key) binSearch(v, mid + 1, last, key);
    else if (v[mid] > key) binSearch(v, first, mid - 1, key);
    else return mid; //key was found at mid

}

//-------------------------------------------------------
//Helper function
int binSearch(vector<int>& v, int key) {
    int first = 0;
    int last = v.size() - 1;

    return binSearch(v, first, last, key);
}




void experiment04() {
    vector<int> v{ 2, 5, 7, 9, 11, 15, 22, 27, 40, 65, 74 };
    for (auto val : v) cout << val << "  ";
    cout << endl;

    int key = 765;
    int pos = binSearch(v, key);
    cout << key << " was found at location " << pos << endl;
}



int main()
{
    //experiment01();
    //experiment02();
    //experiment03();
    experiment04();
    cout << "All done!\n";
}

