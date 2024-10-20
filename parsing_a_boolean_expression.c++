class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> operators; // Stack for operators |, &, !
        stack<vector<bool>> operands; // Stack for boolean values of inner expressions
        
        for (char ch : expression) {
            if (ch == 't' || ch == 'f') {
                // Push the boolean values to operands
                operands.top().push_back(ch == 't');
            } else if (ch == '|' || ch == '&' || ch == '!') {
                // Push the operator to the operators stack
                operators.push(ch);
                operands.push({}); // Start a new operand collection for this operator
            } else if (ch == '(') {
                // Start of a new inner expression (ignore, handled by stacks)
            } else if (ch == ')') {
                // Time to evaluate the expression when encountering closing ')'
                char op = operators.top();
                operators.pop();

                vector<bool> currentOperands = operands.top();
                operands.pop();
                
                bool result;
                if (op == '|') {
                    result = false;
                    for (bool val : currentOperands) {
                        result = result || val;
                    }
                } else if (op == '&') {
                    result = true;
                    for (bool val : currentOperands) {
                        result = result && val;
                    }
                } else if (op == '!') {
                    // Not operator only applies to a single boolean value
                    result = !currentOperands[0];
                }
                
                // After evaluating, push the result back as an operand for outer expressions
                if (!operands.empty()) {
                    operands.top().push_back(result);
                } else {
                    operands.push({result});
                }
            }
        }

        // The final result is the single value left on the operands stack
        return operands.top()[0];
    }
};
