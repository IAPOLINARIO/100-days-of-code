import string


def combine_letters(digits):
    result = []
    if len(digits) == 0:
        return []

    result.append('')
    buttons = {
        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z']
    }
    
    i = 0
    while i < len(digits):
        aux = []
        button = buttons[digits[i]]
        j = 0
        while j < len(button):
            k = 0
            while k < len(result):
                aux.append(result[k] + button[j])
                k += 1
            j += 1
        result = aux
        i += 1

    result.sort()
    return result
