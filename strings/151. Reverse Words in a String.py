class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()[::-1]
        return " ".join(words)



if __name__ == "__main__":
    print(Solution().reverseWords("a good   example"))