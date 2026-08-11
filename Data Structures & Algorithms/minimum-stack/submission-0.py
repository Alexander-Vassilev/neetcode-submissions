import heapq

class MinStack:

    def __init__(self):
        self.l = []
        self.minHistory = []

    def push(self, val: int) -> None:
        self.l.append(val)

        if not self.minHistory:
            self.minHistory.append(val)
        else:
            if val < self.minHistory[-1]:
                self.minHistory.append(val)
            else:
                self.minHistory.append(self.minHistory[-1])

    def pop(self) -> None:
        self.l.pop()
        self.minHistory.pop()

    def top(self) -> int:
        return self.l[-1]

    def getMin(self) -> int:
        return self.minHistory[-1]
