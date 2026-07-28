class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c in "([{":
                stack.append(c)
            elif stack == []:
                return False
            elif c == ")":
                if stack.pop() != "(":
                    return False
            elif c == "]":
                if stack.pop() != "[":
                    return False
            elif c == "}":
                if stack.pop() != "{":
                    return False
        if stack != []:
            return False
        return True