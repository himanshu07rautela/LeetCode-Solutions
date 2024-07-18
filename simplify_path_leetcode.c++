

class Solution {
public:
    string simplifyPath(string path) {
        // Handle edge cases
        if (path == "//" || path == "/./" || path == "/../" || path == "//./" || path == "/..//"
            || path == "//..//" || path == "/.//" || path == "//.//"||path=="/..") {
            return "/";
        }

        // Remove consecutive slashes
        string ans;
        ans += '/'; // initial slash added
        char prev = path[0];
        for (int i = 1; i < path.size(); i++) {
            char curr = path[i];
            if (curr == '/' && prev == '/') {
                continue;
            } else {
                ans += path[i];
            }
            prev = curr;
        }

        // Use a stack to process the components of the path
        stack<string> st;
        string temp;
        for (int i = 0; i < ans.size(); ++i) {
            if (ans[i] == '/') {
                if (temp == "..") {
                    if (!st.empty()) st.pop();
                } else if (temp != "." && !temp.empty()) {
                    st.push(temp);
                }
                temp.clear();
            } else {
                temp += ans[i];
            }
        }

        // Process the last component if there's any
        if (temp == ".." && !st.empty()) {
            st.pop();
        } else if (temp != "." && !temp.empty()) {
            st.push(temp);
        }

        // Construct the final simplified path
        string result;
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        // done because we were not looking at the final token
        if (result == "//" || result == "/./" || result == "/../" || result == "//./" || result == "/..//"
            || result == "//..//" || result == "/.//" || result == "//.//"||result=="/..") {
            return "/";
        }

        return result.empty() ? "/" : result;
    }
};


// one of the best stack questions i've ever done