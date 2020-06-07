#include <iostream>

#include <boost/thread.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/fiber/all.hpp>

#define N 1000
#define MOD (int)100000007

using namespace std;
using namespace boost;

boost::atomic<int> a{ 0 };

void f(int x, int y, int z) {
    int tmp = 0;

    for (int i = 0; i < 100; ++i) {
	tmp += (x + y + z) % MOD;
    }

    a += tmp % MOD;
}

int main() {
    vector<boost::thread> ts;

    for (int i = 0; i < N; i++) {
	ts.push_back(boost::thread{f, i, i % 2, i % 3});
    }

    cerr << "Spawned " << N << " threads." << endl;

    for (int i = 0; i < N; i++) {
	ts[i].join();
    }

    cout << "a = " << a << endl;

    return EXIT_SUCCESS;
}
