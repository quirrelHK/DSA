print('Ritesh Singh\nSec: A\n2060008\n')
import threading
import time
from random import randint

# Semaphores
buffer_mutex = threading.Semaphore(1)
buffer_empty = threading.Semaphore(0)
buffer_full = threading.Semaphore(0)

# Shared buffer
buffer = []

# Maximum size of the buffer
max_size = 5
counter = 0

def produce_item():
    item = randint(1,20)
    print(f'Producer produces item: {item}')
  
    return item

def consume_item(item):
    print(f'Consumer consumes item: {item}')
    


def producer():
  global buffer
  global counter

  
  while True:

    if counter > 20:
        break
    # Produce an item
    item = produce_item()
    
    # Acquire the buffer mutex
    buffer_mutex.acquire()

    # Add the item to the buffer
    buffer.append(item)

    # Release the buffer mutex
    buffer_mutex.release()

    # Signal that the buffer is not empty
    buffer_empty.release()
    time.sleep(.2)
    counter +=1

def consumer():
  global buffer, counter
  while True:
    if counter > 20: break
    # Acquire the buffer empty semaphore
    buffer_empty.acquire()

    # Acquire the buffer mutex
    buffer_mutex.acquire()

    # Remove an item from the buffer
    item = buffer.pop(0)

    # Release the buffer mutex
    buffer_mutex.release()

    # Signal that the buffer is not full
    buffer_full.release()

    # Consume the item
    consume_item(item)
    time.sleep(.2)

    counter+=1

# Start the producer and consumer threads
producer_thread = threading.Thread(target=producer)
consumer_thread = threading.Thread(target=consumer)
producer_thread.start()
consumer_thread.start()

producer_thread.join()
consumer_thread.join()