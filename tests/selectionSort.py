import pycee
import gc
import time
import random

def selectionSortTest():
    l = [random.randint(0,10000000) for r in xrange(100)]
    t = time.time()
    a = pycee.selectionSort(l)
    print (time.time() - t)*1000
    print gc.collect()
    t = time.time()
    l.sort()
    print (time.time() - t)*1000
    if a == l:
        pass
    else:
        assert False

if __name__ == "__main__":
    selectionSortTest()
