# https://practice.geeksforgeeks.org/problems/account-merge/1

# TC: O(N*M*log(N))
# SC: O(N*M)
from implement_DSU import DSU


if __name__ == '__main__':
    n = int(input())
    accounts = []
    for _ in range(n):
        m = int(input())
        lst = input().split()
        accounts.append(lst[:])
        
    ds = DSU(n)
    map_mail_node = dict()
    for i in range(n):
        for j in range(1,len(accounts[i])):
            if map_mail_node.get(accounts[i][j],None) is None:
                map_mail_node[accounts[i][j]] = i
            else:
                # If the mail is already present then merging is required
                ds.union_by_size(i,map_mail_node[accounts[i][j]])
                
    merged_mails = [[] for _ in range(n)]
    for mail,node in map_mail_node.items():
        parent_node = ds.find_parent(node)
        merged_mails[parent_node].append(mail)
        
    ans = []
    # print(map_mail_node)
    for i in range(n):
        if len(merged_mails[i]) == 0:
            continue
        else:
            merged_mails[i].sort()
            temp = [accounts[i][0]]
            temp.extend(merged_mails[i])
            ans.append(temp[:])
            
    print(*ans)

                
                
         
        
    
