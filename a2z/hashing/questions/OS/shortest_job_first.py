print('Name: Abhay Singh Bisht')
print('University Roll No: 2061751')
print('Sec: A')
print('Roll NO: 1')
print()

nb_process = int(input('Enter number of processes: '))
a = list(map(int,input('Enter arrival time: ').split()))
b = list(map(int,input('Enter burst time: ').split()))

arrival_d = dict()
burst_d = dict()

for i in range(nb_process):
    arrival_d[f'p{i+1}'] = a[i]
for i in range(nb_process):
    burst_d[f'p{i+1}'] = b[i]

burst_list = sorted(burst_d.items(), key=lambda kv:kv[1])
complete_d = dict()

# Find the process with least arrival time
temp = min(arrival_d.values())
first_p = [(k,v) for k,v in arrival_d.items() if arrival_d[k] == temp]
for i in range(nb_process):
    if not complete_d:  # first the process with least arrival time will be executed
        complete_d[first_p[0][0]] = burst_d[first_p[0][0]] + first_p[0][1]
        burst_d[first_p[0][0]] = -1
        del burst_list[0]
        continue
   
    if burst_d[burst_list[0][0]] != -1:     # if process is not already executed then go inside if
        if arrival_d[burst_list[0][0]] > list(complete_d.values())[-1]:      # if arrival time of current process is greater than current time stamp
            continue
        else:
            complete_d[burst_list[0][0]] = list(complete_d.values())[-1] + burst_list[0][1]
            burst_d[burst_list[0][0]] = -1
            del burst_list[0]

for k,v in burst_d.items():    # add the remaining processes
    if v != -1:
        if complete_d.get(k)==None:
             complete_d[k] = v + arrival_d[k]
        else:
            complete_d[k] = v + list(complete_d.values())[-1]


tat = []
waiting_t = []
for i in range(nb_process):
    tat.append(complete_d[f'p{i+1}'] - a[i])
    waiting_t.append(tat[-1] - b[i])

print('Process\t Completion time\t TAT\t Waiting time')
for i in range(nb_process):
    print(f'p{i+1}\t\t{complete_d[f"p{i+1}"]}\t\t',end='')
    print(f'{tat[i]}\t\t{waiting_t[i]}\t\t')

print('\nAverage TAT:',round(sum(tat)/nb_process,2))
print('Average Waiting Time',sum(waiting_t)/nb_process)
