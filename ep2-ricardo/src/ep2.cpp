
#include <stdlib.h>
#include <stdio.h>
#include <LIMITs.h>
#include <math.h>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

#define Prime(i) (2*(i)+3)
//#define MAX 65536  // 2^16
//#define LIMIT 127  // Prime(126)*Prime(126) == 65025, o prox valor estoura o max 
#define MAX 1048576
#define LIMIT 510
unsigned int is_prime[MAX];

int init() {
    for (int i = 0; i < MAX; i++)
        is_prime[i] = 1;

    cout << "setup done MAX = " << MAX << " LIMIT = " << LIMIT << endl;

    for (int i = 0; i < LIMIT; i++) {
        int limit = (int) floor((MAX/(float)Prime(i))/2 - 1.5); 
        cout << "P(i)=" << Prime(i) << ": " << limit << endl;
        for (int j = 0; j < limit; j++) {
            int p = Prime(i) * Prime(j);
            cout << "  P(j)=" << Prime(j) << ": " << p << endl;
            is_prime[p] = 0;
        }
    }

    cout << endl;

    for (int i = 0; i < MAX; i++)
        if (is_prime[i]) cout << Prime(i) << " primo" << endl;

    return 0;
}

int main() {
    init();
    return 0;
}
