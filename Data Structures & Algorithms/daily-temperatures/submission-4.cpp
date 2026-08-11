class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
    vector<int> res(n, 0);
    
    // Use a vector as a stack and reserve space upfront
    // This ensures contiguous memory and no reallocations
    vector<int> stack;
    stack.reserve(n); 

    for (int i = 0; i < n; i++) {
        // Accessing the back of a vector is much faster than deque-based stack.top()
        while (!stack.empty() && temperatures[stack.back()] < temperatures[i]) {
            int prevIndex = stack.back();
            res[prevIndex] = i - prevIndex;
            stack.pop_back();
        }
        stack.push_back(i);
    }

    return res;
    }
};
