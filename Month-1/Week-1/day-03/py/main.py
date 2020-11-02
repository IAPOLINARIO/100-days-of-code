
def count_vegetarian_skewers(grill):
    skewers = grill.replace('[', '').replace(']', '').split(', ')
    vegetarians = 0
    non_vegetarians = 0
    
    for skewer in skewers:
        if ('x' in skewer):
            non_vegetarians = non_vegetarians + 1
        else:
            vegetarians = vegetarians + 1
    
    return '[{}, {}]'.format(vegetarians, non_vegetarians)