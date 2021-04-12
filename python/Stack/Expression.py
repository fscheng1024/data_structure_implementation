class Expression:
    def __init__(self):
        #super().__init__()
        self.k_elements_of_bracket = 4
        self.__left_brackets = ['(', '{', '<', '[']
        self.__right_brackets = [')', '}', '>', ']']
    
    def __is_left_bracket(self, ch):
        return ch in self.__left_brackets
    
    def __is_right_bracket(self, ch):
        return ch in self.__right_brackets
    
    def __is_bracket_matched(self, left, right):
        return self.__left_brackets.index(left) == self.__right_brackets.index(right)
    
    def _is_balanced(self, string):
        stack = []
        for ch in string:
            if self.__is_left_bracket(ch):
                stack.append(ch)
                
            elif self.__is_right_bracket(ch):
                if len(stack) == 0:
                    return False
                
                top = stack.pop(-1)
                if not self.__is_bracket_matched(top, ch):
                    return False
                
        return len(stack) == 0
                
                
if __name__ == '__main__':
    exp = Expression()

    string = "()]"
    print(exp._is_balanced(string))
    