package main

import (
	"fmt"
	"sync"
	"sync/atomic"
)

// N is the number of goroutines to be spawned.
const N int32 = 1000

// MOD is the modulus of the operations.
const MOD int32 = 100000007

var a int32 = 0

func f(wg *sync.WaitGroup, x, y, z int32) {
	var tmp int32 = 0

	for i := int32(0); i < 100; i++ {
		tmp += (x + y + z) % MOD
	}

	atomic.AddInt32(&a, tmp%MOD)
	wg.Done()
}

func main() {
	var wg sync.WaitGroup

	for i := int32(0); i < N; i++ {
		wg.Add(1)
		go f(&wg, i, i%2, i%3)
	}

	fmt.Printf("Spawned %d goroutines.\n", N)

	wg.Wait()

	fmt.Printf("a = %d\n", a)
}
