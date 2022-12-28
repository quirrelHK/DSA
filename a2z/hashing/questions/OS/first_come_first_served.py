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

arrival_d = sorted(arrival_d.items(), key=lambda kv:kv[1])
complete_d = dict()

for i in range(nb_process):
    if not complete_d:
        complete_d[arrival_d[i][0]] = arrival_d[i][1] + burst_d[arrival_d[i][0]]
    else:
        if arrival_d[i][1] <= list(complete_d.values())[-1]:
            complete_d[arrival_d[i][0]] = list(complete_d.values())[-1] + burst_d[arrival_d[i][0]]
        else:
            complete_d[arrival_d[i][0]] =  arrival_d[i][1] + burst_d[arrival_d[i][0]]


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
