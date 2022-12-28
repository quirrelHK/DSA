print('Ritesh Singh\nSec: A\n2060008\n')
import threading
import time

shared = 0
flag = [False,False]
turn = 0
N = 10

def process_0():
    global shared, flag, turn, N
    flag[0]=True
    turn = 1
    while(flag[1] and turn ==1):
        continue

    for _ in range(N):
        shared +=1
        print('Process 0: shared=',shared)
        time.sleep(0.1)

    flag[0]=False

def process_1():
    global shared, flag, turn, N
    flag[1]=True
    turn = 0
    while(flag[0] and turn ==0):
        continue

    for _ in range(N):
        shared +=1000
        print('Process 1: shared=',shared)
        time.sleep(0.1)

    flag[1]=False

if __name__ == '__main__':
    p0 = threading.Thread(target=process_0)
    p1 = threading.Thread(target=process_1)

    p0.start()
    p1.start()
