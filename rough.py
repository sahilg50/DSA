from queue import Queue
import copy
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Q = Queue()
# Convert the wordList to set
S = set(wordList)
ansList = []
usedList = [beginWord]
level = 0
Q.put([beginWord])
while(not Q.empty()):
    vec = Q.get()
    if(len(vec) > level):
       level += 1
       for word in usedList:
          if(word in S): S.remove(word)

    wordToBeTransformed = vec[-1]
    if(wordToBeTransformed == endWord):
        if(len(ansList) == 0): ansList.append(vec)
        elif(len(ansList[0]) == len(vec)): ansList.append(vec)

    for i in range(len(wordToBeTransformed)):
        originalLetter = wordToBeTransformed[i]
        for j in range(ord('a'), ord('z') + 1):
            wordToBeTransformed = wordToBeTransformed[:i] + chr(j) + wordToBeTransformed[i+1:]
            if(wordToBeTransformed in S):
                usedList.append(wordToBeTransformed)
                vec.append(wordToBeTransformed)
                temp = copy.copy(vec)
                Q.put(temp)
                vec.pop()

        wordToBeTransformed = wordToBeTransformed[0:i] + originalLetter + wordToBeTransformed[i+1:]

print(ansList)