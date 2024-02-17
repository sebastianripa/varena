#include <iostream>

using namespace std;

int v[100001];

void ciur() {
    v[0] = 0;
    v[1] = 0;
    for(int i = 2; i <= 100000; i += 2)
        v[i] = 2;
    for(int i = 3; i <= 100000; i += 2) {
        if(!v[i]) {
            v[i] = i;
            for(int j = i*i; j <= 100000; j += i*2) {
                if(!v[j])
                    v[j] = i;
            }
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
