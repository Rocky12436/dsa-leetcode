class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;
    for(int  i  = n-2;i>=0;i--)
    {
        st.push(arr[i]);
    }
    //STACK
    
    for(int i = n - 1; i >= 0; i--) {
        
        // Remove all smaller or equal elements
        while(!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack is empty → no greater element
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();

        // Push current element
        st.push(arr[i]);
    }

    return res;
    }
};