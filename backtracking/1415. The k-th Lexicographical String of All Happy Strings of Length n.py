class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        store = [] 
        def gen_strings(curr, last):
            if len(store) == k:
                return
            if len(curr) == n:
                store.append(curr)
                return

            for ch in ['a', 'b', 'c']:
                if ch != last:
                    gen_strings(curr + ch, ch)

        gen_strings("", "")
            
        return store[k - 1] if k <= len(store) else ""

if __name__ == "__main__":
    print(Solution().getHappyString(3, 9))
