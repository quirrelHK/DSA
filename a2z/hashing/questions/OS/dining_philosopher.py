print('Ritesh Singh\nSec: A\n2060008\n')
import threading
import time

# The number of philosophers
NUM_PHILOSOPHERS = 5
counter = 0
# A list of semaphores, one for each chopstick
chopsticks = [threading.Semaphore(1) for _ in range(NUM_PHILOSOPHERS)]
def philosopher(id):
  # The philosopher's left and right chopsticks
  global counter
  left_chopstick = chopsticks[id]
  right_chopstick = chopsticks[(id + 1) % NUM_PHILOSOPHERS]
  
  while True:
    # Think for a while
    # time.sleep(0.1)
    if counter > 20: break
    
    # Acquire the left chopstick
    left_chopstick.acquire()
    try:
      # Acquire the right chopstick
      try:
        right_chopstick.acquire()

        # Eat for a while
        print(f'Philosopher {id} is eating.')
        counter +=1
        # time.sleep(0.2)
      finally:
        # Release the right chopstick
        right_chopstick.release()
        # time.sleep(0.2)
    finally:
      # Release the left chopstick
      left_chopstick.release()
      time.sleep(0.2)
    

# Create and start the philosopher threads
philosophers = [threading.Thread(target=philosopher, args=(i,)) for i in range(NUM_PHILOSOPHERS)]
for philosopher in philosophers:
  philosopher.start()
