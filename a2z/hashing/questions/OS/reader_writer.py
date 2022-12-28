print('Ritesh Singh\nSec: A\n2060008\n')

import threading as thread
import random
import time

global x                #Shared Data
x = 0
lock = thread.Lock()    #Lock for synchronising access

def Reader():
    global x
    print('Reader is Reading!')
    lock.acquire()      #Acquire the lock before Reading (mutex approach)
    time.sleep(0.2)
    print('Shared Data:', x)
    time.sleep(0.2)
    lock.release()      #Release the lock after Reading
    time.sleep(0.2)
def Writer():
    global x
    print('Writer is Writing!')
    lock.acquire()   
    time.sleep(0.2)   
    x += 1              #Write on the shared memory
    print('Writer is Releasing the lock!')
    lock.release()      #Release the lock after Writing
    time.sleep(0.2)

if __name__ == '__main__':
    for i in range(0, 10):
        randomNumber = random.randint(0, 100)   #Generate a Random number between 0 to 100
        if(randomNumber > 50):
            Thread1 = thread.Thread(target = Reader)
            Thread1.start()
        else:
            Thread2 = thread.Thread(target = Writer)
            Thread2.start()

Thread1.join()
Thread2.join()
