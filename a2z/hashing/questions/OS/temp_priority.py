# Define a list of processes with their arrival times, burst times, and priorities
processes = [("p1", 2, 4, 10), ("p2", 1, 7, 1), ("p3", 3, 5, 4), ("p4", 4, 3, 12), ("p5", 2, 1, 9), ("p6", 5, 6, 13)]

# Set the initial time to 0
time = 0

# Initialize a dictionary to store the completion times and waiting times for each process
completion_times = {}
waiting_times = {}

# Initialize a dictionary to store the remaining burst times for each process
remaining_burst_times = {process[0]: process[2] for process in processes}

# Initialize a list to store the processes that still need to be executed
pending_processes = [(process[0], process[1], process[3]) for process in processes]

# Loop until all processes have completed
while pending_processes:
  # Find the next process to execute by sorting the remaining burst times
  next_processes = sorted(pending_processes, key=lambda x: x[2], reverse=True)
  name, arrival, priority = next_processes[0]
  if arrival > time:
    # If the process has not arrived yet, advance the time to the arrival time
    time = arrival
  # Calculate the remaining burst time for the process
  remaining = remaining_burst_times[name]
  # Execute the process for one time unit
  print(f"Executing process {name} for one time unit")
  time += 1
  # Update the remaining burst time for the process
  remaining_burst_times[name] = remaining - 1
  if remaining_burst_times[name] == 0:
    # If the process has completed, remove it from the list of pending processes
    pending_processes.remove((name, arrival, priority))
    # Calculate the completion time and waiting time for the process
    completion_time = time
    waiting_time = time - arrival - remaining
    # Store the completion time and waiting time in the dictionaries
    completion_times[name] = completion_time
    waiting_times[name] = waiting_time

# Print the completion times and waiting times for each process
for name, completion_time in completion_times.items():
  print(f"Process {name} has completion time {completion_time}")
for name, waiting_time in waiting_times.items():
  print(f"Process {name} has waiting time {waiting_time}")
