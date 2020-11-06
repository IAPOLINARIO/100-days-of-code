
def sort_array(first_array_str, second_array_str):
    arr = (list(filter((0).__ne__, eval(first_array_str))) + eval(second_array_str))
    arr.sort()
    return arr
