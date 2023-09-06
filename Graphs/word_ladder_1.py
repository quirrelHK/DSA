# https://practice.geeksforgeeks.org/problems/word-ladder/1

# TC: O(N*W + E); W-> length of word
# SC: O(N)

from collections import deque

def bfs(start_word,end_word,word_list):
    q = deque([(start_word,1)])
    if start_word in word_list:
        word_list.remove(start_word)
    
    while q:
        word,step = q.popleft()
        
        if word == end_word: return step
        size = len(word)
        for i in range(size):
            original = word[i]
            for val in range(ord('a'),ord('z')+1):
                # word = list(word)
                # word[i] = chr(val)
                # word = ''.join(word)
                word = word[:i]+chr(val)+word[i+1:] 
                if word in word_list:
                    q.append((word,step+1))
                    word_list.remove(word)
            word = word[:i]+original+word[i+1:]
            # word[i] = original
    return 0


if __name__ == '__main__':
    start_word,end_word = input().split()
    word_list = input().split()
    word_list = set(tuple(word_list))

    print(bfs(start_word,end_word,word_list))
    
    
    