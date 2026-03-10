//Deque (Double-Ended Queue)
//A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. 
//It provides more flexibility than a standard queue or stack.

from collections import deque

dq = deque()

dq.append(10)        # push_back
dq.appendleft(5)     # push_front
dq.append(20)

print("Deque:", dq)

dq.pop()             # pop_back
dq.popleft()         # pop_front

print("After deletion:", dq)

print("Front element:", dq[0])
print("Rear element:", dq[-1])
print("Size:", len(dq))
print("Is empty:", len(dq) == 0)
