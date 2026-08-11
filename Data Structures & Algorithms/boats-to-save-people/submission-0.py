class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        total = 0
        left = 0
        right = len(people) - 1
        currBoat = 0
        people.sort()

        while left <= right:
            print(str(left) + ": " + str(right))

            if people[left] + people[right] <= limit:
                left += 1
                right -= 1
                total += 1    
            else:
                right -= 1
                total += 1
        
        return total