#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include <boost/intrusive_ptr.hpp>
#include <boost/fiber/all.hpp>

#define N 1000
#define MOD (int)100000007

using namespace std;
using namespace boost;

atomic<int> a{ 0 };


void f(int x, int y, int z) {
    int tmp = 0;

    for (int i = 0; i < 100; ++i) {
	tmp += (x + y + z) % MOD;
    }

    a += tmp % MOD;
    this_fiber::yield();
}

int main() {
    vector<fibers::fiber> fibers;

    for (int i = 0; i < N; i++) {
	fibers.push_back(fibers::fiber(f, i, i % 2, i % 3));
    }

    cerr << "Spawned " << N << " fibers." << endl;

    for (int i = 0; i < N; i++) {
	fibers[i].join();
    }

    cout << "a = " << a << endl;

    return EXIT_SUCCESS;
}
