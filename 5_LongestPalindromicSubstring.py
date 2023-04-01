class Solution:
    def longestPalindrome(self, s: str) -> str:
        longestPalindromeBegin = 0
        longestPalindromeLength = 1
        for i in range(0, len(s)):
            #compute largest palindrome centered at i OR pair(i, i+1)
            leftPointer = i-1
            rightPointer = i+1
            palindromeLength = 1
            while(leftPointer >= 0 and rightPointer < len(s) and s[leftPointer]==s[rightPointer]):
                leftPointer-=1
                rightPointer+=1
                palindromeLength+=2
            if(palindromeLength > longestPalindromeLength):
                longestPalindromeBegin = leftPointer + 1
                longestPalindromeLength = palindromeLength
            if(i>=1 and s[i]==s[i-1]):
                leftPointer2 = i-2
                rightPointer2 = i+1
                palindromeLength2 = 2
                while(leftPointer2 >= 0 and rightPointer2 < len(s) and s[leftPointer2]==s[rightPointer2]):
                    leftPointer2-=1
                    rightPointer2+=1
                    palindromeLength2+=2
                if(palindromeLength2 > longestPalindromeLength):
                    longestPalindromeBegin = leftPointer2 + 1
                    longestPalindromeLength = palindromeLength2
        answer = ""
        for i in range(longestPalindromeBegin, longestPalindromeBegin+longestPalindromeLength):
            answer += s[i]
        return answer
    