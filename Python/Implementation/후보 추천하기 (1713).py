import sys

class LRU:
    time=0
    recommend=0
    number=0
    def __init__ (self, time, recommend, number):
        self.time = time
        self.recommend = recommend
        self.number = number
    
N = int(sys.stdin.readline())
m = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().strip().split()))
memory = []

def tick():
    for i in range(len(memory)):
        memory[i].time +=1

def find_num(number):
    for i in range(len(memory)):
        if memory[i].number == number:
            return i
    return -1

def delete_num():
    global memory
    memory = sorted(memory, key = lambda x: (x.recommend, -x.time))
    memory.pop(0)

for number in arr:
    idx = find_num(number)
    if  idx!= -1:
        memory[idx].recommend+=1
    else:
        if len(memory) < N:
            memory.append(LRU(1,1,number))
        else:
            delete_num()
            memory.append(LRU(1,1,number))
    tick()

memory = sorted(memory, key = lambda x : x.number)
for i in range(len(memory)):
    print(memory[i].number, end=' ')
