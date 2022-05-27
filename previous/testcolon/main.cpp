#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}


void compute (int in, int Out)
{
  int tmp1, tmp2;
  int totalNumWords = 1

  A: for (int i = 0; i < totalNumWords ; ++i) {
    tmp1[i] = in[i] * 3;
    tmp2[i] = in[i] * 3;
  }
  B: for (int i = 0; i < totalNumWords ; ++i) {
    tmp1[i] = tmp1[i] + 25;
  }
  C: for (int i = 0; i < totalNumWords ; ++i) {
    tmp2[i] = tmp2[i] * 2;
 }
  D: for (int i = 0; i <  totalNumWords ; ++i) {
     out[i] = tmp1[i] + tmp2[i] * 2;
   }
}
