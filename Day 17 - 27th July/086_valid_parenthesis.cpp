bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> record;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '}'){
          if(record.empty() || record.top()!='{') return false;
          else record.pop();
      }
      else if (s[i] == ')'){
          if(record.empty() || record.top()!='(') return false;
          else record.pop();
      }
      else if (s[i] == ']'){
          if(record.empty() || record.top()!='[') return false;
          else record.pop();
      }
      else record.push(s[i]);
    }

    return record.empty();
}