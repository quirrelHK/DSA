# Define a list of processes with their arrival times and burst times
processes = [("p1", 1, 7), ("p2", 2, 3), ("p3", 3, 1), ("p4", 4, 4), ("p5", 5, 5)]


# Sort the list of processes by arrival time
processes.sort(key=lambda x: x[1])

# Set the initial time to 0
time = 0

# Initialize a dictionary to store the completion times and waiting times for each process
completion_times = {}
waiting_times = {}

# Initialize a dictionary to store the remaining burst times for each process
remaining_burst_times = {process[0]: process[2] for process in processes}

# Loop until all processes have completed
while remaining_burst_times:
  # Find the next process to execute by sorting the remaining burst times
  next_processes = sorted(remaining_burst_times, key=lambda x: remaining_burst_times[x])
  for process in next_processes:
    name, arrival, burst = [p for p in processes if p[0] == process][0]
    if arrival > time:
      # If the process has not arrived yet, advance the time to the arrival time
      time = arrival
    # Calculate the remaining burst time for the process
    remaining = remaining_burst_times[process]
    # Execute the process for one time unit
    print(f"Executing process {name} for one time unit")
    time += 1
    # Update the remaining burst time for the process
    remaining_burst_times[process] = remaining - 1
    if remaining_burst_times[process] == 0:
      # If the process has completed, remove it from the dictionary
      del remaining_burst_times[process]
      # Calculate the completion time and waiting time for the process
      completion_time = time
      waiting_time = time - arrival - burst
      # Store the completion time and waiting time in the dictionary
      completion_times[name] = completion_time
      waiting_times[name] = waiting_time

# Print the completion times and waiting times for each process
for name, completion_time in completion_times.items():
  print(f"Process {name} has completion time {completion_time}")
for name, waiting_time in waiting_times.items():
  print(f"Process {name} has waiting time {waiting_time}")
