class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        packedList = []

        for pos, speed in zip(position, speed):
            packedList.append((pos, speed))
        
        packedList = sorted(packedList, key=lambda item: -item[0])
        numFleets = 0
        currFleetT = 0

        for carData in packedList:
            t = (target - carData[0]) / carData[1]

            if t > currFleetT:
                numFleets += 1
                currFleetT = t
        
        return numFleets