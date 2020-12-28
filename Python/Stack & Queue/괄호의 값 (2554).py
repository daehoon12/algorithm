import sys
from collections import deque

st = deque()
s = sys.stdin.readline().strip()
answer=0
for i in s:
    if i == ')':
        t = 0
        while len(st) != 0:
            top = st.pop()
            if top == '(':
                if t==0:
                    st.append(2)
                else:
                    st.append(2*t)
                break
            elif top == '[':
                print(0)
                exit(0)
            else:
                t+= int(top)
    elif i == ']':
        t = 0
        while len(st) != 0:
            top = st.pop()
            if top == '[':
                if t==0:
                    st.append(3)
                else:
                    st.append(3*t)
                break
            elif top == '(':
                print(0)
                exit(0)
            else:
                t+= int(top)
    else:
        st.append(i)

for i in st:
    if i == '(' or i =='[':
        print(0)
        exit(0)
    else:
        answer+=int(i)
print(answer)
