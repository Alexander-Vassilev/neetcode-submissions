class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        nums.sort()
        counter = 1
        current_el = nums[0]
        frequency_map = {}

        for i in range(1, len(nums)):
            if nums[i] == current_el:
                counter += 1
            else:
                frequency_map.update({current_el: counter})
                current_el = nums[i]
                counter = 1
        
        frequency_map.update({current_el: counter})
        sorted_by_value = sorted(frequency_map.items(), key=lambda kv: (kv[1], kv[0]))
        sorted_by_value.reverse()
        output_list = []

        for i in range(k):
            output_list.append(sorted_by_value[i][0])

        return output_list
