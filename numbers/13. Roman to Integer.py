class Solution:
    val_map = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }

    def romanToInt(self, s: str) -> int:
        num = 0

        #for i in range(len(s)):
        #    if (i < len(s) - 1 and self.val_map[s[i]] < self.val_map[s[i+1]]):
        #        num -= self.val_map[s[i]]
        #    else:
        #        num += self.val_map[s[i]]
        i = 0
        while (i < len(s)):
            next = ''
            if i+1 != len(s):
                next = s[i+1]

            if s[i] == 'I' and next in ['V', 'X']:
                    num += self.val_map[next] - self.val_map[s[i]]
                    i += 2
            elif s[i] == 'X' and next in ['L', 'C']:
                    num += self.val_map[next] - self.val_map[s[i]]
                    i += 2
            elif s[i] == 'C' and next in ['D', 'M']:
                    num += self.val_map[next] - self.val_map[s[i]]
                    i += 2
            else:
                num += self.val_map[s[i]]
                i += 1
        return num
            
if __name__ == "__main__":
    s = Solution()
    print(s.romanToInt("MCMXCIV"))