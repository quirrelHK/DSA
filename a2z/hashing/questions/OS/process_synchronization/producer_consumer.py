print('Ritesh Singh\nSec: A\n2060008\n')
import threading
import time
 
# Shared Memory variables
CAPACITY = 10
buffer = [-1 for _ in range(CAPACITY)]
in_index = 0
out_index = 0
count = 0
N = 10

def producer():
    global CAPACITY, buffer, in_index, out_index, N
    global count
    counter=0
    items_produced = 0
     
    while items_produced < N:
        while count == CAPACITY-1:
            continue
        counter += 1
        buffer[in_index] = counter
        in_index = (in_index + 1)%CAPACITY
        print("Producer produced:", counter)
        
        time.sleep(0.35)
        count+=1
        
        items_produced += 1

def consumer():
    global CAPACITY, buffer, in_index, out_index, N
    global count
     
    items_consumed = 0
     
    while items_consumed < N:
        while(count <= 0):
            continue
        item = buffer[out_index]
        out_index = (out_index + 1)%CAPACITY
        print("Consumer consumed item:",item)     
        
        time.sleep(0.75)
        count-=1
        
        items_consumed += 1

if __name__ == '__main__':
    pro = threading.Thread(target=producer)
    con = threading.Thread(target=consumer)
    pro.start()
    con.start()
    pro.join()
    con.join()
