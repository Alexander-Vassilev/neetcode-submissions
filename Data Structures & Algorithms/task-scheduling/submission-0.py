class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        priorQ = []
        taskFreqDict = {}

        for task in tasks:
            if task in taskFreqDict:
                taskFreqDict[task] += 1
            else:
                taskFreqDict[task] = 1
            
        for key in taskFreqDict:
            priorQ.append((-taskFreqDict[key], key))
        
        heapq.heapify(priorQ)
        waitList = []
        count = 0

        while priorQ or waitList:
            print(waitList)
            count += 1

            if waitList:
                for i in range(len(waitList)):
                    el = waitList[i]
                    waitList[i] = [el[0], el[1] - 1]

                if waitList[-1][1] <= 0:
                    renewedTask = waitList.pop()
                    heapq.heappush(priorQ, renewedTask[0])

            if priorQ:    
                task = heapq.heappop(priorQ)
                prior = task[0] + 1

                if -prior > 0:
                    waitList.insert(0, [(prior, task[1]), n + 1])

        return count