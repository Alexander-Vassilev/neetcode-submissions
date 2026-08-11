class Solution:

    def encode(self, strs: List[str]) -> str:
        metadata = ""
        string = ""

        for i in range(len(strs)):
            metadata += str(len(strs[i])) + " "
            string += strs[i]
        
        metadata += "."

        return metadata + string

    def decode(self, s: str) -> List[str]:
        temp = s.split(" ")
        splitLocations = []
        outputList = []

        for i in range(len(temp)):
            if ("." in temp[i]):
                break
            else:
                splitLocations.append(int(temp[i]))
        
        p = s.find(".")
        processed = s[p + 1:]

        for i in range(len(splitLocations)):
            outputList.append(processed[:splitLocations[i]])
            processed = processed[splitLocations[i]:]
        
        return outputList
        