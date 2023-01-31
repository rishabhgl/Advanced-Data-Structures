#include <iostream>
using namespace std;

//https://www.codechef.com/problems/MYSITM


int main(){
    unsigned long int test;
    cin >> test;
    unsigned long int num, width , height;
    int sol[test];
    for (int i = 0 ; i < test; i++)
    {
        cin >> num;
        cin >> height;
        cin >> width;
        unsigned long int low = 1;
        unsigned long int high = num * height * width;
        unsigned long int mid;
        unsigned long int expr;
        while (low < high)
        {
            mid  = (low + high)/2;
            expr = (mid/height)*(mid/width);
            if (expr >= num) 
                high = mid;
            else if (expr < num)
                low = mid + 1;
        } 
        sol[i] = high;
    }
    for (int i = 0 ; i < test; i++)
    {
        cout << sol[i] << endl;
    }
    return 0;
}