class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = strs[0]

        for string in strs:
            while not prefix == string[:len(prefix)]:
                prefix = prefix[:len(prefix) - 1]
        
        return prefix

tests = []
tests.append((["h", "h", "h", "h"], "h"))
tests.append((["", "", ""], ""))
tests.append((["gan", "gan", "gan", ""], ""))
tests.append((["gan", "gan", "gan"], "gan"))
tests.append((["chant", "chandelier", "chair"], "cha"))
tests.append((["a", "b", "c", "d"], ""))
sol = Solution()

for test in tests:
    assert sol.longestCommonPrefix(test[0]) == test[1], "test failed"