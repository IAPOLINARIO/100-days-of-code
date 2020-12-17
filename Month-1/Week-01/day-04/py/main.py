
def progress_days(days):
    days_arr = eval(days)
    progress_days_count = 0
    i = 0
    while i < len(days_arr):
        if (i > 0 and days_arr[i] > days_arr[i - 1]):
            progress_days_count += 1
        
        i += 1
    return progress_days_count
