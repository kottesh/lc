from typing import List

class Solution:
    def isValid(self, s: str) -> bool:
        store = []

        for chr in s:
            if chr in '([{':
                store.append(chr)
            else:
                if store:
                    curr = store.pop()
                    if curr == '(' and chr != ')':
                        return False 
                    elif curr == '{' and chr != '}':
                        return False 
                    elif curr == '[' and chr != ']':
                        return False 
                else:
                    return False
        
        return True if not store else False

run = Solution()
print(run.isValid('()'))