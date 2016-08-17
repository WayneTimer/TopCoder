class grafixCorrupt:
    def selectWord(self, dictionary, candidate):
        max = 0
        ans = -1
        for x in range(len(dictionary)):
            t = 0
            s = dictionary[x]
            for i in range(len(s)):
                if s[i]==candidate[i]:
                    t+=1
            if t>max:
                max = t
                ans = x
        return ans
