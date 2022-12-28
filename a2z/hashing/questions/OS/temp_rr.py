# Define a list of processes with their arrival times and burst times
processes = [("p1", 5, 5), ("p2", 4, 6), ("p3", 3, 7), ("p4", 1, 9), ("p5", 2, 2), ("p6", 6, 3)]

# Set the time quantum (the fixed time slice for each process)
quantum = 2

# Set the initial time to 0
time = 0

# Initialize a dictionary to store the completion times and waiting times for each process
completion_times = {}
waiting_times = {}

# Initialize a dictionary to store the remaining burst times for each process
remaining_burst_times = {process[0]: process[2] for process in processes}

# Initialize a list to store the processes that still need to be executed
pending_processes = [(process[0], process[1]) for process in processes]

# Loop until all processes have completed
while pending_processes:
  name, arrival = pending_processes.pop(0)
  if arrival > time:
    # If the process has not arrived yet, advance the time to the arrival time
    time = arrival
  # Calculate the remaining burst time for the process
  remaining = remaining_burst_times[name]
  if remaining > quantum:
    # If the remaining burst time is greater than the quantum, execute the process for the quantum time
    print(f"Executing process {name} for {quantum} time units")
    time += quantum
    # Update the remaining burst time for the process
    remaining_burst_times[name] = remaining - quantum
    # Add the process to the end of the list of pending processes
    pending_processes.append((name, time))
  else:
    # If the remaining burst time is less than or equal to the quantum, execute the process to completion
    print(f"Executing process {name} for {remaining} time units")
    time += remaining
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
