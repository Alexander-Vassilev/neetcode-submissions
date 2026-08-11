public class Solution {
    public List<List<string>> GroupAnagrams(string[] strs) {
        List<List<string>> groupings = new List<List<string>>();
        string[] sortedStrs = new string[strs.Length];
        Dictionary<string, string> strPairs = new Dictionary<string, string>();

        for (int i = 0; i < strs.Length; i++) {
            if (!strPairs.ContainsKey(strs[i])) {
                char[] charred = strs[i].ToCharArray();
                Array.Sort(charred);
                strPairs.Add(strs[i], new string(charred));
            }
        }

        for (int i = 0; i < strs.Length; i++) {
            bool hasAnagram = false;

            for (int j = 0; j < groupings.Count; j++) {
                if (!hasAnagram) {
                    if (strPairs[groupings[j][0]] == strPairs[strs[i]]) {
                       groupings[j].Add(strs[i]);
                       hasAnagram = true;
                    }
                }
            }

            if (!hasAnagram) {
                groupings.Add(new List<string> {strs[i]});
            }
        }

        return groupings;
    }
}