print('Name: Abhay Singh Bisht')
print('University Roll No: 2061751')
print('Sec: A')
print('Roll NO: 1')
print()
nb_process = int(input('Enter number of processes: '))
a = list(map(int,input('Enter arrival time: ').split()))
b = list(map(int,input('Enter burst time: ').split()))
c = list(map(int,input('Enter priorities: ').split()))

arrival_d = dict()
burst_d = dict()
priority_d = dict()

for i in range(nb_process):
    arrival_d[f'p{i+1}'] = a[i]
    burst_d[f'p{i+1}'] = b[i]
    priority_d[f'p{i+1}'] = c[i]

complete_d  = dict()

arrival_list = sorted(arrival_d.items(), key=lambda kv:kv[1])
priority_list = sorted(priority_d.items(), key=lambda k:k[1], reverse=True)

total = arrival_list[0][1]
arrived = dict()
highest = priority_d[arrival_list[0][0]]
j = arrival_list[-1][1]

while j > 0:
    flag = False
    for i in range(nb_process):
        if j < 1:
            break
        if arrival_list[i][1] <= total and arrived.get(arrival_list[i][0]) == None:
            arrived[arrival_list[i][0]] = arrival_list[i][1]
            highest = max(highest,priority_d[arrival_list[i][0]])
        elif arrival_list[i][1] > total and arrived.get(arrival_list[i][0])==None:
            while(arrival_list[i][1] > total):
                total+=1
            arrived[arrival_list[i][0]] = arrival_list[i][1]
            highest = max(highest,priority_d[arrival_list[i][0]])
        if arrived.get(arrival_list[i][0]) != None and priority_d[arrival_list[i][0]] == highest:
            if burst_d[arrival_list[i][0]] <= 0:
                continue
            else:
                flag = True
                total+=1
                j-=1
                complete_d[arrival_list[i][0]] = total
                burst_d[arrival_list[i][0]] = burst_d.get(arrival_list[i][0]) - 1
    if not flag:
        break

for i in range(nb_process):
    if burst_d[priority_list[i][0]] < 1:
        continue
    total += burst_d[priority_list[i][0]]
    complete_d[priority_list[i][0]] = total
    burst_d[priority_list[i][0]] = 0

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


