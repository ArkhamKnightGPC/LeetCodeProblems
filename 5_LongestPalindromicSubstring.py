
class Solution:

    def extendPalindrome(self, s: str, leftPointer: int, rightPointer: int, oddPalindrome: bool) -> tuple:
        extensionCount = 1 if oddPalindrome else 2
        while(leftPointer >= 0 and rightPointer < len(s) and s[leftPointer]==s[rightPointer]):
                #we check to see if borders of palindrome can be extended
                leftPointer -= 1
                rightPointer += 1
                extensionCount += 2
        #return (begin, length) of palindrome found
        return (leftPointer + 1, extensionCount)

    def longestPalindrome(self, s: str) -> str:
        longestPalindromeBegin = 0
        longestPalindromeLength = 1

        for i in range(0, len(s)):
            #compute largest palindrome centered at i (odd length)
            (largestOddBegin, largestOddLength) = self.extendPalindrome(s, i-1, i+1, True)
            if(largestOddLength > longestPalindromeLength):
                longestPalindromeBegin = largestOddBegin
                longestPalindromeLength = largestOddLength
            #compute largest palindrome centered at pair i, i+1 (even length)
            if(i>=1 and s[i]==s[i-1]):
                (largestEvenBegin, largestEvenLength) = self.extendPalindrome(s, i-2, i+1, False)
                if(largestEvenLength > longestPalindromeLength):
                    longestPalindromeBegin = largestEvenBegin
                    longestPalindromeLength = largestEvenLength
        #now we build answer to return
        return s[longestPalindromeBegin:longestPalindromeBegin+longestPalindromeLength]
        