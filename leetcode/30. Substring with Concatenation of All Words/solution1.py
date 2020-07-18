from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        
        set_of_words = Counter(words)
        
        result = []
        
        if len(words) == 0:
            return []
        
        if len(s) == 0:
            return []
        
        length = len(words[0])
        total_words = len(words)
        
        for i in range(len(s) - total_words * length + 1):
            set_of_words = Counter(words)
            
            words_to_check = total_words
            j = i
            
            occurred_words = set()
            
            continue_flag = False
            
            while words_to_check > 0:
                curr_word = s[j:j + length]
                
                if curr_word not in set_of_words or set_of_words[curr_word] == 0:
                    continue_flag = True
                    break
                
                
                set_of_words[curr_word] -= 1
                
                occurred_words.add(curr_word)
                words_to_check -= 1
                j += length
            
            if continue_flag:
                continue
            
            result.append(i)
            
        return result
