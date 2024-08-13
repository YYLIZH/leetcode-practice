#include <string>
#include <stack>

using namespace std;

// O(n) memory
class SolutionOne
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> s_stack;
        stack<char> t_stack;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '#')
            {
                s_stack.push(s[i]);
            }
            else
            {
                if (!s_stack.empty())
                {
                    s_stack.pop();
                }
            }
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] != '#')
            {
                t_stack.push(t[i]);
            }
            else
            {
                if (!t_stack.empty())
                {
                    t_stack.pop();
                }
            }
        }

        while ((!s_stack.empty()) && (!t_stack.empty()))
        {
            if (s_stack.top() != t_stack.top())
            {
                return false;
            }
            s_stack.pop();
            t_stack.pop();
        }

        if (!s_stack.empty() || !t_stack.empty())
        {
            return false;
        }
        return true;
    }
};

// O(1) memory
class SolutionTwo
{
public:
    bool backspaceCompare(string s, string t)
    {
        int k = processString(s);
        int p = processString(t);

        if (k != p)
            return false;

        for (int i = 0; i < k; i++)
        {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }

private:
    int processString(string &str)
    {
        int k = 0;
        for (char c : str)
        {
            if (c != '#')
            {
                str[k++] = c;
            }
            else if (k > 0)
            {
                k--;
            }
        }
        return k;
    }
};