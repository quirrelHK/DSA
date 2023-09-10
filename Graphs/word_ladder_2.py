# https://practice.geeksforgeeks.org/problems/word-ladder-ii/1
from collections import deque


def bfs(start_word,end_word,word_list):
    word_list = set(tuple(word_list))
    ans = []
    q = deque()
    q.append([start_word])
    if start_word in word_list:
        word_list.remove(start_word)
    level = 0
    words_used = [start_word]
    while q:
        my_list = q.popleft()
        size = len(my_list)
        if size > level:
            level += 1
            for word in words_used:
                if word in word_list:
                    word_list.remove(word)
            words_used = []
        # print(my_list)
        word = my_list[-1]
        if word == end_word:
            if len(ans) == 0: ans.append(my_list)
            elif len(ans[0]) == len(my_list): ans.append(my_list)
            
        
        for j in range(len(word)):
            original = word[j]
            for val in range(ord('a'),ord('z')+1):
                # print(word,chr(val))
                word = word[:j]+ chr(val) + word[j+1:]
                if word in word_list:
                    my_list.append(word)
                    words_used.append(word)
                    q.append(my_list[:])
                    my_list.pop()
            word = word[:j] + original + word[j+1:]
                
    return ans
        

if __name__ == '__main__':
    start_word,end_word = input().split()
    word_list = input().split()
    
    ans = bfs(start_word,end_word,word_list)
    print(ans)
    