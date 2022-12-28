# Define a list of processes with their arrival times and burst times
processes = [("p1", 0, 2), ("p2", 1, 3), ("p3", 2, 6), ("p4", 3, 5), ("p5", 4, 4)]

# Set the initial time to 0
time = 0

# Initialize a dictionary to store the completion times and waiting times for each process
completion_times = {}
waiting_times = {}

# Loop through each process and execute it in order of arrival
for process in processes:
  name, arrival, burst = process
  if arrival > time:
    # If the process has not arrived yet, advance the time to the arrival time
    time = arrival
  print(f"Executing process {name} from time {time} to {time + burst}")
  # Calculate the completion time and waiting time for the process
  completion_time = time + burst
  waiting_time = time - arrival
  # Store the completion time and waiting time in the dictionary
  completion_times[name] = completion_time
  waiting_times[name] = waiting_time
  # Advance the time by the burst time of the process
  time += burst

# Print the completion times and waiting times for each process
for name, completion_time in completion_times.items():
  print(f"Process {name} has completion time {completion_time}")
for name, waiting_time in waiting_times.items():
  print(f"Process {name} has waiting time {waiting_time}")
