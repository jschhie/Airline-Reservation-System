#include <iostream>

using namespace std;
int main()
{

    int* matrixPtr;
    int temp[15];
    
    matrixPtr = temp;

    for (int i = 0; i < 15; i++)
    {
        matrixPtr[i] = -1;
        cout << "val: " << i << matrixPtr[i] << endl;
    }

    matrixPtr[3] = 100;
    cout << matrixPtr[3] << endl;

    return 0;

}
