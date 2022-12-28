print('Name: Abhay Singh Bisht')
print('University Roll No: 2061751')
print('Sec: A')
print('Roll NO: 1')
print()
nb_process = int(input('Enter number of processes: '))
a = list(map(int,input('Enter arrival time: ').split()))
b = list(map(int,input('Enter burst time: ').split()))
quanta = int(input('Enter time quanta: '))

arrival_d = dict()
burst_d = dict()

for i in range(nb_process):
    arrival_d[f'p{i+1}'] = a[i]
for i in range(nb_process):
    burst_d[f'p{i+1}'] = b[i]

arrival_list = sorted(arrival_d.items(), key=lambda kv:kv[1])

complete_d = dict()
total = arrival_list[0][1]
total_completion_time = sum(burst_d.values()) + arrival_list[0][1]     # total burst time 


while total_completion_time > 0:
    flag = False
    for i in range(nb_process):
        if burst_d[arrival_list[i][0]] <= 0:     # if process is terminated continue
            continue
        flag = True
        mini_ =  min(quanta,burst_d[arrival_list[i][0]])
        total = total + mini_# it maybe burst time is less than time quanta
        if mini_ == 0:
            total_completion_time -= 2
        else:
            total_completion_time -= mini_
        burst_d[arrival_list[i][0]] = burst_d.get(arrival_list[i][0]) - mini_    
            
        
        if burst_d[arrival_list[i][0]] <= 0 and arrival_list[i][0] not in complete_d.keys():    # check if the process having burst time less than 1 is alredy in completed_d
            complete_d[arrival_list[i][0]] = total
    if not flag:
        break


tat = []
waiting_t = []
for i in range(nb_process):
    tat.append(complete_d[f'p{i+1}'] - int(a[i]))
    waiting_t.append(tat[-1] - int(b[i]))

print('Process\t Completion time\t TAT\t Waiting time')
for i in range(nb_process):
    print(f'p{i+1}\t\t{complete_d[f"p{i+1}"]}\t\t',end='')
    print(f'{tat[i]}\t\t{waiting_t[i]}\t\t')

print('\nAverage TAT:',round(sum(tat)/nb_process,2))
print('Average Waiting Time',sum(waiting_t)/nb_process)