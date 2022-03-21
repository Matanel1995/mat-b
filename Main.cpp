#include <iostream>
#include "mat.hpp"
#include <stdexcept>

using namespace std;
using namespace ariel;
int main(){
    bool isOk = true;
    int col;
    int row;
    char symbol1;
    char symbol2;
    while(isOk == true){
        try{
        cout << "Enter the row size:" << endl;
        cin >> row;
        cout << "Enter the col size:" << endl;
        cin >> col;
        cout << "Enter the first symbol:" << endl;
        cin >> symbol1;
        cout << "Enter the second symbol:" << endl;
        cin >> symbol2;
        cout << mat(col,row,symbol1,symbol2) << endl;
        isOk = false;
        }
        catch(invalid_argument err) {
            cout << "Make sure you enterd legit values!!" << endl <<err.what() << endl;
        }
        catch (out_of_range err){
            cout << "Make sure you enterd legit values!!" << endl <<err.what() << endl;
        }
    }
    cout << "Done!" << endl;
}